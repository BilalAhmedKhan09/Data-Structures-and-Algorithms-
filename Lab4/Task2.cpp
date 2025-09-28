#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void bubbleSort(int arr[], int n, int &comp) {
    comp = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            comp++;
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comp) {
    comp = 0;
    for(int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while(j >= 0 && (comp++, arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n, int &comp) {
    comp = 0;
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            comp++;
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void shellSort(int arr[], int n, int &comp) {
    comp = 0;
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for(j = i; j >= gap && (comp++, arr[j - gap] > temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    srand(time(0));
    int n = 20, arr[100];
    for(int i = 0; i < n; i++){ 
        arr[i] = rand() % 100 + 1;
    }
    int a1[100], a2[100], a3[100], a4[100], c;
    for(int i = 0; i < n; i++) {
        a1[i] = arr[i];
        a2[i] = arr[i];
        a3[i] = arr[i];
        a4[i] = arr[i];
    }

    bubbleSort(a1, n, c);
    for(int i = 0; i < n; i++) cout << a1[i] << " ";
    cout << endl << "Comparisons: " << c << endl;

    insertionSort(a2, n, c);
    for(int i = 0; i < n; i++) cout << a2[i] << " ";
    cout << endl << "Comparisons: " << c << endl;

    selectionSort(a3, n, c);
    for(int i = 0; i < n; i++) cout << a3[i] << " ";
    cout << endl << "Comparisons: " << c << endl;

    shellSort(a4, n, c);
    for(int i = 0; i < n; i++) cout << a4[i] << " ";
    cout << endl << "Comparisons: " << c << endl;
    n = 100;
    for(int i = 0; i < n; i++) 
        arr[i] = rand() % 100 + 1;
}
