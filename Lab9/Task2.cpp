#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node *root;
    int height(Node *N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    void updateHeight(Node *N) {
        N->height = 1 + max(height(N->left), height(N->right));
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node *insert(Node *node, int key) {
        if (node == nullptr)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else{
            return node;
        }
        updateHeight(node);
        return node;
    }

    void inOrder(Node *root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }
    void displayTree() {
        if (root == nullptr) {
            cout << "The tree is empty.\n";
            return;
        }
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << "\n";
    }
};

int main() {
    AVLTree tree;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < n; i++) {
        tree.insert(elements[i]);
    }
    cout << "Initial AVL Tree Structure";
    tree.displayTree();
    tree.insert(55);
    cout << "Tree after insertion of 55:\n";
    tree.displayTree();
}