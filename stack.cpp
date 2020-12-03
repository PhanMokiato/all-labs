//
// Created by Zver on 22.11.2020.
//
#include <string>
#include "stack.h"
#include <iostream>


bool Stack_A::IsEmpty() {
    return top == -1;
}


bool Stack_A::IsFull(){
    return top == capacity - 1;
}


int Stack_A::Size()
{
    return top + 1;
}


double Stack_A::Peek()
{
    if (!IsEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

double Stack_A::Top() {
    return arr[top];
}


//double Stack_A::PopTheTop()
//{
//    if (IsEmpty())
//    {
//        std::cout << "UnderFlow\nProgram Terminated\n";
//        exit(EXIT_FAILURE);
//    }
//    double LastTop = arr[top];
//    --top;
//    return LastTop;
//}
//
//double Stack_A::PopTheFirst() {
//    double first = arr[0];
//    for (int i = 0; i < top; ++i) {
//        arr[i] = arr[i + 1];
//    }
//    --top;
//    return first;
//}

void Stack_A::PrintStack_A () {
    if (!IsEmpty()) {
        for (int i = 0; i < top + 1; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Actually, this stack is empty." << std::endl;
    }
}


double Stack_A::GetElement(int elem){
    return arr[elem - 1];
}

void operator<<(Stack_A &st,const double &value) {
    if (st.IsFull())
    {
        std::cout << "There is too much elements";
    } else {
        ++st.capacity;
        ++st.top;
        st.arr[st.top] = value;
    }
}

double Stack_A::operator>>(Stack_A &stack){
    if (IsEmpty())
    {
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    double LastTop = arr[top];
    --top;
    return LastTop;
}

Stack_A& Stack_A::operator=(const Stack_A &st){
    delete [] arr;
    top = st.top;
    capacity = st.capacity;
    arr = new double[capacity];
    for (int i = 0; i <= st.top; ++i) {
        arr[i] = st.arr[i];
    }
    return *this;
}

bool operator<(Stack_A &st1, Stack_A &st2){
    return st1.Size() < st2.Size();
}

bool operator>(Stack_A &st1, Stack_A &st2){
    return st1.Size() > st2.Size();
}

bool operator==(Stack_A &st1, Stack_A &st2){
    return st1.Size() == st2.Size();
}

double& Stack_A::operator[](const int &n) {
    return arr[n];
}