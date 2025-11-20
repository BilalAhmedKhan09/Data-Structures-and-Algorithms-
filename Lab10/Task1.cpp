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

    void insert(int key) {
        if (size < MAX_SIZE) {
            arr[size] = key;
            size++;
            siftUp(size - 1);
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
    MinHeap packageHeap;
    cout << "Initial Heap: (empty)" << endl;
    packageHeap.insert(2);
    cout << "3. Display updated heap: ";
    packageHeap.display("");
}