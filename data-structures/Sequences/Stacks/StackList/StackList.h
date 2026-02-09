#pragma once
#include <iostream>
#include <cassert>
/*
StackList: is a datastructure that the data is inserted/deleted/read from one end.
The Operation               The Complexity
push(x): O(1)
top(): O(1)
pop(): O(1)
len(): O(1)
*/

template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node<T>(T v = T(), Node<T>* n = nullptr): val(v), next(n){}
};

template <typename T>
class StackList {
private:
    Node<T>* head;
    int length;
public:
    StackList<T>();
    ~StackList<T>();

    T top();
    void pop();
    void push(T x);

    int len();
    bool is_empty();
};

template <typename T>
StackList<T>::StackList() {
    head = nullptr;
    length = 0;
}

template <typename T>
StackList<T>::~StackList() {
    Node<T>* it = head;
    while(it) {
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
}

template <typename T>
T StackList<T>::top() {
    assert((!is_empty()) && "The Stack is Empty!");
    return head->val;
}

template <typename T>
void StackList<T>::pop() {
    assert((!is_empty()) && "The Stack is Empty!");
    Node<T>* del = head;
    head = head->next;
    delete del;
    length--;
}

template <typename T>
void StackList<T>::push(T x) {
    if(is_empty()) {
        head = new Node<T>(x);
        length++;
        return;
    }
    head = new Node<T>(x, head);
    length++;
}

template <typename T>
int StackList<T>::len() {
    return length;
}

template <typename T>
bool StackList<T>::is_empty() {
    return (length == 0);
}