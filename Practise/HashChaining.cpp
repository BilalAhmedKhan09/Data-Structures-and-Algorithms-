#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
        int key;
        Node *next;
        Node(int k): key(k), next(nullptr){}
        Node(){};
};

class hashtable{
    public:
        int size;
        Node **table;
        hashtable(int s){
            size = s;
            table = new Node*[s];
            for(int i=0;i<s;i++){
                table[i] = nullptr;
            }
        }

        int hash(int k){
            return k%size;
        }

        void insert(int k){
            int index = hash(k);
            Node *newn = new Node(k);
            Node *temp = table[index];
            if(table[index] == nullptr){
                table[index] = newn;
                return;
            }
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newn;
        }

        void deletion(int k){
            int index = hash(k);
            Node *temp = table[index];
            Node *prev = nullptr;
            while(temp != nullptr && temp->key != k){
                prev = temp;
                temp = temp->next;
            }
            if(temp == nullptr){
                cout<<"Key not found"<<endl;
                return;
            }
            else if(prev == nullptr){
                table[index] = temp->next; 
            }
            else{
                prev->next = temp->next;
            }
            delete temp;
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
                    cout << "(" << temp->key << ") -> ";
                    temp = temp->next;
                }
                cout << "NULL\n";
            }
        }
    }
};

int main(){
    hashtable ht(10);
    ht.insert(10);
    ht.insert(5);
    ht.insert(3);
    ht.insert(8);
    ht.insert(25); 

    ht.display();
    cout << endl;

    ht.deletion(5);
    ht.deletion(6);
    cout << endl;

    ht.display();
}
