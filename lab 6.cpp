#include <iostream>
#include "fraction_class.h"

using namespace std;

int main() {
    cout << "Please, enter both your numerator and denominator:" << endl;
    int num, den;
    cin >> num >> den;
    Fraction first(num, den);
    cout << "Ta-Dam) There is your fraction:" << endl;
    cout << "So, the numerator of your fraction is " << first.GetNumerator() << " and the denominator is " << first.GetDenominator() << "." << endl;
    first.PrintFraction(); cout << endl;

    Fraction second(1, 6);
    cout << "There you can see the sum of your fraction and 1/6:" << endl;
    first.Sum(second).PrintFraction(); cout << endl;

    cout << "There you can see the product of your fraction and 1/6:" << endl;
    first.Multiplication(second).PrintFraction();  cout << endl;

    cout << "There you can see the quotient of your fraction and 1/6:" << endl;
    first.Division(second).PrintFraction();

 //  Fraction third(two);
 //  Fraction sum(two.Sum(first)); cout << endl; запускаю программу и это работает, но СLion пишет ошибку в синтаксисе. Почему?
 //  sum.PrintFraction();
    return 0;
}
