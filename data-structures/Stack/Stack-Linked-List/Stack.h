#pragma once
template <typename T>
class Node{
public:
    T val;
    Node<T>* next;
    Node(T v, Node<T>* n):val{v}, next{n}{}
    Node(T v):val{v}, next{nullptr}{}
};

template <typename T>
class Stack {
private:
    Node<T>* Top;
    int Size;
public:
    Stack();
    ~Stack();
    void push(T x);
    void pop(void);
    bool isEmpty(void);
    const T top(void);
    int size(void);
};