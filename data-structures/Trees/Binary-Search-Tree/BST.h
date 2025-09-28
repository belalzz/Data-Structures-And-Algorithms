#pragma once

template <typename T>
class Node{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
class BST{
private:
    Node<T>* root;
    int Size;
    void clear(Node<T>* node);
    Node<T>* findMin(Node<T>* node);
    Node<T>* findMax(Node<T>* node);
    Node<T>* remove(Node<T>* node, T data);
    public:
    BST();
    ~BST();
    Node<T>* getRoot(void);
    int height(Node<T>* node);
    void insert(T data);
    void remove(T data);
    bool search(T data);
    int size(void);
    bool isEmpty(void);
    void breadthFirstTraversal(void);
    void depthFirstTraversal(void);
    void inOrderTraversal(Node<T>* node);
    void preOrderTraversal(Node<T>* node);
    void postOrderTraversal(Node<T>* node);
};