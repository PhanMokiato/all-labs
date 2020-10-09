#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
int main() {
    cout << "Please, enter the number of the array's elements(no more than 100):" << endl;
    int n;
    int k;
    cin >> n;
    if (n > 100) {
        cout << "That number is unacceptable";
        return 0;
    }
    double *array = new double[n];
    cout << "If you want to put elements on your own, write '1', otherwise - '2':" << endl;
    cin >> k;
    int i;
    if (k == 1) {
        cout << "Please, enter your array's elements:" << endl;
        for (i = 0; i < n; ++i) {
            cin >> array[i];
        }
    } else {
        cout << "Where do you want your numbers? Write your boundaries, please:" << endl;
        double start; int finish;
        cin >> start >> finish; cout << endl;
        srand(time(NULL));
        for (i = 0; i < n; ++i) {
            array[i] = rand() % finish + start - finish;
            cout << array[i] << " ";
        }

    }
    cout << endl;
    for (i = 0; i < n; ++i) {
        if (abs(array[i]) < 1) {
            array[i] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (array[i] == 0) {
            for (int j = i; j < n - 1; ++j) {
                array[j] = array[j + 1];
                array[n - 1] = 0;
            }
        }
        cout  << array[i] << " ";
    }

    delete[]array;
    return 0;
}