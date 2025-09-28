#include "BST.h"
#include <iostream>
#include <cassert>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
BST<T>::BST()
{
    root = nullptr;
    Size = 0;
}

template <typename T>
BST<T>::~BST()
{
    clear(root);
    root = nullptr;
    Size = 0;
}

template <typename T>
Node<T> *BST<T>::getRoot(void)
{
    return root;
}

template <typename T>
void BST<T>::clear(Node<T> *node)
{
    if (node == nullptr)
        return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template <typename T>
void BST<T>::insert(T data)
{
    if (root == nullptr)
    {
        root = new Node<T>(data);
        Size = 1;
        return;
    }
    if (search(data))
        return;
    Node<T> *it = root;
    while (it)
    {
        if (data < it->data)
        {
            if (it->left == nullptr)
            {
                it->left = new Node(data);
                Size++;
                return;
            }
            it = it->left;
        }
        else if (data > it->data)
        {
            if (it->right == nullptr)
            {
                it->right = new Node(data);
                Size++;
                return;
            }
            it = it->right;
        }
        else
        {
            return;
        }
    }
}

template <typename T>
void BST<T>::remove(T data)
{
    if (!search(data))
        return;
    remove(root, data);
}
template <typename T>
Node<T>* BST<T>::remove(Node<T>* node, T data) {
    if (node == nullptr)
        return node;
    else if (data < node->data) {
        node->left = remove(node->left, data);
    }
    else if (data > node->data) {
        node->right = remove(node->right, data);
    }
    else {
        // Case 1: no children
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
            Size--;
        }
        // Case 2: only right child
        else if (!node->left) {
            Node<T>* del = node;
            node = node->right;
            delete del;
            Size--;
        }
        // Case 3: only left child
        else if (!node->right) {
            Node<T>* del = node;
            node = node->left;
            delete del;
            Size--;
        }
        // Case 4: two children
        else {
            Node<T>* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data);
        }
    }
    return node;
}


template <typename T>
bool BST<T>::search(T data)
{
    if (root == nullptr)
        return false;
    Node<T> *it = root;
    while (it)
    {
        if (data == it->data)
            return true;
        else if (data < it->data)
        {
            it = it->left;
        }
        else if (data > it->data)
        {
            it = it->right;
        }
    }
    return false;
}

template <typename T>
int BST<T>::size()
{
    return Size;
}

template <typename T>
bool BST<T>::isEmpty(void)
{
    return Size == 0;
}

template <typename T>
Node<T> *BST<T>::findMin(Node<T> *node)
{
    if (node == nullptr)
        return nullptr;
    Node<T> *it = node;
    while (it->left)
    {
        it = it->left;
    }
    return it;
}

template <typename T>
Node<T> *BST<T>::findMax(Node<T> *node)
{
    if (node == nullptr)
        return nullptr;
    Node<T> *it = node;
    while (it->right)
    {
        it = it->right;
    }
    return it;
}

template <typename T>
int BST<T>::height(Node<T> *node)
{
    if (node == nullptr)
        return -1;
    return 1 + max(height(node->left), height(node->right));
}
template <typename T>
void BST<T>::breadthFirstTraversal(void)
{
    queue<Node<T> *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node<T> *cur = q.front();
        cout << cur->data << ' ';
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
        q.pop();
    }
}

template <typename T>
void BST<T>::depthFirstTraversal(void)
{
    stack<Node<T> *> st;
    if (root)
        st.push(root);
    while (!st.empty())
    {
        Node<T> *cur = st.top();
        cout << cur->data << ' ';
        st.pop();
        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);
    }
}

template <typename T>
void BST<T>::inOrderTraversal(Node<T> *node)
{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

template <typename T>
void BST<T>::preOrderTraversal(Node<T> *node)
{
    if (node == nullptr)
        return;
    cout << node->data << ' ';
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

template <typename T>
void BST<T>::postOrderTraversal(Node<T> *node)
{
    if (node == nullptr)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << ' ';
}