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
    if(idx == 0) return head->val;
    if(idx == length - 1) return tail->val;

    Node<T>* it = head;
    if (length - idx > idx) {
        for (int i = 0; i < idx; ++i) {
            it = it->next;
        }
    } else {
        for (int i = 0; i < length - idx - 1; ++i) {
            it = it->prev;
        }
    }
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
    if(is_empty()) {
        Node<T>* new_node = new Node<T>(x);
        head = new_node;
        tail = new_node;
        length = 1;
        return;
    }
    Node<T>* new_node = new Node<T>(x, nullptr, head);
    if(head) head->prev = new_node;
    head = new_node;
    if(!tail) tail = head;
    length++;
}

template <typename T>
void DoubleLinkedList<T>::insert_last(T x) {
    if(is_empty()) {
        Node<T>* new_node = new Node<T>(x);
        head = new_node;
        tail = new_node;
        length = 1;
        return;
    }
    Node<T>* new_node = new Node<T>(x, tail, nullptr);
    if(tail) tail->next = new_node;
    tail = new_node;
    if(!head) head = tail;
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
    Node<T>* it = head;
    if (length - idx > idx) {
        for (int i = 0; i < idx; ++i) {
            it = it->next;
        }
    } else {
        for (int i = 0; i < length - idx; ++i) {
            it = it->prev;
        }
    }
    Node<T>* next_node = it;
    Node<T>* prev_node = it->prev;
    Node<T>* new_node = new Node<T>(x, prev_node, next_node);
    if(prev_node) prev_node->next = new_node;
    next_node->prev = new_node;
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
    if (length - idx > idx) {
        for (int i = 0; i < idx; ++i) {
            it = it->next;
        }
    } else {
        for (int i = 0; i < length - idx - 1; ++i) {
            it = it->prev;
        }
    }
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
    if (length - idx > idx) {
        for (int i = 0; i < idx; ++i) {
            it = it->next;
        }
    } else {
        for (int i = 0; i < length - idx; ++i) {
            it = it->prev;
        }
    }
    Node<T>* del = it;
    Node<T>* prev_node = del->prev;
    Node<T>* next_node = del->next;
    if(prev_node) prev_node->next = next_node;
    else head = next_node;
    if(next_node) next_node->prev = prev_node;
    else tail = prev_node;
    delete del;
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