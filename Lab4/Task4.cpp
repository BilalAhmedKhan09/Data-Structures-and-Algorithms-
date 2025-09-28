#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while(low <= high && x >= arr[low] && x <= arr[high]) {
        if(low == high) {
            if(arr[low] == x) {
                return low;
            }
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
        if(arr[pos] == x) {
            return pos;
        }
        if(arr[pos] < x) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[1000];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    cin >> x;
    int i = interpolationSearch(arr, n, x);
    if(i != -1) {
        cout << "Found at index " << i;
    }
    else{ 
        cout << "Not Found";
    }
}
