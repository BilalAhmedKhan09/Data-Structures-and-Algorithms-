#include <iostream>
#include <string>

using namespace std;

struct Node {
    string key;
    Node* next;
    Node(const string& k) : key(k), next(nullptr) {}
};

class ChainHashTable {
private:
    int size;
    Node** table;

    int hashFunction(const string& key) {
        long long asciiSum = 0;
        for (char c : key) {
            asciiSum += static_cast<int>(c);
        }
        return asciiSum % size;
    }

public:
    ChainHashTable(int s = 10) : size(s) {
        table = new Node*[size];
        for (int i = 0; i < size; ++i) {
            table[i] = nullptr;
        }
    }

    ~ChainHashTable() {
        for (int i = 0; i < size; ++i) {
            Node* current = table[i];
            while (current) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
        delete[] table; 
    }

    void insert(const string& key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index] = newNode;
        }
    }

    bool search(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Bucket " << i << ": ";
            Node* current = table[i];
            if (current == nullptr) {
                cout << "NULL" << endl;
            } else {
                while (current) {
                    cout << current->key << " -> ";
                    current = current->next;
                }
                cout << "NULL" << endl;
            }
        }
    }
};

int main() {
    ChainHashTable ht(10);
    ht.insert("grapes");
    ht.insert("peach");
    ht.insert("banana");
    ht.insert("apple");
    ht.insert("mango");
    ht.insert("apple");
    ht.display();
    cout << endl;
    string searchKey1 = "apple";
    if (ht.search(searchKey1)) {
        cout << "Searching '" << searchKey1 << "': Found" << endl;
    } 
    else {
        cout << "Searching '" << searchKey1 << "': Not Found" << endl;
    }
    string searchKey2 = "orange";
    if (ht.search(searchKey2)) {
        cout << "Searching '" << searchKey2 << "': Found" << endl;
    } 
    else {
        cout << "Searching '" << searchKey2 << "': Not Found" << endl;
    }
}