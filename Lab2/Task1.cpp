#include<iostream>

using namespace std;

class Array{
    public:
    int *arr;
    int elements;
    int pointer;
    
    Array(){
        pointer  = -1;
        elements = 3;
        arr = new int[elements];
    }
    void resize(int data){
        elements += 1;
        int *arr2 = new int[elements];
        for(int i=0;i<elements-1;i++){
            arr2[i] = arr[i];
        }
        arr2[elements-1] = data;
        delete[] arr;
        arr = arr2;
    }
    void push(int data){
        if(pointer == -1){
            arr[0] = data;
            pointer += 1;
        }
        else if(pointer == elements-1){
            cout<<"Resizing array"<<endl;
            resize(data);
        }
        else{
            arr[pointer+1] = data;
            pointer += 1;
        }
    }

    void display(){
        for(int i=0;i<elements;i++){
            cout<<arr[i]<<endl;
        }
    }
    ~Array(){
        delete[] arr;
        pointer = -1;
        elements = 3;
    }
};

int main(){
    Array array;
    array.push(1);
    array.push(2);
    array.push(3);
    array.display();
    array.push(4);
    array.display();
}