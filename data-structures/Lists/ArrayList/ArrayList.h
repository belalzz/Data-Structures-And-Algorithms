#pragma once
#include <iostream>

template <typename T>
class ArrayList{
private:
    int count;
    int capacity;
    T* arr;
    void create(int newCapacity);
public:
    ArrayList();
    ArrayList(const ArrayList<T>& other);
    ArrayList<T>& operator=(const ArrayList<T>& other);
    T& operator[](int idx);
    ~ArrayList();
    int size(void);
    bool isEmpty(void);
    T get(int idx);
    void set(int idx, T val);
    void insert(int idx, T val);
    void append(T val);
    void remove(int idx);
    int search(T value);
    void clear(void);
};