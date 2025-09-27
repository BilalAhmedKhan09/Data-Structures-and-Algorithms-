#include<iostream>

using namespace std;

bool Traverse(int x, int y, int arr[5][5], int sol[5][5]){
    if(x==4 && y==4){
        sol[x][y] = 1;
        return true;
    }
    else if(arr[x][y] != 0 && x<5 && y<5){
        sol[x][y] = 1;
        if(x<4 && Traverse(x+1,y,arr,sol)){
            return true;
        }
        else if(y<4 && Traverse(x,y+1,arr,sol)){
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    int arr[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}};
    int sol[5][5] = {0};
    if (Traverse(0, 0, arr, sol)) {
        cout << "Path found:\n";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No path exists.\n";
    }
}