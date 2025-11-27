#include <iostream>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;

struct E {
    string name;
};

class EmployeeHashTable {
private:
    int sz = 50; 
    E* tbl;
    string EMPTY = ""; 
    string DELETED = "#DELETED#";
    
    int sumASCII(string s) {
        int sum = 0;
        for (char c : s) {
            sum += (int)c;
        }
        return sum;
    }

    int h1(int asciiSum) {
        return asciiSum % sz;
    }

    int h2(int asciiSum) {
        return 7 - (asciiSum % 7);
    }

public:
    EmployeeHashTable() {
        tbl = new E[sz];
        for (int i = 0; i < sz; ++i) {
            tbl[i].name = EMPTY;
        }
    }

    ~EmployeeHashTable() {
        delete[] tbl; 
    }

    void Add_Employee(string n) {
        if (n.empty()) return;
        int asciiSum = sumASCII(n);
        int h1_val = h1(asciiSum);
        int h2_val = h2(asciiSum);
        int i = 0;   
        while (i < sz) {
            int curr_idx = (h1_val + i * h2_val) % sz;
            if (tbl[curr_idx].name == EMPTY || tbl[curr_idx].name == DELETED) {
                tbl[curr_idx].name = n;
                cout << "Employee '" << n << "' added at index " << curr_idx << endl;
                return;
            }
            if (tbl[curr_idx].name == n) {
                cout << "Employee " << n << "' already exists at index " << curr_idx << endl;
                return;
            }
            i++;
        }
        cout << "Hash table is full" << n << "'" << endl;
    }

    void Search_Employee(string n) {
        int asciiSum = sumASCII(n);
        int h1_val = h1(asciiSum);
        int h2_val = h2(asciiSum);
        int i = 0;
        while (i < sz) {
            int curr_idx = (h1_val + i * h2_val) % sz;       
            if (tbl[curr_idx].name == EMPTY) {
                cout << "Employee not found in the directory." << endl;
                return;
            }
            if (tbl[curr_idx].name == n) {
                cout << "Employee '" << n << "' found at index " << curr_idx << "." << endl;
                return;
            }
            i++;
        }
        cout << "Employee not found in the directory." << endl;
    }

    void Display_Table() {
        cout << "\n--- Employee Directory State ---" << endl;
        bool first = true;
        for (int i = 0; i < sz; ++i) {
            if (tbl[i].name != EMPTY && tbl[i].name != DELETED) {
                if (!first) {
                    cout << ", ";
                }
                cout << "Index " << i << ": '" << tbl[i].name << "'";
                first = false;
            }
        }
        if (first) {
            cout << "Directory is empty.";
        }
        cout << endl;
    }
};

int main() {
    EmployeeHashTable t;
    t.Add_Employee("Alice"); 
    t.Add_Employee("Bob");
    t.Add_Employee("Carol");
    t.Add_Employee("Fizzy");
    t.Add_Employee("Doris");
    t.Add_Employee("Eliza");
    t.Display_Table();
    t.Search_Employee("Bob");
    t.Search_Employee("Carol");
    t.Search_Employee("George"); 
}