#include <iostream>
#include <stack>

using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(NULL) {}
};

void addToHistory(Node*& head, string url) {
    Node* newNode = new Node(url);
    newNode->next = head;
    head = newNode;
}

void removeFromHistory(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

int main() {
    stack<string> browserHistory;
    Node* historyHead = NULL;
    string visitedSites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (string site : visitedSites) {
        addToHistory(historyHead, site);
        browserHistory.push(site);
    }
    browserHistory.pop();
    removeFromHistory(historyHead);
    browserHistory.pop();
    removeFromHistory(historyHead);
    if (!browserHistory.empty()) {
        cout << "Current page: " << browserHistory.top() << endl;
    } else {
        cout << "No more history!" << endl;
    }
    cout << "Visited sites (most recent first):\n";
    for (Node* current = historyHead; current; current = current->next)
        cout << current->url << " ";

    cout << endl;
}
