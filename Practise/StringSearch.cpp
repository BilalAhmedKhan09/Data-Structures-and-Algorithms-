#include<iostream>
#include<string>

using namespace std;

void search(string s, string t){
    int m = s.length();
    int n = t.length();
    int count = 0;
    for(int i=0; i<=m-n;i++){
        int j=0;
        while (j < n && s[i + j] == t[j]) {
            j++;
        }
        if (j == n) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main(){
    string s = "Helloello";
    string t = "ello";
    search(s,t);
}