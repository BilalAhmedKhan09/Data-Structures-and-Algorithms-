#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** headRef, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void displayList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void swapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low;
    Node* j = low;

    while (j != high) {
        if (j->data <= pivot) {
            swapData(i, j);
            i = i->next;
        }
        j = j->next;
    }
    swapData(i, high);
    return i;
}

Node* getTail(Node* start) {
    Node* current = start;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    return current;
}

Node* getLastNodeBefore(Node* head, Node* target) {
    if (head == target) return nullptr;
    Node* current = head;
    while (current != nullptr && current->next != target) {
        current = current->next;
    }
    return current;
}

void quickSortRec(Node* low, Node* high) {
    if (low == nullptr || low == high || high == nullptr) {
        return;
    }
    Node* pivot = partition(low, high);
    Node* prevToPivot = getLastNodeBefore(low, pivot);
    if (prevToPivot != nullptr) {
        quickSortRec(low, prevToPivot);
    }
    quickSortRec(pivot->next, high);
}

void quickSortLL(Node** headRef) {
    if (*headRef == nullptr || (*headRef)->next == nullptr) {
        return;
    }
    Node* tail = getTail(*headRef);
    quickSortRec(*headRef, tail);
}

int main() {
    Node* head = nullptr;
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 10);
    quickSortLL(&head);
    displayList(head);
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
