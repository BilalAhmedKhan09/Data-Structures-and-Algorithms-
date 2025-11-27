#include <iostream>
#include <string>

using namespace std;

class Hash {
private:
    int sz = 10; 
    int* tbl;
    const int EMPTY = -1;
    const int DELETED = -2;
    int hashFn(int k) {
        return k % sz;
    }

public:
    Hash() {
        tbl = new int[sz];
        for (int i = 0; i < sz; ++i) {
            tbl[i] = EMPTY;
        }
    }

    ~Hash() {
        delete[] tbl; 
    }

    void insert(int k) {
        if (k <= 0) return; 

        int idx = hashFn(k);
        int i = 0;
        while (i < sz) {
            int curr_idx = (idx + i) % sz;
            if (tbl[curr_idx] == EMPTY || tbl[curr_idx] == DELETED) {
                tbl[curr_idx] = k;
                return;
            }
            i++;
        }
    }

    void Delete_Record(int k) {
        int idx = hashFn(k);
        int i = 0;
        while (i < sz) {
            int curr_idx = (idx + i) % sz;
            if (tbl[curr_idx] == EMPTY) {
                return;
            }
            if (tbl[curr_idx] == k) {
                tbl[curr_idx] = DELETED; 
                return;
            }
            i++;
        }
    }

    bool search(int k) {
        int idx = hashFn(k);
        int i = 0;
        while (i < sz) {
            int curr_idx = (idx + i) % sz;
            if (tbl[curr_idx] == EMPTY) {
                return false;
            }
            if (tbl[curr_idx] == k) {
                return true;
            }
            i++;
        }
        return false;
    }

    void display() {
        bool first = true;
        for (int i = 0; i < sz; ++i) {
            if (tbl[i] != EMPTY && tbl[i] != DELETED) {
                if (!first) {
                    cout << " ";
                }
                cout << tbl[i];
                first = false;
            }
        }
        cout << endl;
    }
};

int main() {
    Hash h;
    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7); 
    h.display();
    cout << "Remove 4" << endl;
    h.Delete_Record(4);
    h.display();
    if (h.search(5)) {
        cout << "5 found" << endl;
    } 
    else {
        cout << "5 not found" << endl;
    }
    if (h.search(6)) {
        cout << "6 found" << endl;
    } 
    else {
        cout << "6 not found" << endl;
    }
}