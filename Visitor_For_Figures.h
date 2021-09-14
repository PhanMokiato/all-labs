//
// Created by Zver on 14.09.2021.
//

#ifndef PATTERNS___LAB_1__VISITOR_FOR_FIGURES_H_
#define PATTERNS___LAB_1__VISITOR_FOR_FIGURES_H_

#include "cmath"
#include <string>

class Figure;
class Vector;
class Circle;
class Square;

class Visitor {
 public:
  virtual void Visit(Vector &vector) = 0;
  virtual void Visit(Circle &circle) = 0;
  virtual void Visit(Square &square) = 0;
};

class Figure{
 public:
  int _x1;
  int _y1;
  Figure(int x1, int y1) : _x1(x1), _y1(y1) {}
  virtual void AcceptVisitor(Visitor &V) = 0;
};

class Vector : public Figure {
 public:
  int _x2;
  int _y2;
  Vector(int x1, int y1, int x2, int y2) : Figure(x1, y1), _x2(x2), _y2(y2) {}
  void AcceptVisitor(Visitor &V) override {
    V.Visit(*this);
  }
};

class Circle : public Figure {
 public:
  int _radius;
  Circle(int x1, int y1, int radius) : Figure(x1, y1), _radius(radius) {}
  void AcceptVisitor(Visitor &V) override {
    V.Visit(*this);
  }
};

class Square : public Figure {
 public:
  int _x2;
  int _y2;
  Square(int x1, int y1, int x2, int y2) : Figure(x1, y1), _x2(x2), _y2(y2) {}
  void AcceptVisitor(Visitor &V) override {
    V.Visit(*this);
  }
};


class ParallelTransfer : public Visitor {
 public:
  int _new_x;
  int _new_y;
  ParallelTransfer(int x, int y) : _new_x(x), _new_y(y) {}
  void Visit(Vector &vector) override {
    int move_x = _new_x - vector._x1;
    int move_y = _new_y - vector._y1;
    vector._x1 = _new_x;
    vector._y1 = _new_y;
    vector._x2 += move_x;
    vector._y2 += move_y;
  }
  void Visit(Circle &circle) override {
    circle._x1 = _new_x;
    circle._y1 = _new_y;
  }
  void Visit(Square &square) override {
    int move_x = _new_x - square._x1;
    int move_y = _new_y - square._y1;
    square._x1 = _new_x;
    square._y1 = _new_y;
    square._x2 += move_x;
    square._y2 += move_y;
  }
};

class Scaling : public Visitor {
 public:
  int _factor;
  Scaling(int factor) : _factor(factor) {}
  void Visit(Vector &vector) override {
    int projection_x = (vector._x2 - vector._x1) * _factor;
    int projection_y = (vector._y2 - vector._y1) * _factor;
    vector._x2 = projection_x + vector._x1 ;
    vector._y2 = projection_y + vector._y1;
  }
  void Visit(Circle &circle) override {
    circle._radius *= _factor;
  }
  void Visit(Square &square) override {
    int projection_x = (square._x2 - square._x1) * _factor;
    int projection_y = (square._y2 - square._y1) * _factor;
    square._x2 = projection_x + square._x1;
    square._y2 += projection_y + square._y1;
  }
};

  class Reflection : public Visitor {
   public:
    std::string _axis;
    Reflection(std::string axis) {
      if (axis == "x" || axis == "y") {
        _axis = axis;
      }
    }
    void Visit(Vector &vector) override {
      if (_axis == "x") {
        vector._y1 *= -1;
        vector._y2 *= -1;
      }
      if (_axis == "y") {
        vector._x1 *= -1;
        vector._x2 *= -1;
      }
    }
    void Visit(Circle &circle) override {
      if (_axis == "x") {
        circle._y1 *= -1;
      }
      if (_axis == "y") {
        circle._x1 *= -1;
      }
    }
    void Visit(Square &square) override {
      if (_axis == "x") {
        square._y1 *= -1;
        square._y2 *= -1;
      }
      if (_axis == "y") {
        square._x1 *= -1;
        square._x2 *= -1;
      }
    }
  };



#endif //PATTERNS___LAB_1__VISITOR_FOR_FIGURES_H_
