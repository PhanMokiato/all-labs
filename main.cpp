#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct MultiOne {
  int _i;
  int _threads;
  vector<vector<double>> *_A;
  vector<vector<double>> *_B;
  vector<vector<double>> *_C;
  HANDLE _mutex;
};

void multiply3(int index_i, int index_j, int threads, vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C, HANDLE mutex);

DWORD WINAPI mult1(void* _data) {
  MultiOne * data = static_cast<MultiOne*> (_data);
  int i = data->_i;
  int threads = data->_threads;
  vector<vector<double>>* A = data->_A;
  vector<vector<double>>* B = data->_B;
  vector<vector<double>>* C = data->_C;
  HANDLE mutex = data->_mutex;
  for (int j = 0; j < threads; ++j) {
    multiply3(i, j, threads, *A, *B, *C, mutex);
  }
  delete data;
  ExitThread(0);
}

int main() {
  fstream in("input.txt");
  int n, k, m;
  in >> n >> k >> m;
  CONST HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);
  vector<vector<double>> A(n);
  vector<vector<double>> B(k);
  int threads = 0;
  in >> threads;
  HANDLE* hThreads1 = new HANDLE[threads];
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


  vector<vector<double>> C(n);
  auto start = chrono::high_resolution_clock::now();
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
    MultiOne* data = new MultiOne();
    data->_i = i;
    data->_threads = threads;
    data->_A = &A;
    data->_B = &B;
    data->_C = &C1;
    data->_mutex = hMutex;
    hThreads1[i] = CreateThread(nullptr, 0, &mult1, (void*)data, 0, nullptr);
  }
  WaitForMultipleObjects(threads, hThreads1, TRUE, INFINITE);
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

  for (int i = 0; i < threads; ++i) {
    CloseHandle(hThreads1[i]);
  }
  CloseHandle(hMutex);
  delete [] hThreads1;
  return 0;
}


void multiply3(int index_i, int index_j, int threads, vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C, HANDLE mutex) {
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
      WaitForSingleObject(mutex, INFINITE);
      C[i][j] = element[i - AIstart][j - BJstart];
      ReleaseMutex(mutex);
    }
  }
}
