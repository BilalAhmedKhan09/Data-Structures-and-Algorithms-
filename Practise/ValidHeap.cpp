#include<iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void treeToArray(Node* root, vector<int>& arr, int index) {
    if (!root) return;
    
    // Expand array if needed
    if (index >= arr.size()) {
        arr.resize(index + 1, -1);
    }
    
    arr[index] = root->val;
    treeToArray(root->left, arr, 2 * index + 1);
    treeToArray(root->right, arr, 2 * index + 2);
}

int heightOfValidMinHeap(Node* root) {
    if (!root) return 0;

    vector<int> arr;
    treeToArray(root, arr, 0);
    
    int height = 1;
    int levelend = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        if(i>levelend){
            height++;
            levelend = 2*levelend + 2;
        }
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < arr.size() && arr[left] != -1 && right < arr.size() && arr[right] != -1){
            if (arr[i] > arr[left]) {
                return height;
            }
            if (arr[i] > arr[right]) {
                return height;
            }
        }
    }
    return height;
}

int main() {
    Node* root = new Node(14);
    root->left = new Node(34);
    root->right = new Node(27);
    root->left->left = new Node(40);
    root->left->right = new Node(37);
    root->right->left = new Node(54);
    root->right->right = new Node(30);
    root->left->left->left = new Node(13);
    root->left->left->right = new Node(50);
    root->left->right->left = new Node(21);
    root->left->right->right = new Node(39);
    root->right->left->left = new Node(56);
    root->right->left->right = new Node(89);
    
    cout<< "Height of valid min heap: " << heightOfValidMinHeap(root) << endl;
    
    return 0;
}