#include <iostream>
#include <string>

using namespace std;

class Node{
public:
    string info;
    Node* nextNode;

    Node(string val) : info(val), nextNode(NULL) {}
};

class LinkedList
{
private:
    Node* start;
public:
    LinkedList() : start(NULL) {}
    void insertAtFront(string val) {
        Node* freshNode = new Node(val);
        freshNode->nextNode = start;
        start = freshNode;
    }

    void insertAtEnd(string val) {
        Node* freshNode = new Node(val);
        if (!start) {
            start = freshNode;
            return;
        }
        Node* head = start;
        while (head->nextNode) {
            head = head->nextNode;
        }
        head->nextNode = freshNode;
    }

    void insertAfter(string target, string val){
        Node* head = start;
        while (head && head->info != target){
            head = head->nextNode;
        }
        if (head) {
            Node* freshNode = new Node(val);
            freshNode->nextNode = head->nextNode;
            head->nextNode = freshNode;
        }
    }

    Node* search(string target) {
        Node* head = start;
        while (head) {
            if (head->info == target) {
                return head;
            }
            head = head->nextNode;
        }
        return NULL;
    }

    void display() {
        Node* head = start;
        while (head) {
            cout << head->info << " -> ";
            head = head->nextNode;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList(){
        Node* head;
        while (start) {
            head = start;
            start = start->nextNode;
            delete head;
        }
    }
    
};

int main() {
    LinkedList myList;
    myList.insertAtFront("Artificial Intelligence");
    myList.insertAtEnd("Machine Learning");
    myList.insertAfter("Artificial Intelligence", "Operating Systems");
    myList.insertAfter("operating Systems", "Cyber Security");
    myList.insertAtEnd("Database systems");
    cout << myList.search("Database systems")->info << endl;
    myList.display();
}
