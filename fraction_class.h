//
// Created by Zver on 31.10.2020.
//
#pragma once
#ifndef LAB_6_FRACTION_CLASS_H
#define LAB_6_FRACTION_CLASS_H

class Fraction {
private:
    int numerator;
    int denominator;

// constructor by default
    Fraction() {
        int numerator = 0;
        int denominator = 1;
    }

public:
    Fraction(int , int);
    Fraction (const Fraction &);
    int ReductionOfFraction(int &, int &);
    int CommonDenominator(int &, int &);
    int GetNumerator();
    int GetDenominator();
    Fraction Sum(Fraction &);
    Fraction Multiplication(Fraction &);
    Fraction Division(Fraction &);
    void PrintFraction();
};

#endif //LAB_6_FRACTION_CLASS_H
