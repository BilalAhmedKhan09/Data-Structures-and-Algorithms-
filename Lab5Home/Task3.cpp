#include<iostream>

using namespace std;

bool Traverse(int x, int y, int arr[7][7], int sol[7][7]){
    if(x==6 && y==6){
        sol[x][y] = 1;
        return true;
    }
    else if(arr[x][y] != 0 && x<7 && y<7){
        sol[x][y] = 1;
        if(x<6 && Traverse(x+1,y,arr,sol)){
            return true;
        }
        else if(y<6 && Traverse(x,y+1,arr,sol)){
            return true;
        }
        else if(x>0 && Traverse(x-1,y,arr,sol)){
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
     int arr[7][7] = {
        {1,0,1,1,1,0,1},
        {1,1,1,0,1,1,1},
        {0,1,0,1,0,1,0},
        {1,1,1,1,1,0,1},
        {0,0,0,0,1,1,1},
        {1,1,1,0,1,0,1},
        {0,0,1,1,1,1,1}
    };
    int sol[7][7] = {0};
    if (Traverse(0, 0, arr, sol)) {
        cout << "Path found:\n";
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No path exists.\n";
    }
}