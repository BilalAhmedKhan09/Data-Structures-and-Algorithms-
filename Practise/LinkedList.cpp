#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node() {
        data = -1;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList {
public:
    Node *head, *tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void atstart(int d) {
        Node *temp = new Node(); // allocate new node
        temp->data = d;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void atend(int d) {
        Node *temp = new Node(); // allocate new node
        temp->data = d;
        if (tail == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void atpos(int a, int data){
        Node *temp = new Node();
        temp->data = data;
        if(head==NULL){
            head = temp;
            tail = temp;
        }
        else{
            Node *t;
            for(t=head;t->next!=NULL;t=t->next){
                if(t->data == a){
                    Node *temp2 = t->next;
                    t->next = temp;
                    temp->prev = t;
                    temp->next = temp2;
                }
            }
        }
    }
    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    list.atstart(5);
    list.atend(6);
    list.atpos(5,1);
    list.display();
    list.atstart(4);
    list.display();
}
