#include "pch.h"
#include "Header.h"
#include "Number.h"

Number Vector::countRo() {
    return Number(sqrt(pow(_x.getValue(), 2) + pow(_y.getValue(), 2)));
}
Number Vector::countFi() {
    return Number(atan(_y.getValue() / _x.getValue()));
}
void Vector::add(Vector v) {
    this->_x = this->_x + v._x;
    this->_y = this->_y + v._y;
}