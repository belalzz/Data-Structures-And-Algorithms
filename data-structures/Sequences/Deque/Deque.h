#include <iostream>
#include <cassert>

/*
Deque: is a consecutive data structure which can be accessed in O(1) and insert_last/insert_first O(1) amortized and delete_first/delete_last in O(1).

insert_first: O(1)
insert_last: O(1)

delete_first: O(1)
delete_last: O(1)

get_at(i): O(1)

front: O(1)
back: O(1)

is_empty: O(1)
size: O(1)
*/


template <typename T>
class Deque {
private:
    T* arr; 
    int front_idx;
    int back_idx;
    int length;
    int capacity;
public:
    Deque<T>(int c = 10);
    ~Deque<T>();

    T front();
    T back();

    void insert_first(T x);
    void insert_last(T x);
    
    T get_at(int i);

    void delete_first();
    void delete_last();

    int len();
    bool is_empty();
    void expand();
};

template <typename T>
Deque<T>::Deque(int c) {
    capacity = c;
    arr = new T[capacity];
    length = 0;
    front_idx = -1;
    back_idx = -1;
}

template <typename T>
Deque<T>::~Deque() {
    delete [] arr;
}


template <typename T>
T Deque<T>::front() {
    assert((!is_empty()) && "The Queue is Empty!");
    return arr[front_idx];
}

template <typename T>
T Deque<T>::back() {
    assert((!is_empty()) && "The Queue is Empty!");
    return arr[back_idx];
}

template <typename T>
void Deque<T>::delete_first() {
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
void Deque<T>::delete_last() {
    assert((!is_empty()) && "The Queue is Empty!");
    if(length == 1) {
        front_idx = -1;
        back_idx = -1;
        length = 0;
        return;
    }
    back_idx = (back_idx - 1 + capacity) % capacity;
    length--;
}
template <typename T>
void Deque<T>::insert_first(T x) {
    if(length == capacity) expand();
    if(is_empty()) {
        front_idx = 0;
        back_idx = 0;
        length = 1;
        arr[front_idx] = x;
        return;
    }
    front_idx = (front_idx - 1 + capacity) % capacity;
    arr[front_idx] = x;
    length++;
}
template <typename T>
void Deque<T>::insert_last(T x) {
    if(length == capacity) expand();
    if(is_empty()) {
        front_idx = 0;
        back_idx = 0;
        length = 1;
        arr[front_idx] = x;
        return;
    }
    back_idx = (back_idx + 1) % capacity;
    arr[back_idx] = x;
    length++;
}

template <typename T>
T Deque<T>::get_at(int idx) {
    assert((idx >= 0 && idx < length) && "Invalid index");
    int i = (front_idx + idx) % capacity;
    return arr[i];
}

template <typename T>
int Deque<T>::len() {
    return length;
}

template <typename T>
bool Deque<T>::is_empty() {
    return (length == 0);
}

template <typename T>
void Deque<T>::expand() {
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