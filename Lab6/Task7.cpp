
#include <iostream>
#include <queue>

using namespace std;

class Patron {
    string name;
public:
    Patron(string name = "") : name(name) {}
    string getName() const { return name; }
};

int main() {
    queue<Patron> q;
    int enter = 0;
    while (enter != -1) {
        cout << "\n1 to add patron\n2 to serve patron\n3 to show queue\n-1 to exit\n";
        cin >> enter;
        switch (enter) {
            case 1: {
                string name;
                cout << "enter patron name: ";
                cin >> name;
                q.push(Patron(name));
                break;
            }
            case 2: {
                if (!q.empty()) {
                    cout << "Serving: " << q.front().getName() << endl;
                    q.pop();
                } else cout << "No patrons in queue\n";
                break;
            }
            case 3: {
                if (q.empty()) cout << "No patrons waiting\n";
                else {
                    queue<Patron> temp = q;
                    cout << "Current queue:\n";
                    while (!temp.empty()) {
                        cout << temp.front().getName() << endl;
                        temp.pop();
                    }
                }
                break;
            }
            case -1:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid input\n";
        }
    }
}
