#include <iostream>
#include <cassert>
#include "ArrayList.h"
using namespace std;
template <typename T>
ArrayList<T>::ArrayList(){
    capacity = 10;
    arr = new T[capacity];
    size = 0;
}
template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other){
    capacity = other.capacity;
    arr = new T[capacity];
    size = other.size;
    for (size_t i = 0; i < size; ++i){
        arr[i] = other.arr[i];
    }
}
template <typename T>
ArrayList<T>::ArrayList(size_t c){
    capacity = c;
    arr = new T[c];
    size = 0;
}
template <typename T>
ArrayList<T>::ArrayList(size_t c, T vals){
    capacity = c;
    arr = new T[c];
    size = c;
    for (int i = 0; i < size; ++i){
        arr[i] = vals;
    }
}
template <typename T>
ArrayList<T>::~ArrayList(){
    delete [] arr;
    arr = nullptr;
}
template <typename T>
size_t ArrayList<T>::length(void) const{
    return size;
}
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other){
    if (this != &other){
        delete [] arr;
        capacity = other.capacity;
        arr = new T[capacity];
        size = other.size;
        for (size_t i = 0; i < size; ++i){
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
const T& ArrayList<T>::get(size_t idx) const {
    assert(idx < size && "index is out of bounds");
    return arr[idx];
}
template <typename T>
size_t ArrayList<T>::find(T x) const {
    for (size_t i = 0; i < size; ++i){
        if (arr[i] == x) return i;
    }
    return SIZE_MAX;
}
template <typename T>
void ArrayList<T>::insert(size_t idx, T x){
    assert(idx <= size && "index is out of bounds");
    if (isFull()){
        capacity *= 2;
        T* newArr = new T[capacity];
        for (size_t i = 0; i < size; ++i){
            newArr[i] = arr[i];
        }
        delete [] arr;
        arr = newArr;
    }
    for (size_t i = size; i > idx; --i){
        arr[i] = arr[i-1];
    }
    arr[idx] = x;
    ++size;
}
template <typename T>
void ArrayList<T>::append(T x){
    insert(size, x);
}
template <typename T>
void ArrayList<T>::prepend(T x){
    insert(0, x);
}
template <typename T>
void ArrayList<T>::remove(size_t idx){
    assert(idx < size && "index is out of bounds");
    for (size_t i = idx; i < size - 1; ++i){
        arr[i] = arr[i+1];
    }
    --size;
}
template <typename T>
void ArrayList<T>::remove(T x){
    size_t idx = find(x);
    if (idx != SIZE_MAX){
        remove(idx);
    }
}
template <typename T>
void ArrayList<T>::clear(void){
    size = 0;
}   
template <typename T>
void ArrayList<T>::set(size_t idx, T x){
    assert(idx < size && "index is out of bounds");
    arr[idx] = x;
}
template <typename T>
void ArrayList<T>::traverse(void) const{
    for (size_t i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
template <typename T>
bool ArrayList<T>::isEmpty(void) const{
    return size == 0;
}
template <typename T>
bool ArrayList<T>::isFull(void) const{
    return size == capacity;
}
template <typename T>
bool ArrayList<T>::contains(T x) const{
    return find(x) != SIZE_MAX;
}
template <typename T>
ArrayList<T> ArrayList<T>::subList(size_t i, size_t j){
    assert(i <= j && j <= size && "indices are out of bounds");
    ArrayList<T> sub(j - i);
    for (size_t k = i; k < j; ++k){
        sub.append(arr[k]);
    }
    return sub;
}
template <typename T>
void ArrayList<T>::reverse(void){
    size_t left = 0;
    size_t right = size - 1;
    while (left < right){
        T tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
        ++left;
        --right;
    }
}