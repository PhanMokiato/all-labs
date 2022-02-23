#pragma once

namespace MyNumber {
    class Number {
    private:
        double _num;
    public:
        Number(const double &num) : _num(num) {}
        Number operator+(Number num1);
        Number operator-(Number num1);
        Number operator*(Number num1);
        Number operator/(Number num1);
        double getValue();
    };
    const Number one(1.0);
    const Number zero(0.0);
    inline Number createNumber(double num) {
        return Number(num);
    }
}
