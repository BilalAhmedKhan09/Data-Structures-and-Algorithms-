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

void displayHierarchy(TourPackage* node, int depth) {
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < depth; ++i) {
        cout << "  |";
    }
    cout << "--" << node->packageName << endl;
    displayHierarchy(node->left, depth + 1);
    displayHierarchy(node->right, depth + 1);
}

int main() {
    TourPackage* root = createPackage("World Adventures (Root)");
    root->left = createPackage("European Tours");
    root->right = createPackage("Asian Destinations");
    root->left->left = createPackage("Western Europe");
    root->left->right = createPackage("Mediterranean Cruises");
    root->right->left = createPackage("Southeast Asia Backpacking");
    root->right->right = createPackage("Himalayan");
    root->left->left->left = createPackage("Paris-Rome Express");
    root->left->right->right = createPackage("Greek Island Hopping");
    root->right->left->right = createPackage("Thailand & Vietnam");
    root->right->right->left = createPackage("Everest Base Camp");
    cout << "Hierarchical View (Pre-order Traversal):\n" << endl;
    displayHierarchy(root, 0);
}
