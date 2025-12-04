#include<iostream>

using namespace std;

int partition(int arr[], int start, int end){
    int index = start - 1;
    int pivot = arr[end];
    for(int j=start; j<end; j++){
        if(arr[j] <= pivot){
            index++;
            int temp = arr[j];
            arr[j] = arr[index];
            arr[index] = temp;
        }
    }
    index++;
    int temp = arr[index];
    arr[index] = arr[end];
    arr[end] = temp;
    return index;
}

void QuickSort(int arr[], int start, int end){
    if(start < end){
        int pivot = partition(arr, start, end);
        QuickSort(arr, 0, pivot-1);
        QuickSort(arr, pivot+1, end);
    }
}

int main(){
    int arr[6] = {30,5,8,40,50,1};
    QuickSort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}