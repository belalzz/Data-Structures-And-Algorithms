#pragma once
#include <iostream>
#include <cassert>
/*
Double Linked List: is pointer based data structure that saves data in structures called nodes 
the nodes are the value saved and a pointer to the address of the next node if exist else nullptr and the address of the previous one if existed.

The Operation               The Complexity
set_at(i, x): O(n)
get_at(i): O(n)
len(): O(1)
iter_seq(): O(n)
insert_at(i, x): O(n)
delete_at(i): O(n)
insert_first(x): O(1)
insert_last(x): O(1)
get_first(): O(1)
get_last(): O(1)
is_empty(): O(1)
*/

template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node<T>* prev;
    Node(T x = T(), Node<T>* prv = nullptr, Node<T>* nxt = nullptr) : val(x), prev(prv), next(nxt) {}
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
public:
    DoubleLinkedList<T>();
    ~DoubleLinkedList<T>();
    
    T get_first();
    T get_last();
    T get_at(int i);
    
    int len() const;
    
    void insert_first(T x);
    void insert_last(T x);
    void insert_at(int i, T x);
    
    bool is_empty();
    void set_at(int i, T x);
    void delete_at(int i);
    void delete_first();
    void delete_last();
    void iter_seq(bool rev = false);
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    Node<T>* it = head;
    while (it) {
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
}


template <typename T>
T DoubleLinkedList<T>::get_at(int idx) {
    assert((idx >= 0 && idx < length) && "Invalid index");
    if(length == 1) return head->val;
    if(idx == 0) return head->val;
    if(idx == length - 1) return tail->val;
    Node<T>* it = head;
    for (int i = 0; i < idx; ++i) it = it->next;
    return it->val;
}

template <typename T>
T DoubleLinkedList<T>::get_first() {
    assert(!is_empty() && "The List is empty");
    return head->val;
}

template <typename T>
T DoubleLinkedList<T>::get_last() {
    assert(!is_empty() && "The List is empty");
    return tail->val;
}

template <typename T>
int DoubleLinkedList<T>::len() const {
    return length;
}

template <typename T>
void DoubleLinkedList<T>::insert_first(T x) {
    Node<T>* new_node = new Node<T>(x, nullptr, head);
    if(head) head->prev = new_node;
    else tail = new_node;
    head = new_node;
    length++;
}

template <typename T>
void DoubleLinkedList<T>::insert_last(T x) {
    Node<T>* new_node = new Node<T>(x, tail, nullptr);
    if(tail) tail->next = new_node;
    else head = new_node;
    tail = new_node;
    length++;
}

template <typename T>
void DoubleLinkedList<T>::insert_at(int idx, T x) {
    assert((idx >= 0 && idx <= (length)) && "Invalid index!");
    if (idx == 0) {
        insert_first(x);
        return;
    }
    else if(idx == (length)) {
        insert_last(x);
        return;
    }
    Node<T>* prv = head;
    for (int i = 0; i < idx - 1; ++i) prv = prv->next;
    Node<T>* nxt = prv->next;
    Node<T>* new_node = new Node<T>(x, prv, nxt);
    prv->next = new_node;
    nxt->prev = new_node;
    length++;
}


template <typename T>
bool DoubleLinkedList<T>::is_empty() {
    return (length == 0);
}

template <typename T>
void DoubleLinkedList<T>::set_at(int idx, T x) {
    assert((idx >= 0 && idx < length) && "Invalid index");
    if(idx == 0){ 
        head->val = x;
        return;
    }else if(idx == length - 1){
        tail->val = x;
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < idx; ++i) it = it->next;
    it->val = x;
}

template <typename T>
void DoubleLinkedList<T>::delete_at(int idx) {
    assert((idx >= 0 && idx < length) && "Invalid index");
    if (idx == 0 || length == 1) {
        delete_first();
        return;
    }
    if (idx == length - 1) {
        delete_last();
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < idx; ++i) {
        it = it->next;
    }
    Node<T>* prv = it->prev;
    Node<T>* nxt = it->next;
    if(prv) prv->next = nxt;
    if(nxt) nxt->prev = prv;
    delete it;
    length--;
}

template <typename T>
void DoubleLinkedList<T>::delete_first() {
    assert(!is_empty() && "The list is empty!");
    Node<T>* del = head;
    head = head->next;
    if(head) head->prev = nullptr;
    else tail = nullptr;
    delete del;
    length--;
}


template <typename T>
void DoubleLinkedList<T>::delete_last() {
    assert((!is_empty()) && "Invalid index");
    Node<T>* del = tail;
    tail = tail->prev;
    if(tail) tail->next = nullptr;
    else head = nullptr;
    delete del;
    length--;
}

template <typename T>
void DoubleLinkedList<T>::iter_seq(bool rev) {
    assert(!is_empty() && "The Array is empty!");
    Node<T>* it = rev? tail: head;
    while(it) {
        std::cout << it->val << ' ';
        it = rev? it->prev: it->next;
    }
    std::cout << '\n';
}