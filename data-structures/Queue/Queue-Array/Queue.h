#pragma once

template <typename T>
class Queue{
    private:
    T* arr;
    int Front;
    int Back;
    int Capacity;
    int Size;
    void expand(void);
public:
    Queue(int cap = 10);
    ~Queue();
    void push(const T x);
    void pop(void);
    const T& front(void) const;
    const T& back(void) const;
    int size(void) const;
    bool isEmpty(void) const;
};