#include<iostream>

using namespace std;

class Node {
    public:
    string key;
    string value;
    bool occupied;      
};

class HashTable {
private:
    int size;
    Node* table;

public:
    HashTable(int s) {
        size = s;
        table = new Node[size];

        for (int i = 0; i < size; i++) {
            table[i].occupied = false;
        }
    }

    int hash(string key) {
        int sum = 0;
        for (char c : key){
            sum += int(c);
        }
        return sum % size;
    }

    void insert(string k, string val){
        int index = hash(k);
        int start = index;
        while(table[index].occupied){
            if(table[index].key == k){
                table[index].value = val;
                cout << "Updated (" << k << ", " << val << ") at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash table FULL! Cannot insert.\n";
                return;
            }
        }
        table[index].key = k;
        table[index].value = val;
        table[index].occupied = true;
        cout << "Inserted (" << k << ", " << val << ") at index " << index << endl;
    }

    void search(string k) {
        int index = hash(k);
        int start = index;

        while (table[index].occupied) {
            if (table[index].key == k) {
                cout << "Found: (" << table[index].key 
                     << ", " << table[index].value 
                     << ") at index " << index << endl;
                return;
            }

            index = (index + 1) % size;
            if (index == start) break;
        }

        cout << "Key \"" << k << "\" NOT FOUND!\n";
    }

    void deleteKey(string key) {
        int index = hash(key);
        int start = index;

        while (table[index].occupied) {
            if (table[index].key == key) {
                table[index].occupied = false;
                cout << "Deleted key \"" << key << "\" from index " << index << endl;
                return;
            }

            index = (index + 1) % size;
            if (index == start) break;
        }

        cout << "Key \"" << key << "\" not found, cannot delete!\n";
    }

    void display() {
        cout << "\n--- Hash Table (Linear Probing) ---\n";
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            if (!table[i].occupied)
                cout << "EMPTY\n";
            else
                cout << "(" << table[i].key << ", " << table[i].value << ")\n";
        }
    }
};

int main() {
    HashTable ht(4);

    ht.insert("Apple", "Red");
    ht.insert("Ball", "Round");
    ht.insert("Cat", "Animal");

    ht.display();

    ht.deleteKey("Ball");
    ht.insert("abll", "Round");
    ht.search("abll");

    ht.display();
}