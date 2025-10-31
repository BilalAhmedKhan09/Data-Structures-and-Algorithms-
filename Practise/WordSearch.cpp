#include<iostream>
#include<string>

using namespace std; 

bool search(char arr[5][5],int arr2[5][5], int i, int j,string word, int count){
    if(count == word.length()){
        cout<<"Found"<<endl;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cout<<arr2[i][j];
            }
            cout<<endl;
        }
        return true;
    }
    if(i >= 5 || j >=5 || i<0 || j<0 || word[count] != arr[i][j] || arr2[i][j] == 1){
        return false;
    }
    arr2[i][j] = 1;
    if(search(arr,arr2,i+1,j,word,count+1)){
        return true;
    }
    else if(search(arr,arr2,i,j+1,word,count+1)){
        return true;
    }
    else if(search(arr,arr2,i-1,j,word,count+1)){
        return true;
    }
    else if(search(arr,arr2,i,j-1,word,count+1)){
        return true;
    }
    arr2[i][j] = 0;
    return false;
}

bool exist(char arr[5][5], string word){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int arr2[5][5] = {};
            if(search(arr,arr2,i,j,word,0)){
                cout<<"Found"<<endl;
            }
        }
    }
    return false;
}

int main(){
    char arr[5][5] = {
    {'P', 'A', 'R', 'R', 'O'},
    {'L', 'I', 'O', 'N', 'E'},
    {'E', 'A', 'T', 'O', 'P'},
    {'R', 'T', 'P', 'A', 'R'},
    {'O', 'N', 'E', 'T', 'L'}
};
exist(arr,"LION");
exist(arr,"EAT");
exist(arr,"PARROT");
}