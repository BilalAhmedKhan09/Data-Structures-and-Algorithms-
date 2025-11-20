#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

struct MaxHeap {
    int arr[MAX_SIZE];
    int size;
    MaxHeap() : size(0) {}
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void siftUp(int i) {
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void siftDown(int i) {
        int maxIndex = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && arr[left] > arr[maxIndex]) {
            maxIndex = left;
        }
        if (right < size && arr[right] > arr[maxIndex]) {
            maxIndex = right;
        }

        if (i != maxIndex) {
            swap(arr[i], arr[maxIndex]);
            siftDown(maxIndex);
        }
    }

    void insert(int key) {
        if (size < MAX_SIZE) {
            arr[size] = key;
            size++;
            siftUp(size - 1);
        }
    }

    int removeMax() {
        if (size == 0) return -1;
        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        siftDown(0);
        return root;
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
    MaxHeap patientHeap;
    patientHeap.insert(5);
    patientHeap.insert(8);
    patientHeap.insert(3);
    patientHeap.display("");
    patientHeap.insert(10);
    cout << "Heap after insertion of 10: ";
    patientHeap.display("");
    cout << "2. The patient with the highest severity is treated (removed)." << endl;
    int removedSeverity = patientHeap.removeMax();
    cout << "Heap after removal: ";
    patientHeap.display("");
}