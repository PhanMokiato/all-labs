#include <fstream>
#include <iostream>
#include <thread>
#include <vector>

#include "multiplication.h"

using namespace std;

int main() {
  fstream in("input.txt");
  int n, k, m;
  in >> n >> k >> m;
  vector<vector<double>> A(n);
  vector<vector<double>> B(k);
  int threads;
  in >> threads;
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

  vector<vector<double>> C1(n);
  for (int i = 0; i < n; ++i) {
    C1[i].resize(m);
  }

  start = chrono::high_resolution_clock::now();
  thread* current;
  for (int i = 0; i < threads; ++i) {
      current = new thread([&](){
        int start = i * (n / threads);
        int finish = start + n / threads;
        if (i == threads - 1) {
          finish += n % threads;
        }
        multiply1(i, threads, A, B, C1);
      });
      current->join();
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
  cout << period.count() << " seconds" << endl;

  vector<vector<double>> C2(n);
  for (int i = 0; i < n; ++i) {
    C2[i].resize(m);
  }

  start = chrono::high_resolution_clock::now();
  vector<vector<vector<double>>> matrices;
  for (int i = 0; i < threads; ++i) {
    current = new thread([&](){
      vector<vector<double>> matrix = multiply2(i, threads, A, B);
      matrices.push_back(matrix);
    });
    current->join();
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (auto elem : matrices) {
        C2[i][j] += elem[i][j];
      }
    }
  }
  finish = chrono::high_resolution_clock::now();
  period = finish - start;

  cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << C2[i][j] << "\t ";
    }
    cout << endl;
  }
  cout << period.count() << " seconds" << endl;

  vector<vector<double>> C3(n);
  for (int i = 0; i < n; ++i) {
    C3[i].resize(m);
  }

  start = chrono::high_resolution_clock::now();
  for (int i = 0; i < threads; ++i) {
    current = new thread([&](){
      int start = i * (n / threads);
      int finish = start + n / threads;
      if (i == threads - 1) {
        finish += n % threads;
      }
      enlarge(start, finish, m, C3);
      for (int j = 0; j < threads; ++j) {
        multiply3(i, j, threads, A, B, C3);
      }
    });
    current->join();
  }
  finish = chrono::high_resolution_clock::now();
  period = finish - start;

  cout << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << C3[i][j] << "\t ";
    }
    cout << endl;
  }
  cout << period.count() << " seconds";
  return 0;
}
