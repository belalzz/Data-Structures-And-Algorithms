#include "Queue.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
Queue<T>::Queue(): head{nullptr}, tail{nullptr}, Size{0} {}

template <typename T>
Queue<T>::~Queue(){
    while(!isEmpty()){
        pop();
    }
}
template <typename T>
void Queue<T>::push(const T& x){
    if(isEmpty()){
        head = new Node(x);
        tail = head;
        Size++;
        return;
    }
    Node<T>* newNode = new Node(x);
    tail->next = newNode;
    tail = newNode;
    Size++;
}

template <typename T>
void Queue<T>::pop(void){
    assert(Size > 0 && "Queue is Empty!!");
    Node<T>* del = head;
    head = head->next;
    delete del;
    Size--;
}

template <typename T>
bool Queue<T>::isEmpty(void) const{
    return Size == 0;
}

template <typename T>
int Queue<T>::size(void) const{
    return Size;
}

template <typename T>
const T& Queue<T>::front(void) const{
    assert(Size > 0 && "Queue is Empty!!");
    return head->val;
}

template <typename T>
const T& Queue<T>::back(void) const{
    assert(Size > 0 && "Queue is Empty!!");
    return tail->val;
}
