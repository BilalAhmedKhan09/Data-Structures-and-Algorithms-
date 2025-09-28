#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int key) {
    int low=0, high=n-1;
    while(low<=high) {
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main() {
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Elements: ";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int key;
    cout<<"Enter Target: ";
    cin>>key;
    int result=binarySearch(arr,n,key);
    if(result!=-1){ 
        cout<<"Element found: "<<result<<endl;
    }
    else{
    cout<<"Element not found"<<endl;
    }
}
