#pragma once
#include <iostream>
template<typename T>
class Stack{
private:
    T* arr;
    int capacity;
    int Top;
    int Size;
    void expand(void);
public:
    Stack(int c = 10);
    ~Stack();
    void push(T x);
    void pop(void);
    const T top(void);
    bool isEmpty(void);
    int size(void);
};