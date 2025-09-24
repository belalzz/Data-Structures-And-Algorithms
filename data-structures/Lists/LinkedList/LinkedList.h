#pragma once
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
protected:
    void reverse_H(Node<T>* node);
public:
    LinkedList();
    ~LinkedList();
    void push_back(T value);
    void push_front(T value);
    void pop_back();
    void pop_front();
    void insert(int index, T value);
    void remove(int index);
    const T& get(int index) const;
    Node<T>* find(T x) const;
    size_t length() const;
    bool isEmpty() const;
    void clear();
    void traverse() const;
    void reverse();
};