#include <iostream>

using namespace std;

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void printArray(int arr[], int n, int exp) {
    if (exp == 1) {
        cout << "Pass 1 (Units digit): ";
    } else if (exp == 10) {
        cout << "Pass 2 (Tens digit):";
    } else if (exp == 100) {
        cout << "Pass 3 (Hundreds digit): ";
    } else if (exp == 1000) {
        cout << "Pass 4 (Thousands digit):";
    } else if (exp == 10000) {
        cout << "Pass 5 (Ten-Thousands digit):";
    } else {
        cout << "Array after pass: ";
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] <<endl;
    }
    cout << endl;
}

void countSort(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0}; 

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    printArray(arr, n, exp);
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    int productIDs[] = {
        52184, 11234, 99001, 30502, 44444, 10000, 
        73195, 22222, 50000, 81111, 
        31000, 77777, 60987, 10101, 40000, 
        55555, 28003, 91234, 13370, 60000
    };
    int n = sizeof(productIDs) / sizeof(productIDs[0]);
    cout << " Radix Sort on 5-Digit Product IDs " << endl;
    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << productIDs[i] << " ";
    }
    cout << endl;
    radixSort(productIDs, n);
    cout << "After Sorting: ";
    for (int i = 0; i < n; i++) {
        cout << productIDs[i] <<endl;
    }
    cout << endl;
}