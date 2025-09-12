#include <iostream>
using namespace std;

void run() {
        int n;
        cout << "Enter number of teams: ";
        cin >> n;

        int** data = new int*[n];
        int* len = new int[n];

        for (int i = 0; i < n; i++) {
            cout << "Enter players in team " << i + 1 << ": ";
            cin >> len[i];
            data[i] = new int[len[i]];

            cout << "Enter scores: ";
            for (int j = 0; j < len[i]; j++) cin >> data[i][j];
        }

        cout << "\nTeam Totals:\n";
        for (int i = 0; i < n; i++) {
            int total = 0;
            for (int j = 0; j < len[i]; j++) total += data[i][j];
            cout << "Team " << i + 1 << ": " << total << '\n';
        }

        for (int i = 0; i < n; i++) delete[] data[i];
        delete[] data;
        delete[] len;
}

int main() {
    run();
}
