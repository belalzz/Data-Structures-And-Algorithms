#include <iostream>
#include <queue>
/*
Binary Tree: is a pointer based and non-linear data structure,
The tree that:
1. has only one root (a node with no parents),
2. each node has atmost 2 children nodes
3. there is only 1 path b/w the root and any other node in the tree.
*/

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>(T x = T(), Node<T>* l = nullptr, Node<T>* r = nullptr): val(x), left(l), right(r){}
};

template <typename T>
struct BST {
private:
    Node<T>* root;
    int length;
    
    // helper functions
    Node<T>* find(Node<T>* node, T val);
    Node<T>* find_p(Node<T>* node, T val);
    Node<T>* get_max(Node<T>* node);
    
    void dfs(Node<T>* node);
    
    void in_order(Node<T>* node);
    void pre_order(Node<T>* node);
    void post_order(Node<T>* node);
    
    void remove(Node<T>* node, T val);
    void delete_tree(Node<T>* node);
public:
    BST<T>();
    ~BST<T>();

    int size();
    bool find(T val);
    bool is_empty();

    void insert(T val);
    void remove(T val);
    
    void dfs();
    void bfs();

    void in_order();
    void post_order();
    void pre_order();
};


template <typename T>
BST<T>::BST() {
    root = nullptr;
    length = 0;
}

template <typename T>
BST<T>::~BST() {
    delete_tree(root);
}

template <typename T>
void BST<T>::delete_tree(Node<T>* node) {
    if(!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <typename T>
int BST<T>::size() {
    return length;
}

template <typename T>
bool BST<T>::is_empty() {
    return length == 0;
}

template <typename T>
bool BST<T>::find(T val) {
    return find(root, val);
}

template <typename T>
Node<T>* BST<T>::find(Node<T>* node, T val) {
    if(!node) return nullptr;
    if(node->val == val) return node;
    if(node->val > val) return find(node->left, val);
    else return find(node->right, val);
}

template <typename T>
Node<T>* BST<T>::find_p(Node<T>* node, T val) {
    if(!node) return nullptr;
    if(node->left && node->left->val == val) return node;
    if(node->right && node->right->val == val) return node;
    if(val < node->val && node->left) return find_p(node->left, val);
    if(val > node->val && node->right) return find_p(node->right, val);
    return nullptr;
}

template <typename T>
void BST<T>::insert(T val) {
    if(!root) {
        root = new Node<T>(val, nullptr, nullptr);
        length++;
        return;
    }
    Node<T>* it = root;
    Node<T>* prv = root;
    bool isRight = true;
    while(it) {
        prv = it;
        if(it->val == val) return;
        else if(it->val < val) {
            it = it->right;
            isRight = true;
        }else {
            it = it->left;
            isRight = false;
        }
    }
    if(isRight) prv->right = new Node<T>(val);
    else prv->left = new Node<T>(val);
    length++;
}

template <typename T>
void BST<T>::dfs(Node<T>* node) {
    if(!node) return;
    std::cout << node->val << ' ';
    dfs(node->left);
    dfs(node->right);
}

template <typename T>
void BST<T>::dfs() {
    dfs(root);
    std::cout << '\n';
}

template <typename T>
void BST<T>::bfs() {
    if(!root) return;
    std::queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        Node<T>* cur = q.front();
        q.pop();
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
        std::cout << cur->val << ' ';
    }
    std::cout << '\n';
}

template <typename T>
Node<T>* BST<T>::get_max(Node<T>* node) {
    if(node && node->right) return get_max(node->right);
    return node;
}


template <typename T>
void BST<T>::remove(T val) {
    remove(root, val);
}

template <typename T>
void BST<T>::remove(Node<T>* node, T val) {
    Node<T>* to_del = find(node, val);
    if(!to_del) return;

    // node has two children
    if(to_del->left && to_del->right) {
        Node<T>* max_l_node = get_max(to_del->left);
        T tmp = max_l_node->val;
        remove(root, max_l_node->val);
        to_del->val = tmp;
        return;
    }

    // node has one child
    Node<T>* parent = find_p(root, val);
    if(!parent) {
        if(root->left) root = root->left;
        else if(root->right) root = root->right;
        else root = nullptr;
    }
    else if(parent->left || parent->right) {
        if(parent->left == to_del) {
            parent->left = (to_del->left? to_del->left: to_del->right);
        } else if (parent->right == to_del) {
            parent->right = (to_del->right? to_del->right: to_del->left);
        }
    } else {
        if(parent->left == to_del) {
            parent->left = nullptr;
        } else if (parent->right == to_del) {
            parent->right = nullptr;
        }
    }
    delete to_del;
    length--;
}

template <typename T>
void BST<T>::in_order(Node<T>* node) {
    if(!node) return;
    in_order(node->left);
    std::cout << node->val << ' ';
    in_order(node->right);
}

template <typename T>
void BST<T>::post_order(Node<T>* node) {
    if(!node) return ;
    post_order(node->left);
    post_order(node->right);
    std::cout << node->val << ' ';
}

template <typename T>
void BST<T>::pre_order(Node<T>* node) {
    if(!node) return ;
    std::cout << node->val << ' ';
    pre_order(node->left);
    pre_order(node->right);
}

template <typename T>
void BST<T>::in_order() {
    in_order(root);
}

template <typename T>
void BST<T>::pre_order() {
    pre_order(root);
}

template <typename T>
void BST<T>::post_order() {
    post_order(root);
}