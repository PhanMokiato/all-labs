#include "Number.h"

namespace MyNumber {
    Number Number::operator+(Number num1) {
        return Number(this->_num + num1._num);
    }
    Number Number::operator-(Number num1) {
        return Number(this->_num - num1._num);
    }
    Number Number::operator*(Number num1) {
        return Number(this->_num * num1._num);
    }
    Number Number::operator/(Number num1) {
        return Number(this->_num / num1._num);
    }
    double Number::getValue() {
        return _num;
    }
}