#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>

template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i <= topIndex; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    Stack(int cap = 10) : capacity(cap), topIndex(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    bool is_empty() const { return topIndex == -1; }

    void push(const T& x) {
        if (topIndex + 1 == capacity) resize();
        data[++topIndex] = x;
    }

    T pop() {
        if (is_empty()) throw std::underflow_error("Stack is empty");
        return data[topIndex--];
    }

    T top() const {
        if (is_empty()) throw std::underflow_error("Stack is empty");
        return data[topIndex];
    }

    void output() const {
        std::cout << "Stack (top -> bottom): ";
        for (int i = topIndex; i >= 0; i--)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};

// Infix Postfix Prefix

static int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^')              return 3;
    return 0;
}

static bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

static double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::invalid_argument("Division by zero");
            return a / b;
        case '^': {
            double result = 1;
            for (int i = 0; i < (int)b; i++) result *= a;
            return result;
        }
    }
    throw std::invalid_argument("Unknown operator");
}

// Infix to Postfix
inline std::string infixToPostfix(const std::string& infix) {
    Stack<char> opStack;
    std::ostringstream output;
    std::istringstream tokens(infix);
    std::string token;

    while (tokens >> token) {
        if (std::isdigit(token[0])) {
            output << token << " ";
        } else if (token == "(") {
            opStack.push('(');
        } else if (token == ")") {
            while (!opStack.is_empty() && opStack.top() != '(')
                output << opStack.pop() << " ";
            if (!opStack.is_empty()) opStack.pop();
        } else if (token.size() == 1 && isOperator(token[0])) {
            char op = token[0];
            while (!opStack.is_empty() && opStack.top() != '(' &&
                   ((op != '^' && precedence(opStack.top()) >= precedence(op)) ||
                    (op == '^' && precedence(opStack.top()) >  precedence(op))))
            {
                output << opStack.pop() << " ";
            }
            opStack.push(op);
        }
    }
    while (!opStack.is_empty())
        output << opStack.pop() << " ";

    std::string result = output.str();
    if (!result.empty() && result.back() == ' ') result.pop_back();
    return result;
}

// Infix to Prefix
inline std::string infixToPrefix(const std::string& infix) {
    std::istringstream ss(infix);
    std::vector<std::string> toks;
    std::string t;
    while (ss >> t) toks.push_back(t);
    std::reverse(toks.begin(), toks.end());

    for (auto& tok : toks) {
        if (tok == "(") tok = ")";
        else if (tok == ")") tok = "(";
    }

    std::ostringstream rev;
    for (int i = 0; i < (int)toks.size(); i++) {
        rev << toks[i];
        if (i < (int)toks.size() - 1) rev << " ";
    }

    std::string postfix = infixToPostfix(rev.str());

    std::istringstream ps(postfix);
    std::vector<std::string> ptoks;
    while (ps >> t) ptoks.push_back(t);
    std::reverse(ptoks.begin(), ptoks.end());

    std::ostringstream result;
    for (int i = 0; i < (int)ptoks.size(); i++) {
        result << ptoks[i];
        if (i < (int)ptoks.size() - 1) result << " ";
    }
    return result.str();
}

// Evaluate Postfix 
inline double evaluatePostfix(const std::string& postfix) {
    Stack<double> valStack;
    std::istringstream tokens(postfix);
    std::string token;

    while (tokens >> token) {
        if (std::isdigit(token[0])) {
            valStack.push(std::stod(token));
        } else if (token.size() == 1 && isOperator(token[0])) {
            double b = valStack.pop();
            double a = valStack.pop();
            valStack.push(applyOp(a, b, token[0]));
        }
    }
    return valStack.pop();
}

// Evaluate Prefix 
inline double evaluatePrefix(const std::string& prefix) {
    std::istringstream ss(prefix);
    std::vector<std::string> toks;
    std::string t;
    while (ss >> t) toks.push_back(t);

    Stack<double> valStack;
    for (int i = (int)toks.size() - 1; i >= 0; i--) {
        const std::string& token = toks[i];
        if (std::isdigit(token[0])) {
            valStack.push(std::stod(token));
        } else if (token.size() == 1 && isOperator(token[0])) {
            double a = valStack.pop();
            double b = valStack.pop();
            valStack.push(applyOp(a, b, token[0]));
        }
    }
    return valStack.pop();
}
