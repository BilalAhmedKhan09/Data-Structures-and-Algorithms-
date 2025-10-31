#include <iostream>
#include <string>

using namespace std;

struct ProductNode {
    int productID;
    int quantity;
    ProductNode* left;
    ProductNode* right;

    ProductNode(int id, int qty) : productID(id), quantity(qty), left(nullptr), right(nullptr) {}
};

ProductNode* createProduct(int id, int qty) {
    return new ProductNode(id, qty);
}

ProductNode* insertProduct(ProductNode* root, int id, int qty) {
    if (root == nullptr) {
        return createProduct(id, qty);
    }

    if (id < root->productID) {
        root->left = insertProduct(root->left, id, qty);
    } else if (id > root->productID) {
        root->right = insertProduct(root->right, id, qty);
    } else {
        root->quantity += qty;
    }

    return root;
}

ProductNode* searchProduct(ProductNode* root, int id) {
    if (root == nullptr || root->productID == id) {
        return root;
    }

    if (id < root->productID) {
        return searchProduct(root->left, id);
    } else {
        return searchProduct(root->right, id);
    }
}

void findMaxQuantity(ProductNode* root, ProductNode*& maxNode) {
    if (root == nullptr) {
        return;
    }

    if (maxNode == nullptr || root->quantity > maxNode->quantity) {
        maxNode = root;
    }

    findMaxQuantity(root->left, maxNode);
    findMaxQuantity(root->right, maxNode);
}

int main() { 
    ProductNode* inventoryRoot = nullptr;
     inventoryRoot = insertProduct(inventoryRoot, 50, 10);
    inventoryRoot = insertProduct(inventoryRoot, 30, 15);
    inventoryRoot = insertProduct(inventoryRoot, 70, 8);
    inventoryRoot = insertProduct(inventoryRoot, 20, 25);
    inventoryRoot = insertProduct(inventoryRoot, 40, 5);
    inventoryRoot = insertProduct(inventoryRoot, 60, 12);
    inventoryRoot = insertProduct(inventoryRoot, 80, 4);
    int updateID = 30;
    int addedQty = 5;
    cout << "\nOperation: Adding " << addedQty << " units to Product ID " << updateID << "." << endl;
    inventoryRoot = insertProduct(inventoryRoot, updateID, addedQty);
    int searchID = 40;
    ProductNode* searchResult = searchProduct(inventoryRoot, searchID);
    if (searchResult != nullptr) {
        cout << "Search result for ID " << searchID << ": Found! Quantity in stock: " << searchResult->quantity << endl;
    } else {
        cout << "Search result for ID " << searchID << ": Not found." << endl;
    }
    int missingID = 99;
    searchResult = searchProduct(inventoryRoot, missingID);
    if (searchResult != nullptr) {
        cout << "Search result for ID " << missingID << ": Found! Quantity in stock: " << searchResult->quantity << endl;
    } else {
        cout << "Search result for ID " << missingID << ": Not found." << endl;
    }
 
    ProductNode* maxQtyNode = nullptr;
    findMaxQuantity(inventoryRoot, maxQtyNode);
    cout << "\n--- Inventory Snapshot ---" << endl;
    if (maxQtyNode != nullptr) {
        cout << "Product with the HIGHEST quantity in stock:" << endl;
        cout << "  -> Product ID: " << maxQtyNode->productID << endl;
        cout << "  -> Quantity:   " << maxQtyNode->quantity << endl;
    } 
    else {
        cout << "Inventory is empty." << endl;
    }
}
 
