#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;

    return 0;
}

bool rightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result;

    for (char ch : exp) {

        if (ch == ' ')
            continue;

        if (isalnum(static_cast<unsigned char>(ch))) {
            result += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }

            if (s.empty())
                throw invalid_argument("Mismatched parentheses");

            s.pop();
        }

        else {
            while (!s.empty() && s.top() != '(' &&
                  (precedence(s.top()) > precedence(ch) ||
                  (precedence(s.top()) == precedence(ch) &&
                   !rightAssociative(ch)))) {

                result += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        if (s.top() == '(')
            throw invalid_argument("Mismatched parentheses");

        result += s.top();
        s.pop();
    }

    return result;
}

int main() {
    string exp = "(x+y)/(z*8)";

    cout << infixToPostfix(exp);

    return 0;
}