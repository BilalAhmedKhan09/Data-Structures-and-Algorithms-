#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int main() {
    string expression = "23*54*+9-";
    stack<int> st;
    for (int i = 0; i < expression.size(); i++) {
        char c = expression[i];

        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            if (st.size() < 2) {
                cerr << "Error: Not enough operands in the stack for operation " << c << endl;
                return 1;
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            switch(c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': 
                    if (b == 0) {
                        cerr << "Error: Division by zero." << endl;
                        return 1;
                    }
                    st.push(a / b); 
                    break;
                case '^': st.push(pow(a, b)); break;
            }
        }
    }
    if (st.size() != 1) {
        cerr << "Error: Invalid expression." << endl;
        return 1;
    }
    cout << "Result: " << st.top() << endl;
    return 0;
}
