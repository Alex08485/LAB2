// src/rpn.cpp
#include "rpn.h"
#include <stack>
#include <sstream>
#include <string>
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

double evaluate_rpn(const string& expression) {
    stack<double> stack;
    istringstream iss(expression);
    string token;
    
    while (iss >> token) {
        // Пробуем преобразовать токен в число
        try {
            size_t pos;
            double num = stod(token, &pos);
            if (pos == token.length()) {
                stack.push(num);
                continue;
            }
        } catch (const invalid_argument&) {
            // Не число, продолжаем проверку операторов
        }
        
        // Проверяем операторы
        if (token == "+") {
            if (stack.size() < 2) throw runtime_error("Not enough operands for +");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a + b);
        }
        else if (token == "-") {
            if (stack.size() < 2) throw runtime_error("Not enough operands for -");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a - b);
        }
        else if (token == "*") {
            if (stack.size() < 2) throw runtime_error("Not enough operands for *");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(a * b);
        }
        else if (token == "/") {
            if (stack.size() < 2) throw runtime_error("Not enough operands for /");
            double b = stack.top(); stack.pop();
            if (b == 0) throw runtime_error("Division by zero");
            double a = stack.top(); stack.pop();
            stack.push(a / b);
        }
        else if (token == "^") {
            if (stack.size() < 2) throw runtime_error("Not enough operands for ^");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(pow(a, b));
        }
        else {
            throw runtime_error("Invalid token: " + token);
        }
    }
    
    if (stack.size() != 1) {
        throw runtime_error("Invalid expression - too many operands");
    }
    
    return stack.top();
}