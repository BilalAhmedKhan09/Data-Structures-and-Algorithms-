#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string key;
    int frequency;
    bool isoccupied;

    Node() {
        key = "";
        frequency = 0;
        isoccupied = false;
    }

    Node(string s) : key(s), frequency(0), isoccupied(false) {}
};

class Hashtable {
public:
    Node* hashtable;
    int tablesize;
    int itemcount; 

    Hashtable() {
        tablesize = 10;
        itemcount = 0;
        hashtable = new Node[tablesize];
    }

    ~Hashtable() {
        delete[] hashtable;
        hashtable = nullptr;
    }

    int function1(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash = (hash * 21 + key[i]) % tablesize;
        }
        return hash;
    }

    int function2(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash = (hash * 31 + key[i]) % tablesize;
        }
        return (hash == 0) ? 1 : (tablesize - 1 - hash) % tablesize;
    }

    void resize() {
        int oldsize = tablesize;
        tablesize *= 2;
        Node* oldtable = hashtable;
        hashtable = new Node[tablesize];
        itemcount = 0; 
        for (int i = 0; i < oldsize; i++) {
            if (oldtable[i].isoccupied) {
                insert(oldtable[i].key, oldtable[i].frequency);
            }
        }

        delete[] oldtable;
        oldtable = nullptr;

        cout << "--- Hash Table resized. New capacity: " << tablesize << " ---" << endl;
    }


    void insert(string key, int freq = 1) {

        if (itemcount > tablesize / 2) {
            resize();
        }

        int index = function1(key);
        int step = function2(key);
        while (hashtable[index].isoccupied && hashtable[index].key != key) {
            index = (index + step) % tablesize;
        }
        if (!hashtable[index].isoccupied) {
          
            hashtable[index].key = key;
            hashtable[index].frequency = freq;
            hashtable[index].isoccupied = true;
            itemcount++;
        } 
        else {
           
            hashtable[index].frequency += freq;
        }
    }
    void display() {
        cout << "\n--- Hash Table Contents (Size: " << tablesize << ", Items: " << itemcount << ") ---" << endl;
        for (int i = 0; i < tablesize; i++) {
            if (hashtable[i].isoccupied) {
                cout << "[" << i << "] " << hashtable[i].key << " : " << hashtable[i].frequency << endl;
            }
        }
        cout << "---------------------------------------------------------" << endl;
    }
};


int main() {
    cout << "Starting Hash Table Demonstration..." << endl;
    Hashtable ht;
    ht.insert("apple");
    ht.insert("banana");
    ht.insert("cherry");
    ht.insert("date");
    ht.insert("elderberry");
    ht.insert("apple");

    ht.display();

    ht.insert("fig");

    ht.insert("grape");
    ht.insert("honeydew");
    ht.insert("kiwi");
    ht.insert("lemon");
    ht.insert("mango");
    ht.insert("fig");

    ht.display();

    cout << "Demonstration complete." << endl;
    return 0;
}