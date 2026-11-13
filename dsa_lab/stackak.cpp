#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;

// ================= STACK ADT =================

template <typename T>
class Stack{
private:
    T* S;                 // array to store stack elements
    int capacity;         // maximum capacity
    int t;                // index of top element

public:
    Stack(int cap = 100);
    ~Stack();

    bool empty() const;
    int size() const;
    const T& top() const;

    void push(const T& e);
    void pop();
};

// Constructor
template <typename T>
Stack<T>::Stack(int cap){
    capacity = cap;
    S = new T[capacity];
    t = -1;
}

// Destructor
template <typename T>
Stack<T>::~Stack(){
    delete[] S;
}

// Check whether stack is empty
template <typename T>
bool Stack<T>::empty() const{
    return t == -1;
}

// Return number of elements
template <typename T>
int Stack<T>::size() const{
    return t + 1;
}

// Return top element
template <typename T>
const T& Stack<T>::top() const{
    return S[t];
}

// Push element
template <typename T>
void Stack<T>::push(const T& e){
    if(t == capacity - 1){
        cout << "Stack Overflow!\n";
        return;
    }

    S[++t] = e;
}

// Pop top element
template <typename T>
void Stack<T>::pop(){
    if(empty()){
        cout << "Stack Underflow!\n";
        return;
    }

    t--;
}

// ================= EXPRESSION FUNCTIONS =================

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' ||
           c == '/' || c == '^';
}

int calculate(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
    }

    return 0;
}

int evaluatePostfix(string exp){

    Stack<int> st;

    for(int i = 0; i < exp.length(); i++){

        char c = exp[i];

        // Ignore spaces
        if(c == ' ')
            continue;

        // Operand
        if(isdigit(c)){
            st.push(c - '0');
        }

        // Operator
        else if(isOperator(c)){

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int result = calculate(a,b,c);

            st.push(result);
        }
    }

    return st.top();
}

int evaluatePrefix(string exp){

    Stack<int> st;

    // Scan from right to left
    for(int i = exp.length()-1; i >= 0; i--){

        char c = exp[i];

        // Ignore spaces
        if(c == ' ')
            continue;

        // Operand
        if(isdigit(c)){
            st.push(c - '0');
        }

        // Operator
        else if(isOperator(c)){

            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            int result = calculate(a,b,c);

            st.push(result);
        }
    }
    return st.top();
}

int main(){
    string postfix, prefix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Postfix result = "
         << evaluatePostfix(postfix) << endl;

    cout << "\nEnter prefix expression: ";
    cin >> prefix;

    cout << "Prefix result = "
         << evaluatePrefix(prefix) << endl;
    return 0;
}