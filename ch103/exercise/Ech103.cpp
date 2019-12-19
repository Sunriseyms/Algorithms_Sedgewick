//
// Created by y00455335 on 2019/12/19.
//

#include "Ech103.h"
#include <algorithm>
#include <stack>

/**
 * @brief Complete brackets for expression to complete in-orderExpression
 * @param expression
 * @return the full in-order expression string
 */
std::string Ech103::GetInOrderExpression(const std::string &expression) {
    //std::string tempStr = expression;
    //std::reverse(tempStr.begin(), tempStr.end());

    std::stack<std::string> expressionStack;
    int i = 0;
    while (i < expression.size()) {
        if (IsDigit(expression[i])) {
            std::string num;
            while (IsDigit(expression[i])) {
                num += expression[i];
                i++;
            }
            //std::reverse(num.begin(), num.end());
            expressionStack.push(num);
            continue;
        } else {
            expressionStack.push(GetStringFromChar(expression[i]));
        }
        i++;
    }
    std::stack<std::string> opsStack;
    std::stack<std::string> dataStack;
    int rightBracketsCountInopsStack = 0;
    while (!expressionStack.empty()) {
        if (expressionStack.top() == ")") {
            opsStack.push(expressionStack.top());
            expressionStack.pop();
            rightBracketsCountInopsStack++;
        } else if (IsOps(expressionStack.top())) {
            if (opsStack.empty() || opsStack.top() == ")") {
                opsStack.push(expressionStack.top());
                expressionStack.pop();
            } else {
                std::stack<std::string> operand1;
                std::stack<std::string> operand2;
                while (true) {
                    if ()
                }
            }
        }
    }

    return std::__cxx11::string();
}

std::string Ech103::GetStringFromChar(char c) {
    std::string result(1, c);
    return result;
}

bool Ech103::IsDigit(char c) {
    return c >= '0' && c <= '9';
}

bool Ech103::IsHighPriority(const std::string &ops1, const std::string &ops2) {
    return true;
}

bool Ech103::IsOps(const std::string &str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}
