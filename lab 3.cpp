#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int get_el(int **&mat, int i, int j) {
    if ((i + j) % 2 == 1) {
        return 1;
    } else {
        return mat[i][j];
    }
}

int main() {
    cout <<"Please, enter the measurement of your square matrix(no more than 10):" << endl;
    int n;
    cin >> n; cout << endl;
    if (n > 10) {
        cout << "This measurement is unacceptable. Well... everybody makes mistakes sometimes, right? ";
        return 0;
    }
    int **mat = new int*[n];
    int i, j, k, The_sum = 0, pr = 1, pr_max = 1;
    int prosto_number;
    for (i = 0; i < n; ++i) { // матрица
        mat[i] = new int[n];
    }
    srand(time(NULL));
    for (i = 0; i < n; ++i) { // элементы матрицы
        for (j = 0; j < n; ++j) {
            mat[j][i] = rand() % 10;
            }
        }
    for (i = 0; i < n; ++i) { // вывод матрицы
        for (j = 0; j < n; ++j) {
            cout << get_el(mat, i, j) << "  ";
        }
        cout << endl;
    }
    for (i = 0; i < n; ++i) { // вычисление суммы
        for (j = 0; j < n; ++j) {
            if (get_el(mat, i, j) != 0) {
                prosto_number = 1;
            } else {
                prosto_number = 0;
                break;
            }
        }
        if (prosto_number == 1) {
            for (j = 0; j < n; ++j){
                The_sum = The_sum + get_el(mat, i, j);
            }
        }
        }
 cout << "The sum of the necessary elements is " <<The_sum << "." << endl;
for (i = 1, k = 1; i < n - 1; ++i, ++k) { // алгоритм с умножением
    for (j = 0; j < n - k; ++i, ++j) {
        pr = pr * get_el(mat, i, j);
    }
    i = k;
 if (pr > pr_max) {
     pr_max = pr;
     pr = 1;
 } else {
     pr = 1;
     continue;
 }
}
    for (j = 1, k = 1; j < n - 1; ++j, ++k) { // алгоритм с умножением
        for (i = 0; i < n - k; ++i, ++j) {
            pr = pr * get_el(mat, i, j);
        }
        j = k;
        if (pr > pr_max) {
            pr_max = pr;
            pr = 1;
        } else {
            pr = 1;
            continue;
        }
    }
cout << "The maximum product is " << pr_max << "." << endl;
    for(i = 0; i < n; ++i) {
        delete mat[i];
    }
    delete [] mat;

    return 0;
}
