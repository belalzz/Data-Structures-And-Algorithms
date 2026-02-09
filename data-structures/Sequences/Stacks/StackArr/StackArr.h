#pragma once
#include <iostream>
#include <cassert>
/*
StackArr: is a datastructure that the data is inserted/deleted/read from one end.
The Operation               The Complexity
push(x): O(n), O(1)
top(): O(1)
pop(): O(1)
len(): O(1)
*/

template <typename T>
class StackArr {
private:
    int last;
    T* arr;
    int length;
    int capacity;
public:
    StackArr<T>(int c = 10);
    ~StackArr<T>();

    T top();
    void pop();
    void push(T x);

    int len();
    bool is_empty();
    void expand();
};

template <typename T>
StackArr<T>::StackArr(int c) {
    capacity = c;
    arr = new T[capacity];
    length = 0;
    last = -1;
}

template <typename T>
StackArr<T>::~StackArr() {
    delete [] arr;
}

template <typename T>
T StackArr<T>::top() {
    assert((!is_empty()) && "The Stack is Empty!");
    return arr[last];
}

template <typename T>
void StackArr<T>::pop() {
    assert((!is_empty()) && "The Stack is Empty!");
    last--;
    length--;
    if(is_empty()) last = -1;
}

template <typename T>
void StackArr<T>::push(T x) {
    if(length == capacity) expand();
    arr[++last] = x;
    length++;
}

template <typename T>
int StackArr<T>::len() {
    return length;
}

template <typename T>
bool StackArr<T>::is_empty() {
    return (length == 0);
}

template <typename T>
void StackArr<T>::expand() {
    T* new_arr = new T[capacity*2];
    for (int i = 0; i < capacity; ++i) {
        new_arr[i] = arr[i];
    }
    delete [] arr;
    arr = new_arr;
    capacity *= 2;
}