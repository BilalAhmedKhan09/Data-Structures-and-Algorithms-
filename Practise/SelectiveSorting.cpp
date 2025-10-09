#include<iostream>

using namespace std;


//Sorts around every third element

int* SelectiveSort(int *arr, int size){
    int *arr2;
    int count = 0;
    arr2 = new int[size/3];
    int min;
    for(int i=0;i<size-1;i++){
        min = i;
        if((i+1)%3!=0 || i==0){
            for(int j=i+1;j<size;j++){
                if((j+1)%3 !=0)
                    if(arr[j] < arr[min]){
                        min = j;
                    }
            }
        }
        else{
            arr2[count] = arr[i];
            count++;
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    if(size%3==0){
        arr2[count] = arr[size-1];
    }
    return arr2;
}




int main(){
    int *arr;
    int *msg;
    int size;
    cin>>size;
    arr = new int[size];
    for(int i=0;i<size;i++){
        cin>> arr[i];
    }
    cout<<"Before sorting: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;  
    msg = SelectiveSort(arr,size);
    cout<<"After sorting around: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    cout<<"Hidden message: "<<endl;
    for(int i=0;i<size/3;i++){
        cout<<msg[i]<<", ";
    }
}