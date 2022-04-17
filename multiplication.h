#ifndef MATRIX_MULTIPLICATION__MULTIPLICATION_H_
#define MATRIX_MULTIPLICATION__MULTIPLICATION_H_

#include <mutex>
#include <vector>

using namespace std;

mutex mtx;

void enlarge(int start, int finish, int size, vector<vector<double>> &C) {
  for (int i = start; i < finish; ++i) {
    C[i].resize(size);
  }
}

void multiply1(int iteration, int threads, vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C) {
  unique_lock<mutex> lock(mtx);
  int Astart = iteration * A.size() / threads;
  int Afinish = Astart + A.size() / threads;
  if (iteration == threads - 1) {
    Afinish += A.size() % threads;
  }
  for (int k = 0; k < threads; ++k) {
    int Bstart = k * B[0].size() / threads;
    int Bfinish = Bstart + B[0].size() / threads;
    if (iteration != threads - 1) {
      Bfinish += B[0].size() % threads;
    }
    for (int i = Astart; i < Afinish; ++i) {
      for (int j = Bstart; j < Bfinish; ++j) {
        double elem = 0;
        for (int f = 0; f < B.size(); ++f) {
          elem += A[i][f] * B[f][j];
        }
        C[i][j] = elem;
      }
    }
  }
}

vector<vector<double>> multiply2(int iteration, int threads, vector<vector<double>> &A, vector<vector<double>> &B) {
  unique_lock<mutex> lock(mtx);
  vector<vector<double>> matrix(A.size());
  int kstart = iteration * B.size() / threads;
  int kfinish = kstart + B.size() / threads;
  if (iteration == threads - 1) {
    kfinish += B.size() % threads;
  }
  for (int i = 0; i < A.size(); ++i) {
    matrix[i].resize(B[0].size());
    for (int j = 0; j < B[0].size(); ++j) {
      double elem = 0;
      for (int f = kstart; f < kfinish; ++f) {
        elem += A[i][f] * B[f][j];
      }
      matrix[i][j] = elem;
    }
  }
  return matrix;
}

void multiply3(int index_i, int index_j, int threads, vector<vector<double>> &A, vector<vector<double>> &B, vector<vector<double>> &C) {
  unique_lock<mutex> lock(mtx);
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
      C[i][j] = element[i - AIstart][j - BJstart];
    }
  }
}


#endif //MATRIX_MULTIPLICATION__MULTIPLICATION_H_
