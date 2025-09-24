#pragma once
#include <iostream>

template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T val): data{val}, next{nullptr}, prev{nullptr}{}
};

template <typename T>
class DoublyLL{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DoublyLL();
    ~DoublyLL();
    
    void push_front(T val);
    void push_back(T val);
    
    void pop_front();
    void pop_back();

    T front() const;
    T back() const;

    bool isEmpty() const;
    int length() const;

    void traverse() const;

    void clear();
    void reverse();

    void insertAt(int index, T val);
    void removeAt(int index);

    T get(int index) const;
    Node<T>* find(T val) const; // returns node containing the value or nullptr
    bool contains(T val) const; // true if element exists
};