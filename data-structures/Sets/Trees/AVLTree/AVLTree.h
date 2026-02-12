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
    int height;
    Node<T>(T x = T(), Node<T>* l = nullptr, Node<T>* r = nullptr, int h = 1): val(x), left(l), right(r), height(h){}
};

template <typename T>
struct AVLTree {
private:
    Node<T>* root;
    int length;
    
    // helper functions
    Node<T>* find(Node<T>* node, T val);
    Node<T>* get_max(Node<T>* node);
    
    void dfs(Node<T>* node);
    
    void in_order(Node<T>* node);
    void pre_order(Node<T>* node);
    void post_order(Node<T>* node);

    int getHeight(Node<T>* node);
    int getBalance(Node<T>* node);
    
    Node<T>* rightRotation(Node<T>* node);
    Node<T>* leftRotation(Node<T>* node);
    
    Node<T>* remove(Node<T>* node, T val);
    Node<T>* insert(Node<T>* node, T val);
    void delete_tree(Node<T>* node);
public:
    AVLTree<T>();
    ~AVLTree<T>();

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
AVLTree<T>::AVLTree() {
    root = nullptr;
    length = 0;
}

template <typename T>
AVLTree<T>::~AVLTree() {
    delete_tree(root);
}

template <typename T>
void AVLTree<T>::delete_tree(Node<T>* node) {
    if(!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <typename T>
int AVLTree<T>::size() {
    return length;
}

template <typename T>
bool AVLTree<T>::is_empty() {
    return length == 0;
}

template <typename T>
bool AVLTree<T>::find(T val) {
    return find(root, val);
}

template <typename T>
Node<T>* AVLTree<T>::find(Node<T>* node, T val) {
    if(!node) return nullptr;
    if(node->val == val) return node;
    if(node->val > val) return find(node->left, val);
    else return find(node->right, val);
}

template <typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, T val) {
    if(!node) {
        length++;
        return new Node<T>(val);
    }
    if(val < node->val) {
        node->left = insert(node->left, val);
    }else if(val > node->val) {
        node->right = insert(node->right, val);
    } else return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int b_f = getBalance(node);
    // case LL
    if(b_f > 1 && node->left->val > val) {
        return rightRotation(node);
    }
    
    // case LR
    if(b_f > 1 && node->left->val < val) {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    
    // case RR
    if(b_f < -1 && node->right->val < val) {
        return leftRotation(node);
    }
    
    // case RL
    if(b_f < -1 && node->right->val > val) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    return node;
}
template <typename T>
void AVLTree<T>::insert(T val) {
    root = insert(root, val);
}
template <typename T>
void AVLTree<T>::dfs(Node<T>* node) {
    if(!node) return;
    std::cout << node->val << ' ';
    dfs(node->left);
    dfs(node->right);
}

template <typename T>
void AVLTree<T>::dfs() {
    dfs(root);
    std::cout << '\n';
}

template <typename T>
void AVLTree<T>::bfs() {
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
Node<T>* AVLTree<T>::get_max(Node<T>* node) {
    if(node && node->right) return get_max(node->right);
    return node;
}


template <typename T>
void AVLTree<T>::remove(T val) {
    root = remove(root, val);
}

template <typename T>
Node<T>* AVLTree<T>::remove(Node<T>* node, T val) {
    if (!node) return nullptr;

    if (val < node->val) {
        node->left = remove(node->left, val);
    }
    else if (val > node->val) {
        node->right = remove(node->right, val);
    }
    else {
        // leaf node
        if(!node->left && !node->right) {
            delete node;
            length--;
            return nullptr;
        }

        // has one child
        if(node->left && !node->right) {
            Node<T>* tmp = node->left;
            delete node;
            length--;
            return tmp;
        }
        
        if(node->right && !node->left) {
            Node<T>* tmp = node->right;
            delete node;
            length--;
            return tmp;
        }

        Node<T>* maxNode = get_max(node->left);
        node->val = maxNode->val;
        node->left = remove(node->left, maxNode->val);
    }
    if (!node) return node;
    
    node->height = 1 + std::max(getHeight(node->left),
                                getHeight(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotation(node);

    // LR
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    // RR
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotation(node);

    // RL
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

template <typename T>
void AVLTree<T>::in_order(Node<T>* node) {
    if(!node) return;
    in_order(node->left);
    std::cout << node->val << ' ';
    in_order(node->right);
}

template <typename T>
void AVLTree<T>::post_order(Node<T>* node) {
    if(!node) return ;
    post_order(node->left);
    post_order(node->right);
    std::cout << node->val << ' ';
}

template <typename T>
void AVLTree<T>::pre_order(Node<T>* node) {
    if(!node) return ;
    std::cout << node->val << ' ';
    pre_order(node->left);
    pre_order(node->right);
}

template <typename T>
void AVLTree<T>::in_order() {
    in_order(root);
}

template <typename T>
void AVLTree<T>::pre_order() {
    pre_order(root);
}

template <typename T>
void AVLTree<T>::post_order() {
    post_order(root);
}

template <typename T>
int AVLTree<T>::getHeight(Node<T>* node) {
    return node? node->height: 0;
}

template <typename T>
int AVLTree<T>::getBalance(Node<T>* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

template <typename T>
Node<T>* AVLTree<T>::rightRotation(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    return x;
}


template <typename T>
Node<T>* AVLTree<T>::leftRotation(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    return y;
}
