#include<iostream>

using namespace std;

class queue{
    public:
    int size;
    int *arr;
    queue(int s){
        size = 0;
        arr = new int[s];
    }
    void enqueue(int *arr2,int start, int end){
        int count = 0;
        for(int i = start; i <= end; i++) {
            arr[count] = arr2[i];
            count++;
            size++;
        }
        buildheap();
        count = 0;
        for(int i = start; i <= end; i++) {
            arr2[i] = remove();
        }
    }

    int remove(){
        int num = arr[0];
        arr[0] = arr[size-1];
        size--;
        int i = 0;
        while(true){
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
                swap(arr[smallest],arr[i]);
                i = smallest;
            }
            else{
                    break;
                }
        }
        return num;
    }
    void heapify(int i){
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
            swap(arr[smallest],arr[i]);
            heapify(smallest);
        }
    }
    void buildheap(){
        for(int i = (size/2)-1 ; i>=0;i--){
            heapify(i);
        }
    }

};

int main(){
    int arr[8] = {10,5,8,12,15,6,3,9};
    int start = 2;
    int end = 6;
    queue q(end-start+1);
    q.enqueue(arr,start,end);
    for(int i=0;i<8;i++){
        cout<<arr[i]<<endl;
    }
}