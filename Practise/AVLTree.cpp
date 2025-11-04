#include<iostream>


using namespace std;

struct Node {
    int val;
    int height;
    Node *left;
    Node *right;
};

int getheight(Node *n){
    if(n == NULL){
        return 0;
    }
    else{
        return n->height;    
    }
}

Node * newnode(int key){
    Node *n = new Node;
    n->height = 1;
    n->val = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int getbalancefactor(Node *n){
    if(n == NULL){
        return 0;
    }
    else{
        return getheight(n->left) - getheight(n->right);
    }
}

int max (int a , int b){
    return a>b?a:b;
}

Node *leftrotate(Node *b){
    Node *d = b->right;
    Node *c = d->left;
    
    d->left = b;
    b->right = c;
    b->height = 1 + max(getheight(b->left), getheight(b->right));
    d->height = 1 + max(getheight(d->left), getheight(d->right));
    return d;
}

Node *rightrotate(Node *d){
    Node *b = d->left;
    Node *c = b->right;
    
    b->right = d;
    d->left = c;
    b->height = 1 + max(getheight(b->left), getheight(b->right));
    d->height = 1 + max(getheight(d->left), getheight(d->right));
    return b;
}

Node *Insert(Node*n, int key){
    if(n == NULL){
       return newnode(key);
    }
    else if(key < n->val){
        n->left = Insert(n->left, key);
    }
    else if(key > n->val){
        n->right = Insert(n->right, key);
    }
    n->height = 1 + max(getheight(n->left), getheight(n->right));
    int bf = getbalancefactor(n);   
    if(bf > 1 && key < n->left->val){
        return rightrotate(n);
    }
    else if(bf > 1 && key > n->left->val){
        n->left = leftrotate(n->left);
        return rightrotate(n);
    }
    else if(bf < -1 && key > n->right->val){
        return leftrotate(n);
    }
    else if(bf < -1 && key < n->right->val){
        n->right = rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
}

void preorder(Node *root)
{
    if(root != NULL)
    {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    Node *root = NULL;
    /* Constructing the AVL Tree by inserting keys */
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);
     
    /* The final constructed AVL Tree structure is:
                30
            /    \
           20     40
          / \       \
         10  25      50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preorder(root); // Expected output: 30 20 10 25 40 50
    cout << endl;
}