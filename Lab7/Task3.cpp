#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool availability;
    
    Product(string n, double p, string d, bool a) : name(n), price(p), description(d), availability(a) {}
};

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        double pivot = arr[high].price;
        int i = low - 1;  
        for (int j = low; j < high; j++) {
            if (arr[j].price <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayProducts(Product arr[], int size) {
    cout << "\nSorted Products by Price:\n";
    for (int i = 0; i < size; i++) {
        cout << "Name: " << arr[i].name << "\n";
        cout << "Price: " << arr[i].price << "\n";
        cout << "Description: " << arr[i].description << "\n";
        cout << "Availability: " << (arr[i].availability ? "In Stock" : "Out of Stock") << "\n";
       
    }
}

int main() {
    Product products[3] = {
        Product("Laptop", 999.99, "High performance gaming laptop", true),
        Product("Smartphone", 699.99, "Latest model with 5G", true),
        Product("Headphones", 149.99, "Wireless headphones", false)
    };
    quickSort(products, 0, 2);
    displayProducts(products, 3);
}