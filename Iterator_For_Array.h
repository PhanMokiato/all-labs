//
// Created by Zver on 07.09.2021.
//

#ifndef PATTERNS___LAB_1_CMAKE_BUILD_DEBUG_ITERATOR_FOR_ARRAY_H_
#define PATTERNS___LAB_1_CMAKE_BUILD_DEBUG_ITERATOR_FOR_ARRAY_H_

template <class T>
class ItForArray {
 private:
  T *_array;
  int _end;
  int _current;
 public:
  ItForArray(T *arr, int size) {
    _array = arr;
    _end = size - 1;
    _current = 0;
  }
  T First() {
    return _array[0];
  }
  T Current(){
    return _array[_current];
  }
  T Next(){
    if (_current != _end) {
      ++_current;
    }
    return _array[_current];
  }
  bool IsDone() {
    if (_current == _end) {
      return true;
    } else {
      return false;
    }
  }
};

#endif //PATTERNS___LAB_1_CMAKE_BUILD_DEBUG_ITERATOR_FOR_ARRAY_H_
