#pragma once
#include "Number.h"
#include <cmath>

#ifdef VECTOR_EXPORTS
#define VECTOR_API __declspec(dllexport)
#else
#define VECTOR_API __declspec(dllimport)
#endif

using namespace MyNumber;

class VECTOR_API Vector {
private:
    Number _x;
    Number _y;
public:
    Vector(Number x, Number y) : _x(x), _y(y) {};
    Number countRo();
    Number countFi();
    void add(Vector v);
};

const Vector Zero(zero, zero);
const Vector One(one, one);
