#include <gtest/gtest.h>
#include "fraction_class.h"

using namespace std;

TEST (frac, NumAndDen) {
    Fraction frac(1, 2);
    EXPECT_EQ(1, frac.GetNumerator());
    EXPECT_EQ(2, frac.GetDenominator());
}

TEST(frac, One) {
    Fraction frac1(7, 7);
    EXPECT_EQ(1,frac1.GetNumerator());
    EXPECT_EQ(1,frac1.GetDenominator());
}

TEST(frac, Zero) {
    Fraction frac1(0, 1);
    EXPECT_EQ(0,frac1.GetNumerator());
    EXPECT_EQ(1,frac1.GetDenominator());
}

TEST(frac, ZeroInDen) {
    Fraction frac1(1, 0);
    int m = frac1.GetDenominator();
    EXPECT_EQ(1,m);
}

TEST(operations, Sum) {
    Fraction fr1(1, 2);
    Fraction fr2(1, 3);
    Fraction fr3(fr1.Sum(fr2));
    EXPECT_EQ(5, fr3.GetNumerator());
}

TEST(operations, SumWithZero) {
    Fraction fr1(1, 2);
    Fraction fr2(0, 6);
    Fraction fr3(fr1.Sum(fr2));
    EXPECT_EQ(1, fr3.GetNumerator());
    EXPECT_EQ(2, fr3.GetDenominator());
}

TEST(operations, SumWithNegativeNumerator) {
    Fraction fr1(1, 4);
    Fraction fr2(-1, 2);
    Fraction fr3(fr1.Sum(fr2));
    EXPECT_EQ(-1, fr3.GetNumerator());
    EXPECT_EQ(4, fr3.GetDenominator());
}

TEST(operations, SumWithNegativeDenominator) {
    Fraction fr1(1, 4);
    Fraction fr2(1, -2);
    Fraction fr3(fr1.Sum(fr2));
    EXPECT_EQ(1, fr3.GetNumerator());
    EXPECT_EQ(-4, fr3.GetDenominator());
}

TEST(operations, SumWithNegatives) {
    Fraction fr1(-1, 4);
    Fraction fr2(-1, 2);
    Fraction fr3(fr1.Sum(fr2));
    EXPECT_EQ(-3, fr3.GetNumerator());
    EXPECT_EQ(4, fr3.GetDenominator());
}

TEST(operations, Multiplication) {
    Fraction fr1(1, 2);
    Fraction fr2(6, 7);
    Fraction fr3(fr1.Multiplication(fr2));
    EXPECT_EQ(3, fr3.GetNumerator());
    EXPECT_EQ(7, fr3.GetDenominator());
}

TEST(operations, MultiplicationWithNegativeNumAndDen) {
    Fraction fr1(-1, 2);
    Fraction fr2(6, -7);
    Fraction fr3(fr1.Multiplication(fr2));
    EXPECT_EQ(-3, fr3.GetNumerator());
    EXPECT_EQ(-7, fr3.GetDenominator());
}

TEST(operations, MultiplicationWithNegativeNums) {
    Fraction fr1(-1, 2);
    Fraction fr2(-6, 7);
    Fraction fr3(fr1.Multiplication(fr2));
    EXPECT_EQ(3, fr3.GetNumerator());
    EXPECT_EQ(7, fr3.GetDenominator());
}

TEST(operations, MultiplicationWithNegativeDens) {
    Fraction fr1(1, -2);
    Fraction fr2(6, -7);
    Fraction fr3(fr1.Multiplication(fr2));
    EXPECT_EQ(3, fr3.GetNumerator());
    EXPECT_EQ(7, fr3.GetDenominator());
}

TEST(operations, MultiplicationWithOne) {
    Fraction fr1(1, 2);
    Fraction fr2(7, 7);
    Fraction fr3(fr1.Multiplication(fr2));
    EXPECT_EQ(1, fr3.GetNumerator());
    EXPECT_EQ(2, fr3.GetDenominator());
}

TEST(operations, MultiplicationWithZero) {
    Fraction fr1(1, 2);
    Fraction fr2(0, 7);
    Fraction fr3(fr1.Multiplication(fr2));
    EXPECT_EQ(0, fr3.GetNumerator());
    EXPECT_EQ(14, fr3.GetDenominator());
}

TEST(operations, Division) {
    Fraction fr1(1, 2);
    Fraction fr2(1, 3);
    Fraction fr3(fr1.Division(fr2));
    EXPECT_EQ(3, fr3.GetNumerator());
    EXPECT_EQ(2, fr3.GetDenominator());
}

TEST(operations, DivisionWithNegatives) {
    Fraction fr1(-1, 2);
    Fraction fr2(1, 3);
    Fraction fr3(fr1.Division(fr2));
    EXPECT_EQ(-3, fr3.GetNumerator());
    EXPECT_EQ(2, fr3.GetDenominator());
}

TEST(operations, DivisionWithNegativeNums) {
    Fraction fr1(-1, 2);
    Fraction fr2(-1, 3);
    Fraction fr3(fr1.Division(fr2));
    EXPECT_EQ(-3, fr3.GetNumerator());
    EXPECT_EQ(-2, fr3.GetDenominator());
}

TEST(operations, DivisionWithNegativeDens) {
    Fraction fr1(1, -2);
    Fraction fr2(1, -3);
    Fraction fr3(fr1.Division(fr2));
    EXPECT_EQ(-3, fr3.GetNumerator());
    EXPECT_EQ(-2, fr3.GetDenominator());
}

TEST(operations, DivisionWithNegativeNumAndDen) {
    Fraction fr1(-1, 2);
    Fraction fr2(1, -3);
    Fraction fr3(fr1.Division(fr2));
    EXPECT_EQ(3, fr3.GetNumerator());
    EXPECT_EQ(2, fr3.GetDenominator());
}

TEST(operations, DivisionWithOne) {
    Fraction fr1(1, 2);
    Fraction fr2(3, 3);
    Fraction fr3(fr1.Division(fr2));
    EXPECT_EQ(1, fr3.GetNumerator());
    EXPECT_EQ(2, fr3.GetDenominator());
}

TEST(operations, DivisionWithZero) {
    Fraction fr1(1, 2);
    Fraction fr2(0, 3);
    Fraction fr3(fr1.Division(fr2));
    EXPECT_EQ(0, fr3.GetNumerator());
    EXPECT_EQ(3, fr3.GetDenominator());
}