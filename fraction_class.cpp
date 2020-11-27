#include <iostream>
#include <cmath>
#include "fraction_class.h"

using namespace std;

// constructor with parameters
Fraction::Fraction(int num, int den) {
    if (den != 0) {
        denominator = den / ReductionOfFraction(num, den);
    } else {
        //cout << "Sorry, the denominator can't be 0. But don't worry because I changed it to 1." << endl;
        den = 1;
        denominator = den;
    }
    numerator = num / ReductionOfFraction(num, den);
}
// copy constructor
Fraction::Fraction (const Fraction &frac) {
numerator = frac.numerator;
denominator = frac.denominator;
}

int Fraction::ReductionOfFraction(int &n, int &d) {
    int n1 = abs(n);
    int d1 = abs(d);
    if (n == 0) {
        return 1;
    }
    while (n1 != d1) {
        if (n1 > d1) {
            n1 = n1 - d1;
        } else {
            d1 = d1 - n1;
        }
    }
    return n1;
}

int Fraction::CommonDenominator(int &d1, int &d2) {
    int CD = d1 * d2 / ReductionOfFraction(d1, d2);
    return CD;
}

int Fraction::GetNumerator(){
    return numerator;
}

int Fraction::GetDenominator() {
    return denominator;
}

Fraction Fraction::Sum(Fraction &frac){
    int CommonFactor1 = CommonDenominator(frac.denominator, denominator) / denominator;
    int CommonFactor2 = CommonDenominator(frac.denominator, denominator) / frac.denominator;
    int num1 = CommonFactor1 * numerator + CommonFactor2 * frac.numerator;
    int den = CommonDenominator(frac.denominator, denominator);
    int num = num1 / ReductionOfFraction(num1, den);
    den = den / ReductionOfFraction(num1, den);
    Fraction sum(num, den);
    return sum;
}

Fraction Fraction::Multiplication(Fraction &frac) {
    int num1 = numerator * frac.numerator ;
    int den1 = denominator * frac.denominator;
    int num = num1 / ReductionOfFraction(num1, den1);
    int den = den1 / ReductionOfFraction(num1, den1);
    Fraction mult(num, den);
    return mult;
}

Fraction Fraction::Division(Fraction &frac) {
    if (frac.numerator == 0) {
        cout << "Use something else. This fraction won't do." << endl;
        return frac;
    }
    int num1 = numerator * frac.denominator;
    int den1 = denominator * frac.numerator;
    int num = num1 / ReductionOfFraction(num1, den1);
    int den = den1 / ReductionOfFraction(num1, den1);
    Fraction quotient(num, den);
    return quotient;
}

void Fraction::PrintFraction() {
    if (numerator * denominator > 0) {
        cout << abs(numerator) << "/" << abs(denominator);
    }
    if (numerator * denominator < 0) {
        cout << "-" <<  abs(numerator) << "/" << abs(denominator);
    }
}

;//
// Created by Zver on 31.10.2020.
//

