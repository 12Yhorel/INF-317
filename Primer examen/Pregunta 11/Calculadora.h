#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int evaluarPostfija(const std::string &exp) {
    std::stack<int> pila;
    std::stringstream ss(exp);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            pila.push(std::stoi(token));
        } else {
            int val2 = pila.top(); pila.pop();
            int val1 = pila.top(); pila.pop();

            switch (token[0]) {
                case '+': pila.push(val1 + val2); break;
                case '-': pila.push(val1 - val2); break;
                case '*': pila.push(val1 * val2); break;
                case '/': pila.push(val1 / val2); break;
            }
        }
    }

    return pila.top();
}
