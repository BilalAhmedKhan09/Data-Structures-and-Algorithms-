#include<iostream>
#include<vector>

using namespace std;

struct Node{
    Node *left;
    Node *right;
    int val;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void pathsum(Node *root, int k, vector<int>&path){
    if(root == nullptr) return;

    path.push_back(root->val);
    
    int sum = 0;
    for(int i = path.size()-1; i>=0;i--){
        sum += path[i];
        if(sum == k){
            for(int j=i;j<path.size();j++){
                cout<<path[j]<<"->";
            }
            cout<<endl;
        }
    }
    pathsum(root->left, k,path);
    pathsum(root->right,k,path);
    path.pop_back();
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(1);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right->right = new Node(6);
    
    cout << "Paths that sum to 5:" << endl;
    vector<int> path;
    pathsum(root, 5, path);
}