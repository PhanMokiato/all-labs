#include <iostream>
#include <cstdlib>
#include <ctime>
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
    double sum = 0;
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
    for (i = 0; i < n; ++i) {
        if ((i % 2) == 1) {
            sum = sum + array[i];
        }
    }
    cout << endl << sum;
    delete[]array;
    return 0;
}
