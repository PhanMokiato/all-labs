#include <iostream>
#include <map>
#include <string>

#include "Iterator_For_Array.h"
#include "Iterator_For_Map.h"
#include "Visitor_For_Figures.h"

int main() {
  // First task
  int *Array = new int[5];
  std::cout.setf(std::ios::boolalpha);
  Array[0] = 1;
  Array[1] = 2;
  Array[2] = 3;
  Array[3] = 4;
  Array[4] = 5;
  ItForArray<int> It1(Array, 5);
  std::cout << It1.Current() << std::endl;
  It1.Next();
  std::cout << It1.Next() << std::endl;
  std::cout << It1.First() << " " << It1.IsDone() << std::endl;
  It1.Next();
  It1.Next();
  std::cout << It1.Current() << " " << It1.IsDone() << " " << It1.Next() << std::endl;
  // Second task
  std::map<std::string, std::string> MyMap{{"all", "ball"}, {"pple", "apple"},
                                           {"aven", "raven"}, {"ndroid", "android"}};
  ItForMap It2(&MyMap);
  std::cout << It2.Current() << std::endl;
  std::cout << It2.Next()  << std::endl;
  It2.Next();
  std::cout << It2.Current() << " " << It2.First() << " " << It2.IsDone() << std::endl;
  It2.Next();
  std::cout << It2.Current()  << " " << It2.Next() << " " << It2.IsDone() << std::endl;
  // Third task
  Vector vec(1, 5, 3, 2);
  Circle circ(3, 4, 6);
  Square sq(1, 5, 4, 2);
  ParallelTransfer PT(3, 1);
  Scaling scal(2);
  Reflection ref1("x");
  Reflection ref2("y");
//  vec.AcceptVisitor(PT);
//  circ.AcceptVisitor(PT);
//  sq.AcceptVisitor(PT);
//  vec.AcceptVisitor(scal);
//  circ.AcceptVisitor(scal);
//  sq.AcceptVisitor(scal);
  vec.AcceptVisitor(ref2);
  circ.AcceptVisitor(ref2);
  sq.AcceptVisitor(ref2);
  std::cout << vec._x1 << vec._y1 << vec._x2 << vec._y2 << std::endl;
  std::cout << sq._x1 << sq._y1 << sq._x2 << sq._y2 << std::endl;
  std::cout << circ._x1 << circ._y1 << circ._radius << std::endl;
  delete[] Array;
  return 0;
}
