#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
    string key;
    string val;
    Node *next;
    Node(string k, string v): key(k), val(v), next(nullptr){}
    Node(){}
};

class Hashtable{
    public:
    int size;
    Node **table;
    Hashtable(int s): size(s){
        table = new Node*[s];
        for(int i=0; i<size; i++){
            table[i] = nullptr;
        }
    }

    int Hash(string key){
        int sum = 0;
        for(char c: key){
            sum += c;
        }
        return sum%size;
    }

    void insert(string key, string val){
        int index = Hash(key);
        Node *newn = new Node(key,val);
        Node *temp = table[index];

        if(table[index] == nullptr){
            table[index] = newn;
            return;
        }
        while(temp->next != nullptr){
            if(temp->key == key){
                temp->val = val;
                delete newn;
                return;
            }
            temp = temp->next;
        }
        if(temp->key == key){
            temp->val = val;
            delete newn;
            return;
        }
        temp->next = newn;
    }

    void deletion(string key){
        int index = Hash(key);
        Node *temp = table[index];
        Node *prev = nullptr;
        while(temp->next != nullptr && temp->key != key){
            prev = temp;
            temp = temp->next;
        }
        if(temp == nullptr){
            cout<<"Key not found"<<endl;
            return;
        }
        if(prev == nullptr){
            table[index] = temp->next;
        }
        else{
            prev->next = temp->next;
        }
        delete temp;
    }

    void search(string key){
        int index = Hash(key);
        Node *temp = table[index];
        while(temp != nullptr){
            if(temp->key == key){
                cout<<temp->val<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Not found"<<endl;
    }

    void display() {
        cout << "\n--- Hash Table (Key-Value Separate Chaining) ---\n";
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            if (table[i] == NULL)
                cout << "EMPTY\n";
            else {
                Node* temp = table[i];
                while (temp != NULL) {
                    cout << "(" << temp->key << ", " << temp->val<< ") -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }
        }
    }
};

int main(){
    Hashtable ht(10);
    ht.insert("Apple", "Red");
    ht.insert("Banana", "Yellow");
    ht.insert("Grapes", "Green");
    ht.insert("Mango", "Sweet");
    ht.insert("Apple", "Green Apple");  // update existing key

    cout << endl;

    ht.search("Mango");
    ht.search("Orange");

    cout << endl;

    ht.display();
}
