#include<iostream>

using namespace std;

void sumdig(int n, int sum){
    if(n != 0){
        sum += n % 10;
        sumdig(n/10,sum);
    }
    else if(sum >= 10){
        sumdig(sum,0);
    }
    else{
        cout<<sum<<endl;
    }
}

int main(){
    sumdig(9875, 0);
}