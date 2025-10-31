#include <iostream>
#include <string>

using namespace std;

struct Order {
    int orderID;
    string Name;
    double Price;
};

int partition(Order arr[], int low, int high) {
    double pivot = arr[high].Price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].Price <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Order arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Order orders[5] = {
        {101, "John", 250},
        {102, "Alice", 150.15},
        {103, "Patel", 500},
        {104, "Jones", 200.05},
        {105, "Alex", 175}
    };
    quickSort(orders, 0, 4);
    cout << "Sorted orders: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "OrderID: " << orders[i].orderID << ", Customer: " << orders[i].Name << ", Price: " << orders[i].Price << endl;
    }
}