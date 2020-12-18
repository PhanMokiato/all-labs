#pragma once
#include <iostream>
#include <string>

template <class T>
class Stack_A {
private:
    T *arr;
    int top;
    int capacity;
public:
    Stack_A(int size = 100){
        arr = new T[size];
        capacity = size;
        top = -1;
    }
    Stack_A(Stack_A<T> &list){
        arr = new T[100];
        capacity = list.capacity;
        top = list.top;
        for (int i = 0; i <= list.top; ++i) {
            arr[i] = list.arr[i];
        }
    }
    Stack_A(const std::initializer_list<T> &list) : Stack_A(list.size()) {
        int count = 0;
        arr = new T[100];
        for (auto &element : list)
        {
            arr[count] = element;
            ++count;
        }
        capacity = 100;
        top = count - 1;
    }

  bool IsEmpty() {
  return top == -1;
  }

  bool IsFull(){
  return top == capacity - 1;
  }

     int Size()
     {
       return top + 1;
     }


     T Peek()
     {
       if (!IsEmpty())
        return arr[top];
       else
        exit(EXIT_FAILURE);
     }

  T Top() {
    return arr[top];
   }

void PrintStack_A () {
  if (!IsEmpty()) {
    for (int i = 0; i < top + 1; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  } else {
    std::cout << "Actually, this stack is empty." << std::endl;
  }
}

  T GetElement(int elem){
  return arr[elem - 1];
  }

    friend void operator<<(const Stack_A<T> &st,const T &value);

  T operator>>(Stack_A &stack){
  if (IsEmpty())
  {
    std::cout << "UnderFlow\nProgram Terminated\n";
    exit(EXIT_FAILURE);
  }
  T LastTop = arr[top];
  --top;
  return LastTop;
  }

  Stack_A<T>& operator=(const Stack_A &st){
  delete [] arr;
  top = st.top;
  capacity = st.capacity;
  arr = new T[capacity];
  for (int i = 0; i <= st.top; ++i) {
    arr[i] = st.arr[i];
  }
  return *this;
}

    friend bool operator<(Stack_A &st1, Stack_A &st2);

    friend bool operator>(Stack_A &st1, Stack_A &st2);

    friend bool operator==(Stack_A &st1, Stack_A &st2);

    T& operator[](const int &n);
};

//template <typename T>
//bool Stack_A<T>::IsEmpty() {
//  return top == -1;
//}
//
//template <typename T>
//bool Stack_A<T>::IsFull(){
//  return top == capacity - 1;
//}
//
//template <typename T>
//int Stack_A<T>::Size()
//{
//  return top + 1;
//}
//
//template <typename T>
//T Stack_A<T>::Peek()
//{
//  if (!IsEmpty())
//    return arr[top];
//  else
//    exit(EXIT_FAILURE);
//}
//
//template <typename T>
//T Stack_A<T>::Top() {
//  return arr[top];
//}
//
//template <typename T>
//void Stack_A<T>::PrintStack_A () {
//  if (!IsEmpty()) {
//    for (int i = 0; i < top + 1; ++i) {
//      std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//  } else {
//    std::cout << "Actually, this stack is empty." << std::endl;
//  }
//}
//
//template <typename T>
//T Stack_A<T>::GetElement(int elem){
//  return arr[elem - 1];
//}
//

template <typename T>
void operator<<(const Stack_A<T> &st,const T &value) {
  if (st.IsFull())
  {
    std::cout << "There is too much elements." << std::endl;
  } else {
    ++st.capacity;
    ++st.top;
    st.arr[st.top] = value;
  }
}

//template <typename T>
//T Stack_A<T>::operator>>(Stack_A &stack){
//  if (IsEmpty())
//  {
//    std::cout << "UnderFlow\nProgram Terminated\n";
//    exit(EXIT_FAILURE);
//  }
//  T LastTop = arr[top];
//  --top;
//  return LastTop;
//}
//
//template <typename T>
//Stack_A<T>& Stack_A<T>::operator=(const Stack_A &st){
//  delete [] arr;
//  top = st.top;
//  capacity = st.capacity;
//  arr = new T[capacity];
//  for (int i = 0; i <= st.top; ++i) {
//    arr[i] = st.arr[i];
//  }
//  return *this;
//}
//
template <typename T>
bool operator<(Stack_A<T> &st1, Stack_A<T> &st2){
  return st1.Size() < st2.Size();
}

template <typename T>
bool operator>(Stack_A<T> &st1, Stack_A<T> &st2){
  return st1.Size() > st2.Size();
}

template <typename T>
bool operator==(Stack_A<T> &st1, Stack_A<T> &st2){
  return st1.Size() == st2.Size();
}

template <typename T>
T& Stack_A<T>::operator[](const int &n) {
  return arr[n];
}