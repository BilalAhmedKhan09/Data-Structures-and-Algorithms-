#include<iostream>

using namespace std;

void sort(int arr[], int start, int mid, int end){
    int size = end-start+1;
    int left = start;
    int right = mid+1;
    int *temp = new int[size];
    int index = 0;
    while(left<=mid && right<=end){
        if(arr[left] < arr[right]){
            temp[index] = arr[left];
            left++;
            index++;
        }
        else{
            temp[index] = arr[right];
            right++;
            index++;
        }
    }
    while(left <= mid){
        temp[index] = arr[left];
        left++;
        index++;
    }
    while(right <= end){
        temp[index] = arr[right];
        right++;
        index++;
    }
    for(int i=0;i<size;i++){
        arr[start+i]  = temp[i];
    }
    delete[] temp;
}

void mergesort(int arr[], int start, int end){
    if(start < end){
        int mid = start + (end-start)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        sort(arr, start, mid, end);
    }
}

int main(){
    int arr[6] = {30,5,8,40,50,1};
    mergesort(arr,0,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}