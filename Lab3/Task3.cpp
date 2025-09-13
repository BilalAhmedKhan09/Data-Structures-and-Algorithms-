#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string compartment;
    Node* nextCompartment;
    Node* prevCompartment;

    Node(string val) : compartment(val), nextCompartment(NULL), prevCompartment(NULL) {}
};

class RailwaySystem {
private:
    Node* start;
    Node* end;

public:
    RailwaySystem() : start(NULL), end(NULL) {}

    void addCompartmentAtEnd(string val) {
        Node* freshNode = new Node(val);
        if (!start) {
            start = end = freshNode;
            return;
        }
        end->nextCompartment = freshNode;
        freshNode->prevCompartment = end;
        end = freshNode;
    }

    void removeCompartmentAtFront() {
        if (!start) return;
        Node* head = start;
        start = start->nextCompartment;
        if (start) {
            start->prevCompartment = NULL;
        } else {
            end = NULL;
        }
        delete head;
    }

    Node* searchCompartmentByPosition(int position) {
        Node* head = start;
        int index = 0;
        while (head && index < position - 1) {
            head = head->nextCompartment;
            index++;
        }
        return head;
    }

    void displayTrain() {
        Node* head = start;
        while (head) {
            cout << head->compartment << " -> ";
            head = head->nextCompartment;
        }
        cout << "NULL" << endl;
    }

    ~RailwaySystem() {
        Node* head;
        while (start) {
            head = start;
            start = start->nextCompartment;
            delete head;
        }
    }
};

int main() {
    RailwaySystem train;
    train.addCompartmentAtEnd("Compartment 1");
    train.addCompartmentAtEnd("Compartment 2");
    train.addCompartmentAtEnd("Compartment 3");
    cout << "Current train configuration:" << endl;
    train.displayTrain();
    cout << "Removing compartment at front." << endl;
    train.removeCompartmentAtFront();
    train.displayTrain();
    int searchPosition = 1;
    Node* found = train.searchCompartmentByPosition(searchPosition);
    if (found) {
        cout << "Found compartment at position " << searchPosition << ": " << found->compartment << endl;
    } 
    else {
        cout << "No compartment found at position " << searchPosition << endl;
    }
}
