#pragma once
#include <iostream>
#include <cassert>
/*
Linked List: is pointer based data structure that saves data in structures called nodes 
the nodes are the value saved and a pointer to the address of the next node if exist else nullptr

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
reverse(): O(n)
*/

template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node(T x = T(), Node<T>* nxt = nullptr) : val(x), next(nxt) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

    Node<T>* reverse(Node<T>* node);
public:
    LinkedList<T>();
    ~LinkedList<T>();
    
    void reverse();   
    
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
    void iter_seq();
};

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* it = head;
    while (it) {
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
}


template <typename T>
T LinkedList<T>::get_at(int idx) {
    assert((idx >= 0 && idx < length) && "Invalid index");
    Node<T>* it = head;
    if(idx == 0) return head->val;
    else if (idx == length-1) return tail->val;
    for (int i = 0; i < idx; ++i) {
        it = it->next;
    }
    return it->val;
}

template <typename T>
T LinkedList<T>::get_first() {
    assert(!is_empty() && "The List is empty");
    return head->val;
}

template <typename T>
T LinkedList<T>::get_last() {
    assert(!is_empty() && "The List is empty");
    return tail->val;
}

template <typename T>
int LinkedList<T>::len() const {
    return length;
}

template <typename T>
void LinkedList<T>::insert_first(T x) {
    Node<T>* new_node = new Node<T>(x);
    if(is_empty()) {
        head = new_node;
        tail = new_node;
        length = 1;
        return;
    }
    new_node->next = head;
    head = new_node;
    length++;
}

template <typename T>
void LinkedList<T>::insert_last(T x) {
    Node<T>* new_node = new Node<T>(x);
    if(is_empty()) {
        head = new_node;
        tail = new_node;
        length = 1;
        return;
    }

    tail->next = new_node;
    tail = tail->next;
    length++;
}

template <typename T>
void LinkedList<T>::insert_at(int idx, T x) {
    assert((idx >= 0 && idx <= (length)) && "Invalid index!");
    if (idx == 0) {
        insert_first(x);
        return;
    }
    else if(idx == (length)) {
        insert_last(x);
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < idx - 1; ++i) {
        it = it->next;
    }
    Node<T>* new_node = new Node<T>(x);
    new_node->next = it->next;
    it->next = new_node;
    length++;
}


template <typename T>
bool LinkedList<T>::is_empty() {
    return (length == 0);
}

template <typename T>
void LinkedList<T>::set_at(int idx, T x) {
    assert((idx >= 0 && idx < length) && "Invalid index");
    Node<T>* it = head;
    for (int i = 0; i < idx; ++i) {
        it = it->next;
    }
    it->val = x;
}

template <typename T>
void LinkedList<T>::delete_at(int idx) {
    assert((idx >= 0 && idx < length) && "Invalid index");
    if (idx == 0) {
        delete_first();
        return;
    }
    Node<T>* it = head;
    for (int i = 0; i < idx - 1; ++i) {
        it = it->next;
    }
    Node<T>* del = it->next;
    if(del == tail) tail = it;
    it->next = del->next;
    delete del;
    length--;
    if(is_empty()) {
        head = nullptr;
        tail = nullptr;
    }
}

template <typename T>
void LinkedList<T>::delete_first() {
    assert(!is_empty() && "Invalid index");
    Node<T>* del = head;
    head = head->next;
    length--;
    if(is_empty()) {
        head = nullptr;
        tail = nullptr;
    }
    delete del;
}

template <typename T>
void LinkedList<T>::delete_last() {
    assert((!is_empty()) && "Invalid index");
    Node<T>* it = head;
    if(length == 1) {
        delete_first();
        return;
    }
    while(it->next->next) it = it->next;
    Node<T>* del = it->next;
    it->next = nullptr;
    delete del;
    length--;
    if(is_empty()) {
        head = nullptr;
        tail = nullptr;
    }
}

template <typename T>
void LinkedList<T>::iter_seq() {
    assert(!is_empty() && "The Array is empty!");
    Node<T>* it = head;
    while(it) {
        std::cout << it->val << ' ';
        it = it->next;
    }
    std::cout << '\n';
}

template <typename T>
void LinkedList<T>::reverse() {
    if(length <= 1) return;
    reverse(head);
    Node<T>* tmp = head;
    head = tail;
    tail = tmp;
}

template <typename T>
Node<T>* LinkedList<T>::reverse(Node<T>* node) {
    if(!node->next) return node;
    Node<T>* tmp = reverse(node->next);
    tmp->next = node;
    node->next = nullptr;
    return node;
}