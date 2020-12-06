//
// Created by Zver on 05.12.2020.
//

#ifndef KR2_GR4_MOKIEVEC_DASHA_BIDIRECTIONAL_LIST_ON_ARRAY_H
#define KR2_GR4_MOKIEVEC_DASHA_BIDIRECTIONAL_LIST_ON_ARRAY_H

#include <iostream>
#include <exception>
#include <initializer_list>
#include <vector>

template<class T>
class BiDirectionalListOnArray {
 private:
  T *data_;
  size_t size_ = 0;
  size_t capacity_;

  static const size_t MIN_CAPACITY = 10;
  static const size_t GROWTH_FACTOR = 2;
 public:
  BiDirectionalListOnArray() {
    data_ = new T[MIN_CAPACITY];
    size_ = 0;
    capacity_ = MIN_CAPACITY;
  }


  BiDirectionalListOnArray(const std::initializer_list<T> &list) {
    data_ = new T[MIN_CAPACITY];
    for (auto &element : list) {
      ++size_;
      data_[size_ - 1] = element;
    }
    capacity_ = MIN_CAPACITY;
  }

  BiDirectionalListOnArray(const BiDirectionalListOnArray &list) {
    capacity_ = list.capacity_;
    data_ = new T[capacity_];
    size_ = list.size_;
    for (int i = 0; i < size_; ++i) {
      data_[i] = list.data_[i];
    }
  }

  BiDirectionalListOnArray(BiDirectionalListOnArray&& list)  noexcept {
    data_ = new T[MIN_CAPACITY];
    capacity_ = list.capacity;
    size_ = list.size_;
    for (int i = 0; i < size_; ++i) {
      data_[i] = list.data_[i];
    }
    delete [] list.data_;
    list.size_ = 0;
  }
  const T *Front() {
    T *bottom_ptr = &data_[0];
    return bottom_ptr;

  }

  const T *Back() {
    T *top_ptr = &data_[size_ - 1];
    return top_ptr;
  }

  BiDirectionalListOnArray<T> &operator=(const BiDirectionalListOnArray<T> &list) {
    delete[] data_;
    size_ = list.size_;
    capacity_ = list.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i <= size_; ++i) {
      data_[i] = list.data_[i];
    }
    return *this;
  }

  BiDirectionalListOnArray<T> &operator=(BiDirectionalListOnArray<T> &&list) {
    delete[] data_;
    size_ = list.size_;
    capacity_ = list.capacity_;
    data_ = new T[capacity_];
    for (int i = 0; i <= size_; ++i) {
      data_[i] = list.data_[i];
    }
    return *this;
    delete [] list.data_;
    list.size_ = 0;
  }

  int Size() {
    return size_;
  }

  bool IsEmpty() {
    return size_ == 0;
  }

  T &operator[](const int &n) {
    try {
      if (n < 0 || n >= size_) {
        throw std::exception();
      }
      return data_[n];
    } catch (std::exception) {
      std::cout << "Wrong index!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  std::vector<T> ToVector() {
    std::vector<T> words;
    for (int i = 0; i < size_; ++i) {
      words.push_back(data_[i]);
    }
    return words;
  }

  void PushFront(const T &value) {
    ++size_;
    for (int i = size_ - 1; i > 0; --i) {
      data_[i] = data_[i - 1];
    }
    data_[0] = value;
  }

  void PushBack(const T &value) {
    data_[size_] = value;
    ++size_;
  }
  void PushFront(T &&value) noexcept {
    ++size_;
    for (int i = size_ - 1; i > 0; --i) {
      data_[i] = data_[i - 1];
    }
    data_[0] = value;
    value = 0;
  }

  void PushBack(T &&value) noexcept {
    data_[size_] = value;
    ++size_;
    value = 0;
  }

  void PopFront() {
    for (int i = 0; i < size_ - 1; ++i) {
      data_[i] = data_[i + 1];
    }
    --size_;
  }

  void PopBack() {
    data_[size_ - 1] = 0;
    --size_;
  }

  void InsertBefore(size_t index, const T &value) {
    try {
      if (index < 0 || index >= size_) {
        throw std::exception();
      }
      if (index == 0) {
        PushFront(value);
      } else {
        ++size_;
        for (int i = size_ - 1; i >= index; --i) {
          data_[i] = data_[i - 1];
        }
        data_[index] = value;
      }
    } catch (std::exception) {
      std::cout << "Wrong index!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  void InsertAfter(size_t index, const T &value) {
    try {
      if (index < 0 || index >= size_) {
        throw std::exception();
      }
      if (index == size_ - 1) {
        PushBack(value);
      } else {
        ++size_;
        for (int i = size_ - 1; i > index; --i) {
          data_[i] = data_[i - 1];
        }
        data_[index + 1] = value;
      }
    } catch (std::exception) {
      std::cout << "Wrong index!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  void InsertBefore(size_t index, T&& value) noexcept{
    try {
      if (index < 0 || index >= size_) {
        throw std::exception();
      }
      if (index == 0) {
        PushFront(value);
      } else {
        ++size_;
        for (int i = size_ - 1; i > index; --i) {
          data_[i] = data_[i - 1];
        }
        data_[index] = value;
      }
      value = 0;
    } catch (std::exception) {
      std::cout << "Wrong index!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  void InsertAfter(size_t index, T&& value) {
    try {
      if (index < 0 || index >= size_) {
        throw std::exception();
      }
      if (index == size_ - 1) {
        PushBack(value);
      } else {
        ++size_;
        for (int i = size_ - 1; i > index; --i) {
          data_[i] = data_[i - 1];
        }
        data_[index + 1] = value;
      }
      value = 0;
    } catch (std::exception) {
      std::cout << "Wrong index!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  void Erase(size_t index) {
    try {
      if (index < 0 || index >= size_) {
        throw std::exception();
      }
      for (int i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
      }
      --size_;
    } catch (std::exception) {
      std::cout << "Wrong index!" << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  int Find(const T& value) {
    bool has;
    int index = 0;
    for (int i = 0; i < size_; ++i) {
      if (data_[i] == value) {
        has = true;
        index = i;
        break;
      }
    }
    if (has == true) {
      return index;
    } else {
      return -1;
    }
  }

  std::vector<int> FindAll(const T& value) {
    std::vector<int> indexes;
    for (int i = 0; i < size_; ++i) {
      if (data_[i] == value) {
          indexes.push_back(i);
      }
    }
    return indexes;
  }

  bool operator==(BiDirectionalListOnArray<T> &list) {
    bool equal = true;
    if (size_ != list.size_) {
      equal = false;
    }
    for (int i = 0; i < size_; ++i) {
      if (data_[i] != list.data_[i]) {
        equal = false;
        break;
      }
    }
    return equal;
  }

  bool operator<(BiDirectionalListOnArray<T> &list) {
    return size_ < list.size_;
  }

  bool operator>(BiDirectionalListOnArray<T> &list) {
    return size_ > list.size_;
  }

  bool operator!=(BiDirectionalListOnArray<T> &list) {
    bool not_equal = false;
    if (size_ != list.size_) {
      not_equal = true;
    }
    for (int i = 0; i < size_; ++i) {
      if (data_[i] != list.data_[i]) {
        not_equal = true;
        break;
      }
    }
    return not_equal;
  }

  void Print() {
    for(int i = 0; i < size_; ++i) {
      std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
  }

  ~BiDirectionalListOnArray() {
    delete []data_;
  }
};

#endif //KR2_GR4_MOKIEVEC_DASHA_BIDIRECTIONAL_LIST_ON_ARRAY_H
