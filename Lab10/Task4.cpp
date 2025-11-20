#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

struct MinHeap {
    int arr[MAX_SIZE];
    int size;
    MinHeap() : size(0) {}
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void siftUp(int i) {
        while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void siftDown(int i) {
        int minIndex = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && arr[left] < arr[minIndex]) {
            minIndex = left;
        }
        if (right < size && arr[right] < arr[minIndex]) {
            minIndex = right;
        }
        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
            siftDown(minIndex);
        }
    }

    void insert(int key) {
        if (size < MAX_SIZE) {
            arr[size] = key;
            size++;
            siftUp(size - 1);
        }
    }

    int removeMin() {
        if (size == 0) return -1;
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        siftDown(0);
        return root;
    }

    void buildHeap(int keys[], int n) {
        for (int i = 0; i < n; ++i) {
            arr[i] = keys[i];
        }
        size = n;
        for (int i = size / 2 - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    void display(const char* label) {
        cout << label << " ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap orderHeap;
    int initialOrders[] = {100, 50, 75, 60};
    int n = 4;
    orderHeap.buildHeap(initialOrders, n);
    cout << "Initial Heap (built from array): ";
    orderHeap.display("");
    orderHeap.insert(55);
    cout << "Heap after insertion of 55: ";
    orderHeap.display("");
    int executedOrder = orderHeap.removeMin();
    cout << "Heap after execution: ";
    orderHeap.display("");
}