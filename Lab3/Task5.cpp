#include <iostream>

using namespace std;

class Node{
public:
    string data;
    Node* next;

    Node(string val) : data(val), next(NULL) {}
};

class musicPlaylistManager{
private:
    Node* head;
public:
    musicPlaylistManager() : head(NULL) {}
    void addSong(string songName) {
        Node* newNode = new Node(songName);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void playingSongs(){
        if (!head) {
            cout << "Playlist is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)" << endl;
    }

    ~musicPlaylistManager() {
        if (!head) return;
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        head = NULL;
    }
};  

int main(){
    musicPlaylistManager playlist;
    playlist.addSong("Hallelujah by Jeff Buckley");
    playlist.addSong("Mountain of Mourne by Don McLean");
    playlist.addSong("Crossroads by Don McLean");
    playlist.addSong("Night We Met by Lord Huron");
    playlist.playingSongs();
}