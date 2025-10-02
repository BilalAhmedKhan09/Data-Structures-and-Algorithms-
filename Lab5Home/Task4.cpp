#include<iostream>

using namespace std;

int solutionCount=0;

bool Placement(char**arr,int size,int row,int placed){
    if(placed==size){
        solutionCount++;
        cout<<"Solution "<<solutionCount<<":\n";
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    if(row>=size){
        return false;
    }
    for(int col=0;col<size;col++){
        bool safe = true;
        for(int i=0;i<row;i++){
            if(arr[i][col]=='Q'){
                safe = false;
                break;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(arr[i][j]=='Q'){
                safe = false;
                break;
            }
        }
        for(int i=row-1,j=col+1;i>=0&&j<size;i--,j++){
            if(arr[i][j]=='Q'){
                safe = false;
                break;
            }
        }
        if(safe){
            arr[row][col] = 'Q';
            Placement(arr,size,row+1,placed+1);
            arr[row][col] = '.';
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    char**arr=new char*[n];
    for(int i=0;i<n;i++){
        arr[i]=new char[n];
        for(int j=0;j<n;j++){
            arr[i][j]='.';
        }
    }
    Placement(arr,n,0,0);
    cout<<"Total solutions = "<<solutionCount<<endl;
    for(int i=0;i<n;i++){
        delete[] arr[i];
    }
    delete[] arr;
}
