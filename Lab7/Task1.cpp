#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct StudentNode {
    std::string name;
    int score;
    StudentNode* next;
};

void insert(StudentNode*& head, const std::string& name, int score) {
    StudentNode* newNode = new StudentNode;
    newNode->name = name;
    newNode->score = score;
    newNode->next = head;
    head = newNode;
}

void displayList(StudentNode* head) {
    StudentNode* current = head;
    while (current != nullptr) {
        cout << current->name << ": " << current->score << endl;
        current = current->next;
    }
}

void sortPass(StudentNode*& head, int divisor) {
    StudentNode* buckets[10] = {nullptr};
    StudentNode* tailBuckets[10] = {nullptr};
    StudentNode* current = head;
    head = nullptr;

    while (current != nullptr) {
        StudentNode* nextNode = current->next;
        int digit = (current->score / divisor) % 10;
        current->next = nullptr;
        
        if (buckets[digit] == nullptr) {
            buckets[digit] = current;
            tailBuckets[digit] = current;
        } else {
            tailBuckets[digit]->next = current;
            tailBuckets[digit] = current;
        }
        current = nextNode;
    }

    for (int i = 0; i < 10; ++i) {
        if (buckets[i] != nullptr) {
            if (head == nullptr) {
                head = buckets[i];
                current = tailBuckets[i];
            } else {
                current->next = buckets[i];
                current = tailBuckets[i];
            }
        }
    }
}

void radixSort(StudentNode*& head) {
    int maxDigits = 3;
    int divisor = 1;
    for (int i = 0; i < maxDigits; ++i) {
        sortPass(head, divisor);
        divisor *= 10;
    }
}

int main() {
    StudentNode* studentList = nullptr;
    insert(studentList, "Alice", 95);
    insert(studentList, "Bob", 42);
    insert(studentList, "Charlie", 100);
    insert(studentList, "David", 12);
    insert(studentList, "Patel", 78);
    insert(studentList, "Javed", 3);
    insert(studentList, "Greg", 60);
    insert(studentList, "Memon", 1);
    insert(studentList, "Elsa", 55);
    radixSort(studentList);
    displayList(studentList);
    StudentNode* current = studentList;
    while (current != nullptr) {
        StudentNode* next = current->next;
        delete current;
        current = next;
    }

}
