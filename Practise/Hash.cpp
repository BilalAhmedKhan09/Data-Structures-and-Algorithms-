#include<iostream>

using namespace std;

class Node{
    public:
    int key;
    bool occup;
};

class hashtable{
    public:
    int size;
    Node *table;
    hashtable(int s){
        size = s;
        for(int i=0;i<s;i++){
            table[i].occup = false;
        }
    }
    int hash(int k){
        return k%size;
    }
    int hash2(int k){
        return (7+(k%7));
    }
    void insert(int k){
        int index = hash(k);
        int start = index;
        int pos = hash2(k);
        int i = 1;
        while(table[index].occup){
            index = (index + i*pos)%size;
            i++;
            if(index == start){
                cout<<"Full"<<endl;
                return;
            }
        }
        table[index].key = k;
        cout<<"inserted"<<endl;
    }
    void Delete(int k){
        int index = hash(k);
        int start = index;
        int pos = hash2(k);
        int i = 1;
        while(table[index].occup){
            index = (index + i*pos)%size;
            if(table[index].key == k){
                table[index].occup = false;
                cout<<"deleted"<<endl;
            }
            if(index == start){
                cout<<"Not found"<<endl;
                return;
            }
        }
    }
};

int main(){
    int arr[6] = {12,3,4,7,10,45};
    hashtable ht(11);
    for(int i=0;i<6;i++){
        ht.insert(arr[i]);
    }
}