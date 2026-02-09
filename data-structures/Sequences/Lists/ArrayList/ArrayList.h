#pragma once
#include <iostream>
#include <cassert>

/*
Array List: is a consecutive data structure saves data with the same data type
The Operation               The Complexity
set_at(i, x): O(1)
get_at(i): O(1)
len(): O(1)
iter_seq(): O(n)
insert_at(i, x): O(n)
delete_at(i): O(n)
insert_first(x): O(n)
insert_last(x): O(n)
get_first(): O(1)
get_last(): O(1)
*/

template <typename T>
class ArrayList{    
private:
    int top = -1;
    int length = 0;
    T* arr;
    int capacity = 10;

public: 
    ArrayList<T>();
    ArrayList<T>(int ln);
    ~ArrayList<T>();

    T get_first();
    T get_last();
    T get_at(int i);

    int len() const;
    void expand();

    void insert_first(T x);
    void insert_last(T x);
    void insert_at(int i, T x);

    bool is_empty();
    void set_at(int i, T x);
    void delete_at(int i);
    void delete_first();
    void delete_last();
    void iter_seq();
    T& operator [](int idx);
};

template <typename T>
ArrayList<T>::ArrayList() {
    capacity = 10;
    top = -1;
    arr = new T[capacity];
    length = 0;
}

template <typename T>
ArrayList<T>::ArrayList(int c) {
    capacity = c;
    top = -1;
    arr = new T[capacity];
    length = 0;
}

template <typename T>
ArrayList<T>::~ArrayList(){
    delete [] arr;
}
template <typename T>
T ArrayList<T>::get_at(int idx) {
    assert((idx >= 0 && idx <= top) && "Invalid index");
    return arr[idx];
}

template <typename T>
T ArrayList<T>::get_first() {
    assert(!is_empty() && "The array is empty");
    return arr[0];
}

template <typename T>
T ArrayList<T>::get_last() {
    assert(!is_empty() && "The array is empty");
    return arr[top];
}

template <typename T>
int ArrayList<T>::len() const {
    return length;
}

template <typename T>
void ArrayList<T>::expand() {
    T* newArr = new T[capacity * 2];
    for (int i = 0; i < capacity; ++i) newArr[i] = arr[i];
    capacity *= 2;
    delete [] arr;
    arr = newArr;
}

template <typename T>
void ArrayList<T>::insert_first(T x) {
    if(length + 1 == capacity) expand();
    for (int i = length; i > 0; --i) {
        arr[i] = arr[i-1];
    }
    ++length;
    ++top;
    arr[0] = x;
}

template <typename T>
void ArrayList<T>::insert_last(T x) {
    if(length + 1 == capacity) expand();
    arr[++top] = x;
    length++;
}

template <typename T>
void ArrayList<T>::insert_at(int i, T x) {
    assert((i >= 0 && i <= (top + 1)) && "Invalid index!");
    if (i == 0) {
        insert_first(x);
        return;
    }
    else if(i == (top + 1)) {
        insert_last(x);
        return;
    }

    for (int j = length; j >= i + 1; --j) {
        arr[j] = arr[j-1];
    }
    arr[i] = x;
    ++length;
    ++top;
}


template <typename T>
bool ArrayList<T>::is_empty() {
    return (length == 0);
}

template <typename T>
void ArrayList<T>::set_at(int i, T x) {
    assert((i >= 0 && i <= top) && "Invalid index");
    arr[i] = x;
}

template <typename T>
void ArrayList<T>::delete_at(int i) {
    assert((i >= 0 && i <= top) && "Invalid index");
    for (int j = i; j < length - 1; ++j) {
        arr[j] = arr[j + 1];
    }
    length--;
    top--;
    if(length == 0) top = -1;
}
template <typename T>
void ArrayList<T>::delete_first() {
    assert(!is_empty() && "Invalid index");
    for (int i = 0; i < length - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    length--;
    top--;
    if(length == 0) top = -1;
}
template <typename T>
void ArrayList<T>::delete_last() {
    assert((!is_empty()) && "Invalid index");
    length--;
    top--;
    if(length == 0) top = -1;
}

template <typename T>
void ArrayList<T>::iter_seq() {
    assert(!is_empty() && "The Array is empty!");
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
T& ArrayList<T>::operator[](int idx) {
    assert((idx >= 0 && idx <= top) && "Invalid Index");
    return arr[idx];
}