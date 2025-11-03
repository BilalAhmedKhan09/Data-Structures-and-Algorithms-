#include<iostream>

using namespace std;

struct Node{
    Node *left;
    Node *right;
    int val;
};

Node* insert(Node *root, int val){
    if(root == NULL){
        root = new Node;
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(val < root->val){
        root->left = insert(root->left,val);
    }
    else if(val > root->val){
        root->right = insert(root->right, val);
    }
    return root;
}

Node *search(Node *root, int val){
    if(root == NULL){
        return NULL;
    }
    else if(val < root->val){
        return search(root->left, val);
    }
    else if(val > root->val){
        return search(root->right, val);
    }
    else{
        cout<<root->val<<endl;
        return root;
    }
}

Node *minimum(Node *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left == NULL){
        return root;
    }
    return minimum(root->left);
}

Node *maximum(Node *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->right == NULL){
        return root;
    }
    return minimum(root->right);
}

Node *Del(Node *root, int val){
    if (root == NULL) {
        return NULL;
    }
    if (val < root->val) {
        root->left = Del(root->left, val);
    } 
    else if (val > root->val) {
        root->right = Del(root->right, val);
    } 
    else {
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minimum(root->right); 
        root->val = temp->val; 
        root->right = Del(root->right, temp->val);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->val<<", ";
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    cout << "--- 1. Insertion Test ---" << endl;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    inorder(root);
    cout<<endl;
    cout << "--- 2. Search Test ---" << endl;
    search(root, 40);
    if (search(root, 99) == NULL) {
        cout << "99 not found." << endl;
    }
    cout << endl;
    cout << "--- 3. Min/Max Test ---" << endl;
    cout << "Minimum value: " << minimum(root)->val << endl;
    cout << "Maximum value: " << maximum(root)->val << endl;
    cout << endl; 
    cout << "--- 4. Deletion Test ---" << endl;
    cout << "Deleting leaf node 20..." << endl;
    root = Del(root, 20);
    inorder(root);
    cout<<endl;
    cout << "Deleting node 70 (one child)..." << endl;
    root = Del(root, 70);
    inorder(root);
    cout<<endl;
    cout << "Deleting root node 50 (two children)..." << endl;
    root = Del(root, 50);
    inorder(root);
    cout<<endl;
    cout << "Deletion operations complete." << endl;
}