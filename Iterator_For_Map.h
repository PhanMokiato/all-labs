//
// Created by Zver on 08.09.2021.
//

#ifndef PATTERNS___LAB_1__ITERATOR_FOR_MAP_H_
#define PATTERNS___LAB_1__ITERATOR_FOR_MAP_H_

#include <map>
#include <string>
#include "Iterator_For_Array.h"

class ItForMap{
 private:
  std::map<std::string, std::string> *_map;
  std::map<std::string, std::string> :: iterator _it;
  std::map<std::string, std::string> :: iterator _begin;
  std::map<std::string, std::string> :: iterator _end;
 public:
  ItForMap(std::map<std::string, std::string> *map) : _map(map) {
    _it = _map->begin();
    _begin = _map->begin();
    _end = _map->end();
    --_end;
  }
  std::string First() {
    return _begin->first;
  }
  std::string Current() {
    return _it->first;
  }
  std::string Next() {
    if (_it != _end) {
      ++_it;
    }
    return _it->first;
  }
  bool IsDone() {
    if (_it == _end) {
      return true;
    } else {
      return false;
    }
  }
};

#endif //PATTERNS___LAB_1__ITERATOR_FOR_MAP_H_
