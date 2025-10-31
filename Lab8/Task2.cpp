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

int countTotalNodes(TourPackage* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countTotalNodes(node->left) + countTotalNodes(node->right);
}

int countLeafNodes(TourPackage* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int calculateHeight(TourPackage* node) {
    if (node == nullptr) {
        return -1;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    TourPackage* root = createPackage("Client Data Root");
    root->left = createPackage("Region North");
    root->right = createPackage("Region South");
    root->left->left = createPackage("Region A");
    root->left->right = createPackage("Region B");
    root->right->left = createPackage("Region C");
    root->left->left->left = createPackage("Client 101");
    root->left->left->right = createPackage("Client 102");
    int totalNodes = countTotalNodes(root);
    int leafNodes = countLeafNodes(root);
    int treeHeight = calculateHeight(root);
    cout << "1. Total Number of Nodes: " << totalNodes << endl;
    cout << "2. Number of Leaf Nodes:  " << leafNodes << endl;
    cout << "3. Overall Height of the Tree: " << treeHeight << endl;
    cout << "------------------------------------------------" << endl;
}
