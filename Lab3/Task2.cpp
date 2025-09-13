#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string title;
    Node* nextBook;

    Node(string val) : title(val), nextBook(NULL) {}
};

class LibraryCatalog {
private:
    Node* start;

public:
    LibraryCatalog() : start(NULL) {}

    void addAtTail(string val) {
        Node* freshNode = new Node(val);
        if (!start) {
            start = freshNode;
            return;
        }
        Node* head = start;
        while (head->nextBook) {
            head = head->nextBook;
        }
        head->nextBook = freshNode;
    }

    void removeBook(string target) {
        if (!start) return;
        if (start->title == target) {
            Node* head = start;
            start = start->nextBook;
            delete head;
            return;
        }
        Node* curr = start;
        Node* prev = NULL;
        while (curr && curr->title != target) {
            prev = curr;
            curr = curr->nextBook;
        }
        if (curr) {
            prev->nextBook = curr->nextBook;
            delete curr;
        }
    }

    Node* searchBookByTitle(string target) {
        Node* head = start;
        while (head && head->title != target) {
            head = head->nextBook;
        }
        return head;
    }

    Node* searchBookByPosition(int position) {
        Node* head = start;
        int index = 0;
        while (head && index < position) {
            head = head->nextBook;
            index++;
        }
        return head;
    }

    void displayCatalog() {
        Node* head = start;
        while (head) {
            cout << head->title << " ";
            head = head->nextBook;
        }
        cout << endl;
    }

    ~LibraryCatalog() {
        Node* head;
        while (start) {
            head = start;
            start = start->nextBook;
            delete head;
        }
    }
};

int main() {
    LibraryCatalog catalog;
    catalog.addAtTail("The Great Gatsby");
    catalog.addAtTail("1984");
    catalog.addAtTail("To Kill a Mockingbird");
    cout << "Catalog after adding books:" << endl;
    catalog.displayCatalog();
    string searchTitle = "1984";
    Node* foundBook = catalog.searchBookByTitle(searchTitle);
    if (foundBook) {
        cout << "Found book: " << foundBook->title << endl;
    } 
    else {
        cout << "Book not found: " << searchTitle << endl;
    }
    int position = 1;
    Node* bookAtPosition = catalog.searchBookByPosition(position);
    if (bookAtPosition) {
        cout << "Book at position " << position << ": " << bookAtPosition->title << endl;
    } 
    else {
        cout << "No book found at position " << position << endl;
    }
    catalog.removeBook("1984");
    cout << "Catalog after removing '1984':" << endl;
    catalog.displayCatalog();
}


