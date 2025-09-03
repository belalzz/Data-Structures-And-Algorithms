#include "ArrayList.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
ArrayList<T>::ArrayList(){
    count = 0;
    arr = nullptr;
    create(10);
}
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other){
    count = other.count;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < count; ++i) arr[i] = other.arr[i];
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    if (this == &other) return *this;
    delete[] arr;
    count = other.count;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < count; ++i) arr[i] = other.arr[i];
    return *this;
}

template <typename T>
T& ArrayList<T>::operator[](int idx) {
    assert(idx >= 0 && idx < count);
    return arr[idx];
}

template <typename T>
ArrayList<T>::~ArrayList(){
    delete[] arr;
}

template <typename T>
void ArrayList<T>::create(int newCapacity){
    T* newArr = new T[newCapacity];
    if (!arr){
        arr = newArr; 
        capacity = newCapacity;
        return;
    }
    for (int i = 0; i < count; ++i){
        newArr[i] = arr[i];
    }
    delete [] arr;
    arr = newArr;
    capacity = newCapacity;
}

template <typename T>
int ArrayList<T>::size(){
    return count;
}

template <typename T>
bool ArrayList<T>::isEmpty(){
    return (count == 0);
}

template <typename T>
T ArrayList<T>::get(int idx){
    assert((idx < count) && "index is out of bounds!!");
    return arr[idx];
}

template <typename T>
void ArrayList<T>::set(int idx, T val){
    assert( (idx < count && idx >= 0) &&"index is out of bounds!!");
    arr[idx] = val;
}

template <typename T>
void ArrayList<T>::append(T val){
    if (count == capacity){
        create(capacity * 2);
    }
    arr[count] = val;
    ++count;
}

template <typename T>
void ArrayList<T>::remove(int idx){
    assert( (idx < count && idx >= 0) &&"index is out of bounds!!");
    for (int i = idx; i < count - 1; ++i){
        arr[i] = arr[i + 1];
    }
    --count;
}

template <typename T>
int ArrayList<T>::search(T val){
    for (int i = 0; i < count; ++i){
        if (val == arr[i]) return i;
    }
    return -1;
}

template <typename T>
void ArrayList<T>::insert(int idx, T val){
    if (idx == count) {
        append(val);
        return;
    }
    if (count == capacity) {
        create(capacity * 2);
    }
    assert( (idx < count && idx >= 0) &&"index is out of bounds!!");
    for (int i = count; i > idx; --i){
        arr[i] = arr[i-1];
    }
    arr[idx] = val;
    ++count;
}

template <typename T>
void ArrayList<T>::clear(){
    capacity = 10;
    count = 0;
    delete [] arr;
    arr = new T[capacity];
}