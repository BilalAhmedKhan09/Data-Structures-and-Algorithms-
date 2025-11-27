#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct R {
    int roll;
    string name;
};

class StudentHashTable {
private:
    const int sz = 15;
    R* tbl;
    const int EMPTY = 0;
    const int DELETED = -1;
    int hashFn(int r) {
        return r % sz;
    }

public:
    StudentHashTable() {
        tbl = new R[sz];
        for (int i = 0; i < sz; ++i) {
            tbl[i].roll = EMPTY;
            tbl[i].name = "";
        }
    }

    ~StudentHashTable() {
        delete[] tbl; 
    }

    void InsertRecord(int r, const string& n) {
        if (r <= 0) return; 
        int idx = hashFn(r);
        int attempt = 0;
        while (attempt < sz) {
            int curr_idx = (idx + attempt * attempt) % sz;
            if (tbl[curr_idx].roll == EMPTY || tbl[curr_idx].roll == DELETED) {
                tbl[curr_idx].roll = r;
                tbl[curr_idx].name = n;
                cout << "Record inserted: Roll " << r << " at slot " << curr_idx << endl;
                return;
            }
            if (tbl[curr_idx].roll == r) {
                tbl[curr_idx].name = n;
                cout << "Record updated for Roll " << r << endl;
                return;
            }
            attempt++;
        }
        cout << "Hash table is full" << r << endl;
    }

    void SearchRecord(int r) {
        int idx = hashFn(r);
        int attempt = 0;
        while (attempt < sz) {
            int curr_idx = (idx + attempt * attempt) % sz;     
            if (tbl[curr_idx].roll == EMPTY) {
                cout << "Record not found for Roll " << r << endl;
                return;
            }    
            if (tbl[curr_idx].roll == r) {
                cout << "Record found: Roll " << r << " belongs to " << tbl[curr_idx].name << endl;
                return;
            }
            attempt++;
        }
        cout << "Record not found for Roll " << r << endl;
    }

    void display() {
        cout << "\n--- Current Hash Table State ---" << endl;
        for (int i = 0; i < sz; ++i) {
            cout << "Slot " << i << ": ";
            if (tbl[i].roll == EMPTY) {
                cout << "EMPTY" << endl;
            } else if (tbl[i].roll == DELETED) {
                cout << "DELETED" << endl;
            } else {
                cout << "Roll " << tbl[i].roll << " (" << tbl[i].name << ")" << endl;
            }
        }
        cout << endl;
    }
};

int main() {
    StudentHashTable sht;
    sht.InsertRecord(16, "A"); 
    sht.InsertRecord(31, "B");   
    sht.InsertRecord(1, "C"); 
    sht.InsertRecord(2, "D"); 
    sht.InsertRecord(10, "E"); 
    sht.display();
    sht.SearchRecord(16);
    sht.SearchRecord(31);
    sht.SearchRecord(2);
    sht.SearchRecord(9);
    sht.SearchRecord(46);
}