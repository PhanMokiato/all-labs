#include <chrono>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

struct MultiOne {
  int _i;
  int _threads;
  vector<vector<double>> *_A;
  vector<vector<double>> *_B;
  vector<vector<double>> *_C;
  pthread_mutex_t _mtx;
};

void multiply(int index_i, int index_j, int threads, vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C, pthread_mutex_t mutex);

void *do_multiplication(void *_data) {
  auto * data = (MultiOne *)_data;
  int i = data->_i;
  int threads = data->_threads;
  vector<vector<double>>* A = data->_A;
  vector<vector<double>>* B = data->_B;
  vector<vector<double>>* C = data->_C;
  pthread_mutex_t mtx = data->_mtx;
  for (int j = 0; j < threads; ++j) {
    multiply(i, j, threads, *A, *B, *C, mtx);
  }
  delete data;
  pthread_exit(NULL);
}

int main() {
  fstream in("input.txt");
  int n, k, m;
  in >> n >> k >> m;
  vector<vector<double>> A(n);
  vector<vector<double>> B(k);
  int threads;
  in >> threads;
  auto* the_threads = new pthread_t[threads];
  auto mtx = PTHREAD_MUTEX_INITIALIZER;
  pthread_attr_t attr;
  void *status;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  for (int i = 0; i < n + k; ++i) {
    if (i < n) {
      for (int j = 0; j < k; ++j) {
        double element;
        in >> element;
        A[i].push_back(element);
      }
    } else {
      for (int j = 0; j < m; ++j) {
        double element;
        in >> element;
        B[i-n].push_back(element);
      }
    }
  }

  auto start = chrono::high_resolution_clock::now();
  vector<vector<double>> C(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      double elem = 0;
      for (int f = 0; f < k; ++f) {
        elem += A[i][f] * B[f][j];
      }
      C[i].push_back(elem);
      cout << C[i][j] << "\t ";
    }
    cout << endl;
  }
  auto finish = chrono::high_resolution_clock::now();
  chrono::duration<double> period = finish - start;
  cout << period.count() << " seconds" << endl;

  vector<vector<double>> C1(n, vector<double>(m));
  start = chrono::high_resolution_clock::now();
  for (int i = 0; i < threads; ++i) {
    auto* data = new MultiOne();
    data->_i = i;
    data->_threads = threads;
    data->_A = &A;
    data->_B = &B;
    data->_C = &C1;
    pthread_mutex_init(&mtx, NULL);
    data->_mtx = mtx;
    pthread_create(&the_threads[i], &attr, do_multiplication, (void*)data);
    pthread_mutex_destroy(&mtx);
  }
  pthread_attr_destroy(&attr);
  for (int i = 0; i < threads; ++i) {
    pthread_join(the_threads[i], &status);
  }
  finish = chrono::high_resolution_clock::now();
  period = finish - start;

  cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << C1[i][j] << "\t ";
    }
    cout << endl;
  }
  cout << period.count() << " seconds";
  delete [] the_threads;
  pthread_exit(NULL);
}

void multiply(int index_i, int index_j, int threads, vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C, pthread_mutex_t mutex) {
  int AIstart = index_i * A.size() / threads;
  int AIfinish = AIstart + A.size() / threads;
  int BJstart = index_j * B[0].size() / threads;
  int BJfinish = BJstart + B[0].size() / threads;
  int n = A.size() / threads;
  int m = B[0].size() / threads;
  if (index_i == threads - 1) {
    AIfinish += A.size() % threads;
    n += A.size() % threads;
  }
  if (index_j == threads - 1) {
    BJfinish += B[0].size() % threads;
    m += B[0].size() % threads;
  }
  vector<vector<double>> element(n);
  for (int k = 0; k < threads; ++k) {
    for (int i = AIstart; i < AIfinish; ++i) {
      for (int j = BJstart; j < BJfinish; ++j) {
        double elem = 0;
        int kstart = k * B.size() / threads;
        int kfinish = kstart + B.size() / threads;
        if (k == threads - 1) {
          kfinish += B.size() % threads;
        }
        for (int f = kstart; f < kfinish; ++f) {
          elem += A[i][f] * B[f][j];
        }
        if (k == 0 && j == BJstart) {
          element[i - AIstart].resize(m);
        }
        element[i - AIstart][j - BJstart] += elem;
      }
    }
  }
  for (int i = AIstart; i < AIfinish; ++i) {
    for (int j = BJstart; j < BJfinish; ++j) {
      pthread_mutex_lock(&mutex);
      C[i][j] = element[i - AIstart][j - BJstart];
      pthread_mutex_unlock(&mutex);
    }
  }
}

