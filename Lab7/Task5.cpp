#include <iostream>

using namespace std;

#define MAX_SIZE 100

long long comparison_count = 0;

void swap_elements(int arr[], int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        comparison_count++;
        if (arr[j] <= pivot) {
            i++;
            swap_elements(arr, i, j);
        }
    }
    swap_elements(arr, i + 1, high);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, void (*pivotSelector)(int[], int, int)) {
    if (low < high) {
        pivotSelector(arr, low, high);
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, pivotSelector);
        quickSort(arr, pi + 1, high, pivotSelector);
    }
}

void firstElementPivot(int arr[], int low, int high) {
    swap_elements(arr, low, high);
}

void randomElementPivot(int arr[], int low, int high) {
    int random_index = low + (rand() % (high - low + 1));
    swap_elements(arr, random_index, high);
}

void middleElementPivot(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap_elements(arr, mid, high);
}

void medianOfThreePivot(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    comparison_count++;
    if (arr[low] > arr[mid]) {
        swap_elements(arr, low, mid);
    }
    comparison_count++;
    if (arr[low] > arr[high]) {
        swap_elements(arr, low, high);
    }
    comparison_count++;
    if (arr[mid] > arr[high]) {
        swap_elements(arr, mid, high);
    }
}


void runQuickSortTest(const char* method_name, int data[], int n, void (*pivotSelector)(int[], int, int)) {
    comparison_count = 0;
    int test_data[MAX_SIZE];
    for(int i = 0; i < n; i++) {
        test_data[i] = data[i];
    }
    quickSort(test_data, 0, n - 1, pivotSelector);
    cout << method_name << ": " << comparison_count << endl;
}

int main() {
    int original_data[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(original_data) / sizeof(original_data[0]);
    runQuickSortTest("First Element Comparisons", original_data, n, firstElementPivot);
    runQuickSortTest("Random Element Comparisons", original_data, n, randomElementPivot);
    runQuickSortTest("Middle Element Comparisons", original_data, n, middleElementPivot);
    runQuickSortTest("Median of Three Comparisons", original_data, n, medianOfThreePivot);
}