#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node* link;

    Node(int val) : value(val), link(NULL) {}
};

void listSort(Node* start) {
    if (!start) return;
    bool swapped;
    Node* current;
    Node* lastPtr = NULL;

    do {
        swapped = false;
        current = start;

        while (current->link != lastPtr) {
            if (current->value > current->link->value) {
                int temp = current->value;
                current->value = current->link->value;
                current->link->value = temp;
                swapped = true;
            }
            current = current->link;
        }
        lastPtr = current;
    } while (swapped);
}

Node* mergeLists(Node* firstList, Node* secondList) {
    if (!firstList) return secondList;
    if (!secondList) return firstList;

    Node* cursor = firstList;
    while (cursor->link) {
        cursor = cursor->link;
    }
    cursor->link = secondList;
    return firstList;
}

Node* middleNode(Node* start) {
    if (!start) return NULL;
    Node* slowPtr = start;
    Node* fastPtr = start;

    while (fastPtr && fastPtr->link) {
        slowPtr = slowPtr->link;
        fastPtr = fastPtr->link->link;
    }
    return slowPtr;
}

void removeDuplicates(Node* start) {
    if (!start) return;
    Node* walker = start;

    while (walker && walker->link) {
        if (walker->value == walker->link->value) {
            Node* temp = walker->link;
            walker->link = walker->link->link;
            delete temp;
        } else {
            walker = walker->link;
        }
    }
}

Node* mergeSortedLists(Node* firstList, Node* secondList) {
    if (!firstList) return secondList;
    if (!secondList) return firstList;

    if (firstList->value < secondList->value) {
        firstList->link = mergeSortedLists(firstList->link, secondList);
        return firstList;
    } else {
        secondList->link = mergeSortedLists(firstList, secondList->link);
        return secondList;
    }
}

void printList(Node* start) {
    Node* cursor = start;
    while (cursor) {
        cout << cursor->value << "->";
        cursor = cursor->link;
    }
    cout << "NULL" << endl;
}

void freeList(Node* start){
    while (start) {
        Node* temp = start;
        start = start->link;
        delete temp;
    }
}

int main() 
{
    Node* list1 = new Node(3);
    list1->link = new Node(1);
    list1->link->link = new Node(4);
    list1->link->link->link = new Node(2);
    printList(list1);
    listSort(list1);
    printList(list1);
    Node* list2 = new Node(6);
    list2->link = new Node(5);
    printList(list2);
    Node* combined = mergeLists(list1, list2);
    printList(combined);
    Node* mid = middleNode(combined);
    cout << "Middle Node: " << mid->value << endl; 
    removeDuplicates(combined);
    printList(combined);
    Node* sortedA = new Node(1);  
    sortedA->link = new Node(3);
    sortedA->link->link = new Node(5);
    Node* sortedB = new Node(2);
    sortedB->link = new Node(4);
    Node* mergedSorted = mergeSortedLists(sortedA, sortedB);
    printList(mergedSorted);
    freeList(combined);
    freeList(mergedSorted);
}
