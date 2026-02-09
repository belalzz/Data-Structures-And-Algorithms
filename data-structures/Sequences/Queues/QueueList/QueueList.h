#pragma once
#include <iostream>
#include <cassert>
/*
QueueList: is a datastructure that the data is inserted from one end and deleted from the other end (FIFO).
The Operation               The Complexity
enqueue(x): O(1)
front(): O(1)
back(): O(1)
dequeue(): O(1)
len(): O(1)
*/

template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node(T x = T(), Node<T>* nxt = nullptr) : val(x), next(nxt) {}
};

template <typename T>
class QueueList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    QueueList<T>();
    ~QueueList<T>();

    T front();
    T back();

    void dequeue();
    void enqueue(T x);

    int len();
    bool is_empty();
};

template <typename T>
QueueList<T>::QueueList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
QueueList<T>::~QueueList() {
    Node<T>* it = head;
    while(it) {
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
}

template <typename T>
T QueueList<T>::front() {
    assert((!is_empty()) && "The Queue is Empty!");
    return head->val;
}
template <typename T>
T QueueList<T>::back() {
    assert((!is_empty()) && "The Queue is Empty!");
    return tail->val;
}

template <typename T>
void QueueList<T>::dequeue() {
    assert((!is_empty()) && "The Queue is Empty!");
    if(length == 1) {
        delete head;
        head = tail = nullptr;
        length = 0;
        return;
    }
    Node<T>* del = head;
    head = head->next;
    delete del;
    length--;
}

template <typename T>
void QueueList<T>::enqueue(T x) {
    if(is_empty()) {
        head = new Node<T>(x);
        tail = head;
        length = 1;
        return;
    }
    tail->next = new Node<T>(x);
    tail = tail->next;
    length++;
}

template <typename T>
int QueueList<T>::len() {
    return length;
}

template <typename T>
bool QueueList<T>::is_empty() {
    return (length == 0);
}