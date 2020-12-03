#pragma once
#include <iostream>
class Stack_A {
private:
    double *arr;
    int top;
    int capacity;
public:
    Stack_A(int size = 100){
        arr = new double[size];
        capacity = size;
        top = -1;
    }
    Stack_A(Stack_A &list){
        arr = new double[100];
        capacity = list.capacity;
        top = list.top;
        for (int i = 0; i <= list.top; ++i) {
            arr[i] = list.arr[i];
        }
    }
    Stack_A(const std::initializer_list<double> &list) : Stack_A(list.size()) {
        int count = 0;
        arr = new double[100];
        for (auto &element : list)
        {
            arr[count] = element;
            ++count;
        }
        capacity = count;
        top = count - 1;
    }

    bool IsEmpty();

    bool IsFull();

    int Size();

    double Peek();

    double Top();

//    double PopTheTop();
//
//    double PopTheFirst();

    void PrintStack_A();

    double GetElement(int elem);

    friend void operator<<(Stack_A &st,const double &value);

    double operator>>(Stack_A &stack);

    Stack_A& operator=(const Stack_A &st);

    friend bool operator<(Stack_A &st1, Stack_A &st2);

    friend bool operator>(Stack_A &st1, Stack_A &st2);

    friend bool operator==(Stack_A &st1, Stack_A &st2);

    double& operator[](const int &n);
};

