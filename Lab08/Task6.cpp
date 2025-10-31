#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ProductNode {
    int productID;
    int quantity;
    ProductNode* left;
    ProductNode* right;

    ProductNode(int id, int qty = 0) : productID(id), quantity(qty), left(nullptr), right(nullptr) {}
};

ProductNode* createProduct(int id, int qty = 0) {
    return new ProductNode(id, qty);
}

ProductNode* insertProduct(ProductNode* root, int id) {
    if (root == nullptr) {
        return createProduct(id);
    }
    if (id < root->productID) {
        root->left = insertProduct(root->left, id);
    } else if (id > root->productID) {
        root->right = insertProduct(root->right, id);
    }
    return root;
}

ProductNode* findLCA(ProductNode* root, int n1, int n2) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->productID > n1 && root->productID > n2) {
        return findLCA(root->left, n1, n2);
    }
    if (root->productID < n1 && root->productID < n2) {
        return findLCA(root->right, n1, n2);
    }
    return root;
}

int main() {
    ProductNode* employeeHierarchy = nullptr;
    employeeHierarchy = insertProduct(employeeHierarchy, 50);
    employeeHierarchy = insertProduct(employeeHierarchy, 30);
    employeeHierarchy = insertProduct(employeeHierarchy, 70);
    employeeHierarchy = insertProduct(employeeHierarchy, 20);
    employeeHierarchy = insertProduct(employeeHierarchy, 40);
    employeeHierarchy = insertProduct(employeeHierarchy, 60);
    employeeHierarchy = insertProduct(employeeHierarchy, 80);
    employeeHierarchy = insertProduct(employeeHierarchy, 25);
    employeeHierarchy = insertProduct(employeeHierarchy, 45);
    int id1 = 25;
    int id2 = 45;
    ProductNode* lcaNode = findLCA(employeeHierarchy, id1, id2);
    cout << "\nFinding LCA (Closest Common Manager):" << endl;
    cout << "Employee 1 ID: " << id1 << endl;
    cout << "Employee 2 ID: " << id2 << endl;
    if (lcaNode != nullptr) {
        cout << "LCA (Common Manager) ID: " << lcaNode->productID << endl;
    } else {
        cout << "LCA not found for the given IDs" << endl;
    } 
    id1 = 60;
    id2 = 80;
    lcaNode = findLCA(employeeHierarchy, id1, id2);

    cout << "\nFinding LCA:" << endl;
    cout << "Employee 1 ID: " << id1 << endl;
    cout << "Employee 2 ID: " << id2 << endl;
    if (lcaNode != nullptr) {
        cout << "LCA (Common Manager) ID: " << lcaNode->productID << endl;
    } else {
        cout << "LCA not found for the given IDs" << endl;
    }
    id1 = 20;
    id2 = 80;
    lcaNode = findLCA(employeeHierarchy, id1, id2);
    cout << "\nFinding LCA:" << endl;
    cout << "Employee 1 ID: " << id1 << endl;
    cout << "Employee 2 ID: " << id2 << endl;
    if (lcaNode != nullptr) {
        cout << "LCA ID: " << lcaNode->productID << endl;
    } else {
        cout << "LCA not found for the given IDs" << endl;
    }
}
