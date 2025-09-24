#include <iostream>
#include "DoublyLL.h"
#include <cassert>

using namespace std;

template <typename T>
DoublyLL<T>::DoublyLL(): head{nullptr}, tail{nullptr}, size{0} {}

template <typename T>
DoublyLL<T>::~DoublyLL() {
    Node<T>* it = head;
    while (it){
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void DoublyLL<T>::push_front(T val) {
    if(isEmpty()){
        head = new Node(val);
        tail = head;
        size++;
        return;
    }
    Node<T>* newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    size++;
}

template <typename T>
void DoublyLL<T>::push_back(T val) {
    if(isEmpty()){
        head = new Node(val);
        tail = head;
        size++;
        return;
    }
    Node<T>* newNode = new Node(val);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    size++;
}

template <typename T>
void DoublyLL<T>::pop_front() {
    assert(size > 0 && "The List is Empty!");
    Node<T>* del = head;
    head = head->next;
    head->prev = nullptr;
    delete del;
    size--;
}
template <typename T>
void DoublyLL<T>::pop_back() {
    assert(size > 0 && "The List is Empty!");
    Node<T>* del = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete del;
    size--;
}

template <typename T>
T DoublyLL<T>::front() const {
    assert(size > 0 && "The List is Empty!");
    return head->data;
}
template <typename T>
T DoublyLL<T>::back() const {
    assert(size > 0 && "The List is Empty!");
    return tail->data;
}
template <typename T>
bool DoublyLL<T>::isEmpty() const {
    return size == 0;
}
template <typename T>
int DoublyLL<T>::length() const {
    return size;
}
template <typename T>
void DoublyLL<T>::traverse() const {
    Node<T>* it = head;
    while(it){
        cout << it->data << ' ';
        it = it->next;
    }
}

template <typename T>
void DoublyLL<T>::clear() {
    Node<T>* it = head;
    while(it){
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
void DoublyLL<T>::reverse() {
    int cnt = size / 2;
    Node<T>* it1 = head;
    Node<T>* it2 = tail;
    for (int i = 0; i < cnt; ++i){
        T tmp = it1->data;
        it1->data = it2->data;
        it2->data = tmp;
        it1 = it1->next;
        it2 = it2->prev;
    }
}
template <typename T>
void DoublyLL<T>::insertAt(int index, T val) {
    assert(index<=size && index >= 0 && "Index is out of bounds!");
    if(index == 0){
        push_front(val);
        return;
    }
    if(index == size){
        push_back(val);
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < index-1; ++i){
        it = it->next;
    }
    Node<T>* newNode = new Node(val);
    newNode->next = it->next;
    it->next->prev = newNode;
    it->next = newNode;
    newNode->prev = it;
    size++;
}

template <typename T>
void DoublyLL<T>::removeAt(int index) {
    assert(index<size && index >= 0 && "Index is out of bounds!");
    if(index == 0){
        pop_front();
        return;
    }
    if(index == size-1){
        pop_back();
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < index-1; ++i){
        it = it->next;
    }
    Node<T>* del = it->next;
    it->next = del->next;
    if(del->next) del->next->prev = it;
    delete del;
    size--;
}

template <typename T>
T DoublyLL<T>::get(int index) const {
    assert(index<size && index >= 0 && "Index is out of bounds!");
    Node<T>* it = head;
    for (int i = 0; i < index; ++i){
        it = it->next;
    }
    return it->data;
}

template <typename T>
Node<T>* DoublyLL<T>::find(T val) const {
    Node<T>* it = head;
    while (it) {
        if (it->data == val) {
            return it;
        }
        it = it->next;
    }
    return nullptr;
}

template <typename T>
bool DoublyLL<T>::contains(T val) const {
    return find(val) != nullptr;
}