#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void bfs(Node *root){
    queue<Node*> q;
    q.push(root);
    while(q.size() != 0){
        Node *front = q.front();
        q.pop();
        cout<<front->val<<endl;
        if (front->left) {
            q.push(front->left);
        }
        if (front->right) {
            q.push(front->right);
        }
    }
}

int main() {
    Node* root = new Node(14);
    root->left = new Node(34);
    root->right = new Node(27);
    root->left->left = new Node(40);
    root->left->right = new Node(37);
    root->right->left = new Node(54);
    root->right->right = new Node(30);
    
    cout << "BFS Traversal: "<<endl;
    bfs(root);
}