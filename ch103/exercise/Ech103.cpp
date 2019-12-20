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
    // 算法思想
    // 从头开始遍历表达式
    // 1. 如果是数字，将之压入数据栈
    // 2. 如果是操作符，将之压入操作符栈
    // 3. 如果是），则从数据栈中取出两个操作数，从数据栈中取出操作符，加上（后，安装），第二个操作数，操作符，第一个操作数，（压人数据栈。
    // 最后数据栈中就是补全过后的中序表达式。

    std::stack<std::string> opsStack; // 操作符栈
    std::stack<std::string> dataStack; // 数据栈
    int i = 0;
    while (i < expression.size()) {
        if (expression[i] == ')') { // 如果是'）'
            std::stack<std::string> operand1; // 操作数1
            std::stack<std::string> operand2; // 操作数2
            std::string op; // 操作符

            // 依次获取操作数1 操作符 操作数2
            if (dataStack.top() != ")") { // 数字
                // 获取操作数1
                operand1.push(dataStack.top());
                dataStack.pop();

                // 获取操作符
                if (opsStack.empty()) {
                    op = dataStack.top();
                    dataStack.pop();
                } else {
                    op = opsStack.top();
                    opsStack.pop();
                }

                // 获取操作数2
                if (dataStack.top() == ")") {
                    operand2.push(dataStack.top());
                    dataStack.pop();
                    int leftBracktsCount = 0;
                    int rightBracktsCount = 1;
                    while (leftBracktsCount != rightBracktsCount) {
                        if (dataStack.top() == "(") {
                            leftBracktsCount++;
                        } else if (dataStack.top() == ")") {
                            rightBracktsCount++;
                        }
                        operand2.push(dataStack.top());
                        dataStack.pop();
                    }
                } else {
                    operand2.push(dataStack.top());
                    dataStack.pop();
                }
            } else { // ")"括号
                // 获取操作数1
                operand1.push(dataStack.top());
                dataStack.pop();
                int leftBracktsCount = 0;
                int rightBracktsCount = 1;
                while (leftBracktsCount != rightBracktsCount) {
                    if (dataStack.top() == "(") {
                        leftBracktsCount++;
                    } else if (dataStack.top() == ")") {
                        rightBracktsCount++;
                    }
                    operand1.push(dataStack.top());
                    dataStack.pop();
                }

                // 获取操作符
                if (opsStack.empty()) {
                    op = dataStack.top();
                    dataStack.pop();
                } else {
                    op = opsStack.top();
                    opsStack.pop();
                }

                // 获取操作数2
                if (dataStack.top() == ")") {
                    operand2.push(dataStack.top());
                    dataStack.pop();
                    int leftBracktsCount = 0;
                    int rightBracktsCount = 1;
                    while (leftBracktsCount != rightBracktsCount) {
                        if (dataStack.top() == "(") {
                            leftBracktsCount++;
                        } else if (dataStack.top() == ")") {
                            rightBracktsCount++;
                        }
                        operand2.push(dataStack.top());
                        dataStack.pop();
                    }
                } else {
                    operand2.push(dataStack.top());
                    dataStack.pop();
                }
            }

            // 将‘（’、操作数2、操作符、操作数1、‘）’依次压入数据栈
            dataStack.push("(");
            while (!operand2.empty()) {
                dataStack.push(operand2.top());
                operand2.pop();
            }
            dataStack.push(op);
            while (!operand1.empty()) {
                dataStack.push(operand1.top());
                operand1.pop();
            }
            dataStack.push(GetStringFromChar(expression[i]));
        } else if (IsDigit(expression[i])) { // 是数字
            std::string num;
            while (IsDigit(expression[i])) {
                num += expression[i];
                i++;
            }
            dataStack.push(num);
            continue;
        } else { // 是操作符
            opsStack.push(GetStringFromChar(expression[i]));
        }
        i++;
    }

    // 取出数据栈中元素，拼接到string中（即所需结果）
    std::string result;
    while (!dataStack.empty()) {
        result = dataStack.top() + result;
        dataStack.pop();
    }

    return result;
}

std::string Ech103::GetStringFromChar(char c) {
    std::string result(1, c);
    return result;
}

bool Ech103::IsDigit(char c) {
    return c >= '0' && c <= '9';
}

