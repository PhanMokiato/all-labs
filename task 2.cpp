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
    int f = n + 1; // i just needed to give it a number that doesn't equals any arrays elements
    int l;
    double pr = 1;
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
        if (array[i] < 0) {
            f = i;
            break;
        } else {
            continue;
        }
    }
    if (f == n + 1) {
        cout << endl << "Sorry, there aren't any negative numbers(";
    }
        for (i = 0; i < n; ++i) {
        if (array[i] < 0) {
            l = i;
        }
        }
    if (l == f) {
        cout << endl << "Sorry, there is only one negative number";
    }
    for (i = f + 1; i < l; ++i) {
        pr = pr * array[i];
    }
cout << endl;
    cout << pr;
    delete[]array;
    return 0;
}
