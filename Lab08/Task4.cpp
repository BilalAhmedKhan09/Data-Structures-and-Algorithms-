#include <iostream>
#include <string>

using namespace std;

struct TourPackage {
    int quantity;
    TourPackage* left;
    TourPackage* right;

    TourPackage(int value) : quantity(value), left(nullptr), right(nullptr) {}
};

TourPackage* createPackage(int quantity) {
    return new TourPackage(quantity);
}

TourPackage* foundSubtreeRoot = nullptr;

int checkSubtreeSum(TourPackage* node, int targetSum) {
    if (node == nullptr) {
        return 0;
    }
    int leftSum = checkSubtreeSum(node->left, targetSum);
    int rightSum = checkSubtreeSum(node->right, targetSum);
    int currentSubtreeSum = node->quantity + leftSum + rightSum;
    if (currentSubtreeSum == targetSum && foundSubtreeRoot == nullptr) {
        foundSubtreeRoot = node;
    }   
    return currentSubtreeSum;
}

void displaySubtree(TourPackage* node, int level) {
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < level; ++i) {
        cout << "  ";
    }
    cout << "|-- " << node->quantity << endl;
    displaySubtree(node->left, level + 1);
    displaySubtree(node->right, level + 1);
}

int main() { 
    const int TARGET_SUM = 15;   
    TourPackage* root = createPackage(8); 
    root->left = createPackage(5); 
    root->right = createPackage(3);
    root->left->left = createPackage(2); 
    root->left->right = createPackage(7); 
    root->right->left = createPackage(1); 
    root->right->right = createPackage(4); 
    root->right->right->left = createPackage(6); 
    root->right->right->right = createPackage(5);  
    foundSubtreeRoot = nullptr;  
    checkSubtreeSum(root, TARGET_SUM);   
    cout << "Target Subtree Sum: " << TARGET_SUM << endl;
    if (foundSubtreeRoot != nullptr) {
        cout << "Subtree found whose total quantity equals " << TARGET_SUM << "." << endl;
        cout << "Root of the matching subtree has quantity: " << foundSubtreeRoot->quantity << endl;
        cout << "\nStructure of the matching subtree:\n" << endl;
        displaySubtree(foundSubtreeRoot, 0);
    } 
    else {
        cout << "No subtree found whose sum of all nodes is equal to " << TARGET_SUM << "." << endl;
    }
}
