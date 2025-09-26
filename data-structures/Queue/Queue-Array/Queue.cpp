#pragma once
#include <iostream>
#include <cassert>
#include "Queue.h"
using namespace std;

template <typename T>
Queue<T>::Queue(int cap){
    Capacity = cap;
    arr = new T[Capacity];
    Front = -1;
    Back = -1;
    Size = 0;
}

template <typename T>
Queue<T>::~Queue(){
    delete[] arr;
}

template <typename T>
void Queue<T>::expand(void){
    T* newArr = new T[Capacity * 2];
    for (int i = 0; i < Capacity; ++i){
        newArr[i] = arr[(Front + i) % Capacity];
    }
    Capacity *= 2;
    Front = 0;
    Back = Size - 1;
    delete [] arr;
    arr = newArr;
}

template <typename T>
void Queue<T>::push(const T x){
    if (isEmpty()) {
        Front = 0;
        Back = 0;
        arr[0] = x;
        Size = 1;
        return;
    }
    if(Size == Capacity){
        expand();
    }
    Back = (Back + 1) % Capacity;
    Size++;
    arr[Back] = x;
}
template <typename T>
void Queue<T>::pop(void){
    assert(!isEmpty() && "Cannot pop from an empty queue");
    Front = (Front + 1) % Capacity;
    Size--;
    if(isEmpty()){
        Front = -1;
        Back = -1;
    }
}
template <typename T>
const T& Queue<T>::front(void) const{
    assert(!isEmpty() && "Queue is empty");
    return arr[Front];
}

template <typename T>
const T& Queue<T>::back(void) const{
    assert(!isEmpty() && "Queue is empty");
    return arr[Back];
}

template <typename T>
int Queue<T>::size(void) const{
    return Size;
}
template <typename T>
bool Queue<T>::isEmpty(void) const{
    return Size == 0;
}