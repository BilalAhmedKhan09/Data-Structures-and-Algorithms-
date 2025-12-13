#include<iostream>

using namespace std;

class Node {
public:
    int num;
    int stat;
    Node *next;

    Node(int val) : num(val), next(nullptr),stat(1) {}
};

class CircularLinkedList {
public:
    Node *head = nullptr;

    CircularLinkedList(int n) {
        if (n <= 0) return;
        head = new Node(1); 
        Node *current = head;
        for (int i = 2; i <= n; i++) {
            current->next = new Node(i);
            current = current->next;
        }
        current->next = head;
    }
};

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    CircularLinkedList l(n);
    int count = 1;
    int killed = 0;
    Node *temp = l.head;
    while(killed < (n-1)){
        if(temp->stat == 0){
            temp = temp->next;
        }
        else if(count == k){
            cout<<count<<" ";
            cout<<temp->num<<endl;
            temp->stat = 0;
            count = 1;
            temp = temp->next;
            killed++;
        }
        else{
            temp = temp->next;
            count++;
        }
    }
    Node *curr = l.head;
    while(curr->stat == 0){
        curr = curr->next;
    }
    cout<<curr->num<<endl;
}