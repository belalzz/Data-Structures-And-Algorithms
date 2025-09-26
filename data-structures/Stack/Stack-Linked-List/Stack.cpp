#include <iostream>
#include <cassert>
#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack():Top{nullptr}, Size{0}{}

template <typename T>
Stack<T>::~Stack(){
    Node<T>* it = Top;
    while (it){
        Node<T>* del = it;
        it = it->next;
        delete del;
    }
    Size = 0;
    Top = nullptr;
}

template <typename T>
void Stack<T>::push(T x) {
    if(Size == 0){
        Top = new Node<T>(x);
        Size++;
        return;
    }
    Node<T>* newNode = new Node<T>(x, Top);
    Top = newNode;
    Size++;
}

template <typename T>
void Stack<T>::pop(){
    assert(Size > 0 && "The stack is Empty!");
    Node<T>* del = Top;
    Top = Top->next;
    delete del;
    Size--;
}

template <typename T>
const T Stack<T>::top(){
    assert(Size > 0 && "The Stack is Empty!");
    return Top->val;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return Size == 0;
}
template <typename T>
int Stack<T>::size(){
    return Size;
}