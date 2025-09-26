#pragma once

template <typename T>
class Node{
public:
    T val;
    Node<T>* next;
    Node(T x, Node<T>* nxt): val{x}, next{nxt}{}
    Node(T x): val{x}, next{nullptr}{} 
};

template <typename T>
class Queue{
private:
    Node<T>* head;
    Node<T>* tail;
    int Size;
public:
    Queue();
    ~Queue();
    void push(const T& x);
    void pop(void);
    bool isEmpty(void) const;
    int size(void) const;
    const T& front(void) const;
    const T& back(void) const;
};
