#include<iostream>

using namespace std;

class Heap{
    public:
        int size;
        int *arr;
        Heap(int s){
            size = 0;
            arr = new int[s];
        }
        ~Heap(){
            delete[] arr;
        }
        void heapify(int arr[],int size,int i){
            int smallest = i;
            int left = 2*i+1;
            int right = 2*i+2;
            if(left < size && arr[left] < arr[smallest]){
                smallest = left;
            }
            if(right < size && arr[right] < arr[smallest]){
                smallest = right;
            }
            if(smallest != i){
                swap(arr[smallest], arr[i]);
                heapify(arr,size,smallest);
            }
        }
        void remove(){
            if(size == 0){
                cout<<"Empty Heap"<<endl;
                return;
            }
            cout<<"Smallest: "<<arr[0]<<endl;
            arr[0] = arr[size-1];
            size--;
            int index = 0;
            while(true){
                int smallest = index;
                int left = 2*index+1;
                int right = 2*index+2;
                if(left < size && arr[left] < arr[smallest]){
                    smallest = left;
                }
                if(right < size && arr[right] < arr[smallest]){
                    smallest = right;
                }
                if(smallest != index){
                    swap(arr[smallest], arr[index]);
                    index = smallest;
                }
                else{
                    return;
                }
            }
        }
        void insert(int val){
            int i = size;
            size++;
            arr[i] = val;
            while(i > 0){
                int p = (i-1)/2;
                if(arr[i] < arr[p]){
                    swap(arr[i], arr[p]);
                    i = p;
                }
                else{
                    return;
                }
            }
        }
        void display(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<endl;
            }
        }
};

int main(){
    int arr2[5] = {5,10,3,4,9};
    Heap h(100);
    for(int i=(5/2)-1;i>=0;i--){
        h.heapify(arr2,5,i);
    }
    for(int i=0;i<5;i++){
        cout<<arr2[i]<<endl;
    }
    cout<<"-----------------------------"<<endl;
    h.insert(1);
    h.insert(6);
    h.insert(10);
    h.insert(5);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.display();
    cout<<endl;
    h.remove();
    h.remove();
    h.remove();
    h.display();
}