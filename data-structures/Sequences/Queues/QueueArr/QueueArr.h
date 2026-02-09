#pragma once
#include <iostream>
#include <cassert>
/*
QueueArr: is a datastructure that the data is inserted from one end and deleted from the other end (FIFO).
The Operation               The Complexity
enqueue(x): O(n), O(1)
front(): O(1)
back(): O(1)
dequeue(): O(1)
len(): O(1)
*/

template <typename T>
class QueueArr {
private:
    int front_idx;
    int back_idx;
    T* arr;
    int length;
    int capacity;
public:
    QueueArr<T>(int c = 10);
    ~QueueArr<T>();

    T front();
    T back();

    void dequeue();
    void enqueue(T x);

    int len();
    bool is_empty();
    void expand();
};

template <typename T>
QueueArr<T>::QueueArr(int c) {
    capacity = c;
    arr = new T[capacity];
    length = 0;
    front_idx = -1;
    back_idx = -1;
}

template <typename T>
QueueArr<T>::~QueueArr() {
    delete [] arr;
}


template <typename T>
T QueueArr<T>::front() {
    assert((!is_empty()) && "The Queue is Empty!");
    return arr[front_idx];
}
template <typename T>
T QueueArr<T>::back() {
    assert((!is_empty()) && "The Queue is Empty!");
    return arr[back_idx];
}
template <typename T>
void QueueArr<T>::dequeue() {
    assert((!is_empty()) && "The Queue is Empty!");
    if(length == 1) {
        front_idx = -1;
        back_idx = -1;
        length = 0;
        return;
    }
    front_idx = (front_idx + 1) % capacity;
    length--;
}

template <typename T>
void QueueArr<T>::enqueue(T x) {
    if(length == capacity) expand();
    if(is_empty()) {
        front_idx = 0;
    }
    back_idx = (is_empty()? 0: ((back_idx + 1) % capacity));
    arr[back_idx] = x;
    length++;
}

template <typename T>
int QueueArr<T>::len() {
    return length;
}

template <typename T>
bool QueueArr<T>::is_empty() {
    return (length == 0);
}

template <typename T>
void QueueArr<T>::expand() {
    T* new_arr = new T[capacity*2];
    int idx = front_idx;
    for (int i = 0; i < length; ++i) {
        new_arr[i] = arr[idx % capacity];
        idx++;
    }
    delete [] arr;
    arr = new_arr;
    front_idx = 0;
    back_idx = length - 1;
    capacity *= 2;
}