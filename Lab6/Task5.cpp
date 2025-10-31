#include <iostream>
#include <stack>

using namespace std;

int main() {
    string input;
    cout<<"Enter your input: ";
    cin>>input;

    stack<int> st;
    for(int i=input.length()-1;i>=0;i--) {
        if(isdigit(input[i])) st.push(input[i] - '0');
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            switch (input[i]) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    cout<<"\nThe answer is: "<<st.top();
}