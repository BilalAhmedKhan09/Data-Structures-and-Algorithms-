#include <iostream>
#include <string>

using namespace std;

struct Runner {
    int time;
    string name;
};

void merge(Runner runners[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner leftRunners[n1], rightRunners[n2];
    for (int i = 0; i < n1; i++)
        leftRunners[i] = runners[left + i];
    for (int i = 0; i < n2; i++)
        rightRunners[i] = runners[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftRunners[i].time <= rightRunners[j].time) {
            runners[k] = leftRunners[i];
            i++;
        } else {
            runners[k] = rightRunners[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        runners[k] = leftRunners[i];
        i++;
        k++;
    }
    while (j < n2) {
        runners[k] = rightRunners[j];
        j++;
        k++;
    }
}

void mergeSort(Runner runners[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(runners, left, mid);
        mergeSort(runners, mid + 1, right);

        merge(runners, left, mid, right);
    }
}

int main() {
    Runner runners[10] = {
        {120, "John"},
        {110, "Alice"},
        {130, "Bob"},
        {115, "Charlie"},
        {105, "Adam"},
    };
    mergeSort(runners, 0, 9);
    for (int i = 0; i < 5; i++) {
        cout << runners[i].name << " with time: " << runners[i].time << " seconds\n";
    }
}