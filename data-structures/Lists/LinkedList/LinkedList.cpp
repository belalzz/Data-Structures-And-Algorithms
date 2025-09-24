#include <iostream>
#include "LinkedList.h"
#include <cassert>

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0){}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* it = head;
    while(it){
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
}

template <typename T>
void LinkedList<T>::push_back(T value) {
    if (!head){
        head = new Node(value);
        size++;
        tail = head;
        return;
    }
    tail->next = new Node(value);
    tail = tail->next;
    size++;
    return;
}

template <typename T>
void LinkedList<T>::push_front(T value) {
    if (!head){
        head = new Node(value);
        tail = head;
        size++;
        return;
    }
    Node<T>* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;
    return;
}

template <typename T>
void LinkedList<T>::pop_front() {
    assert(size > 0 && "The List is Empty!");
    Node<T>* del = head;
    head = head->next;
    delete del;
    size--;
}
template <typename T>
void LinkedList<T>::pop_back() {
    assert(size > 0 && "The List is Empty!");
    Node<T>* it = head;
    while(it->next != tail) it = it->next;
    delete tail;
    tail = it;
    size--;
}

template <typename T>
void LinkedList<T>::insert(int index, T value) {
    assert(index >= 0 && index <= size && "index is out of bounds.");
    if (index == 0) {
        push_front(value);
        return;
    }else if (index == size){
        push_back(value);
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < index - 1; ++i){
        it = it->next;
    }
    Node<T>* newNode = new Node(value);
    newNode->next = it->next;
    it->next = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    assert(index >= 0 && index < size && "index is out of bounds.");
    if (index == 0){
        pop_front();
        return;
    }else if (index == size - 1){
        pop_back();
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < index - 1; ++i){
        it = it->next;
    }
    Node<T>* del = it->next;
    it->next = del->next;
    delete del;
    size--;
}

template <typename T>
const T& LinkedList<T>::get(int index) const {
    assert(index >= 0 && index < size && "index is out of bounds.");
    Node<T>* it = head;
    for (int i = 0; i < index; ++i){
        it = it->next;
    }
    return it->data;
}

template <typename T>
Node<T>* LinkedList<T>::find(T x) const {
    Node<T>* it = head;
    while (it){
        if (it->data == x) return it;
    }
    return nullptr;
}

template <typename T>
size_t LinkedList<T>::length() const {
    return size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
void LinkedList<T>::clear() {
    Node<T>* it = head;
    while (it){
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
void LinkedList<T>::traverse() const {
    Node<T>* it = head;
    while (it){
        cout << it->data << ' ';
        it = it->next;
    }
    cout << '\n';
}

template <typename T>
void LinkedList<T>::reverse() {
    if (!head) return;
    reverse_H(head);
}

template <typename T>
void LinkedList<T>::reverse_H(Node<T>* node){
    if (!node->next) {
        tail = head;
        head = node;
        return;
    }
    reverse_H(node->next);
    Node<T>* nxt = node->next;
    nxt->next = node;
    node->next = nullptr;
}