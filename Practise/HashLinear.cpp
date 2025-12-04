#include<iostream>

using namespace std;

class Node {
    public:
    string key;
    string value;
    bool occupied;   // to check if slot is used
    bool deleted;    // for handling deletion if needed
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
            table[i].deleted = false;
        }
    }

    int hash(string key) {
        int sum = 0;
        for (char c : key){
            sum += int(c);
        }
        return sum % size;
    }

    void insert(string key, string val){
        int index = hash(key);
        int start = index;
        while(table[index].occupied && !table[index].deleted){
            if(table[index].key == key){
                table[index].value = val;
                cout << "Updated (" << key << ", " << val << ") at index " << index << endl;
                return;
            }
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash table FULL! Cannot insert.\n";
                return;
            }
        }
        table[index].key = key;
        table[index].value = val;
        table[index].occupied = true;
        table[index].deleted = false;
        cout << "Inserted (" << key << ", " << val << ") at index " << index << endl;
    }

        void search(string key) {
        int index = hash(key);
        int start = index;

        while (table[index].occupied || !table[index].deleted) {

            if (table[index].occupied || table[index].key == key) {
                cout << "Found: (" << table[index].key 
                     << ", " << table[index].value 
                     << ") at index " << index << endl;
                return;
            }

            index = (index + 1) % size;
            if (index == start) break;
        }

        cout << "Key \"" << key << "\" NOT FOUND!\n";
    }

    void deleteKey(string key) {
        int index = hash(key);
        int start = index;

        while (table[index].occupied || table[index].deleted) {

            if (table[index].occupied && table[index].key == key) {
                table[index].occupied = false;
                table[index].deleted = true;
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
    HashTable ht(10);

    ht.insert("Apple", "Red");
    ht.insert("Ball", "Round");
    ht.insert("Cat", "Animal");

    ht.display();

    ht.deleteKey("Ball");
    ht.search("Ball");

    ht.display();
}