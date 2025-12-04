#include<iostream>

using namespace std;

int getmax(int arr[], int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countsort(int arr[], int n, int pos){
    int *output = new int[n];
    int count[10] = {0};
    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;
    }
    for(int i=1; i<10;i++){
        count[i] += count[i-1];
    }
    for(int i = n-1; i>=0;i--){
        int digit = (arr[i]/pos)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }     
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
    delete output;
}

void radix(int arr[], int n){
    int max = getmax(arr, n);
    for(int pos=1; max/pos > 0 ;pos*=10){
        countsort(arr,n,pos);
    }
}

int main(){
    int arr[8] = {170, 45, 75, 90, 802, 24, 2, 66};
    radix(arr, 8);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }
}