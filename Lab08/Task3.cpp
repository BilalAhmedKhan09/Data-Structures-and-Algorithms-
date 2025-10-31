#include <iostream>
#include <string>

using namespace std;

struct TourPackage {
    string packageName;
    TourPackage* left;
    TourPackage* right;

    TourPackage(string name) : packageName(name), left(nullptr), right(nullptr) {}
};

TourPackage* createPackage(string name) {
    return new TourPackage(name);
}

bool isFullBinaryTree(TourPackage* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return true;
    }
    if (node->left != nullptr && node->right != nullptr) {
        return isFullBinaryTree(node->left) && isFullBinaryTree(node->right);
    }
    return false;
}

int main() {
    TourPackage* root = createPackage("Level 1 (Root)");
    root->left = createPackage("Level 2-A");
    root->right = createPackage("Level 2-B");
    root->left->left = createPackage("Level 3-A");
    root->left->right = createPackage("Level 3-B");
    root->right->left = createPackage("Level 3-C");
    root->right->right = createPackage("Level 3-D");
    bool isFull = isFullBinaryTree(root);
    if (isFull) {
        cout << "The constructed tree is a Full Binary Tree." << endl;
        cout << "Progression is symmetrically balanced (Every node has 0 or 2 children)." << endl;
    } 
    else {
        cout << "The constructed tree is NOT a Full Binary Tree." << endl;
        cout << "Progression is NOT symmetrically balanced." << endl;
    }
}

//I did not change the name of the tree because it was simpler to do it like this