#include <iostream>
#include <string>

using namespace std;

struct N {
    string key;
    N* next;
    N(const string& k) : key(k), next(nullptr) {}
};

class Dictionary {
private:
    int sz = 100;
    N** tbl;
    int hashFn(const string& k) {
        long long sum = 0;
        for (char c : k) {
            sum += static_cast<int>(c);
        }
        return sum % sz;
    }

public:
    Dictionary() {
        tbl = new N*[sz];
        for (int i = 0; i < sz; ++i) {
            tbl[i] = nullptr;
        }
    }

    ~Dictionary() {
        for (int i = 0; i < sz; ++i) {
            N* curr = tbl[i];
            while (curr) {
                N* nextN = curr->next;
                delete curr;
                curr = nextN;
            }
        }
        delete[] tbl; 
    }

    void Add_Record(const string& k) {
        int idx = hashFn(k);
        N* newN = new N(k);
        if (tbl[idx] == nullptr) {
            tbl[idx] = newN;
        } else {
            newN->next = tbl[idx];
            tbl[idx] = newN;
        }
    }

    void Word_Search(const string& k) {
        int idx = hashFn(k);
        N* curr = tbl[idx];
        bool found = false;
        while (curr) {
            if (curr->key == k) {
                found = true;
                break;
            }
            curr = curr->next;
        }
        if (found) {
            cout << "Word_Search('" << k << "'): Found at Bucket " << idx << endl;
        } 
        else {
            cout << "Word_Search('" << k << "'): Error: Word not found in dictionary." << endl;
        }
    }

    void Print_Dictionary() {
        cout << " Dictionary Contents (Table Size: " << sz << ")    " << endl;
        bool empty = true;
        for (int i = 0; i < sz; ++i) {
            N* curr = tbl[i];
            if (curr != nullptr) {
                empty = false;
                cout << "Bucket " << i << ": ";
                while (curr) {
                    cout << curr->key << " -> ";
                    curr = curr->next;
                }
                cout << "NULL" << endl;
            }
        }
        if (empty) {
            cout << "The dictionary is currently empty." << endl;
        }
        cout << endl;
    }
};

int main() {
    Dictionary dict;
    dict.Add_Record("algorithm");
    dict.Add_Record("data");
    dict.Add_Record("structure");
    dict.Add_Record("system");
    dict.Add_Record("apple");
    dict.Add_Record("zebra");
    dict.Add_Record("mango");
    dict.Print_Dictionary();
    dict.Word_Search("mango");
    dict.Word_Search("data");
    dict.Word_Search("book"); 
}