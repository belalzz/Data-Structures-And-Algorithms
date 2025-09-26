#pragma once
#include <iostream>
#include <cassert>
#include "Stack.h"

using namespace std;

template<typename T>
Stack<T>::Stack(int c){
    Size = 0;
    capacity = c;
    arr = new T[capacity];
    Top = -1;
}
template<typename T>
Stack<T>::~Stack(){
    delete [] arr;
    arr = nullptr;
}
template<typename T>
void Stack<T>::expand(void){
    capacity = capacity * 2;
    T* newArr = new T[capacity];
    for (int i = 0; i < Size; ++i){
        newArr[i] = arr[i];
    }
    delete [] arr;
    arr = newArr;
}

template<typename T>
void Stack<T>::push(T x){
    if(Size == capacity){
        expand();
    }
    Size++;
    Top++;
    arr[Top] = x;
}

template<typename T>
void Stack<T>::pop(void){
    assert(Size > 0 && "The Stack is Empty!");
    Top--;
    Size--;
}

template<typename T>
const T Stack<T>::top(void){
    assert(Size > 0 && "The Stack is Empty!");
    return arr[Top];
}

template<typename T>
bool Stack<T>::isEmpty(void){
    return Size == 0;
}

template<typename T>
int Stack<T>::size(void){
    return Size;
}