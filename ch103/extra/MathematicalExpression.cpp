//
// Created by y00455335 on 2019/12/18.
//

#include "MathematicalExpression.h"
#include <stack>
#include <algorithm>
#include <iostream>
#include <queue>


/**
* @brief : Convert inorderExpression to PreExpression
* @param [in]  : inorderExpression
* @param [out] :
* @return : PreExpression string.
*/
std::string MathematicalExpression::GetPreExpression() {
    std::string result;
    std::string temp = inorderExpression;
    std::reverse(temp.begin(), temp.end());
    std::stack<char> ops;   // 操作符栈
    std::stack<std::string> data;   // 前序表达式栈
    int i = 0;
    while (i < temp.size()) {
        // 1.当是数字时，将该数字（完整的数字）入data栈
        if (IsDigit(temp[i])) {
            std::string num;
            while (IsDigit(temp[i])) {
                num += temp[i];
                i++;
            }
            std::reverse(num.begin(), num.end());
            data.push(num);
            continue;
        } else if (temp[i] == ')') { // 2. 当是‘）’时，入ops栈
            ops.push(temp[i]);
        } else if (temp[i] == '(') { // 3. 当是‘（’时，将ops栈中的运算符取出并入data栈直到遇到‘）’
            while (ops.top() != ')') {
                data.push(GetString(ops.top()));
                ops.pop();
            }
            ops.pop();
        } else { // 4. 是操作符：+ - * /
            // 4.1 如果ops栈为空， ops栈顶为')', 或者当前操作符比栈顶运算符优先级高，将该运算符入ops栈
            if (ops.empty() || ops.top() == ')' || IsHighPriorityForPre(temp[i], ops.top())) {
                ops.push(temp[i]);
            } else {
                // 4.2 取出ops中的运算符并入data栈直到满足4.1条件后，将该运算符入ops栈
                while (!(ops.empty() || ops.top() == ')' || IsHighPriorityForPre(temp[i], ops.top()))) {
                    data.push(GetString(ops.top()));
                    ops.pop();
                }
                ops.push(temp[i]);
            }
        }
        i++;
    }

    // 将ops栈中的运算符取出并入data栈，此时data栈中就保存了完整的前序表达式
    while (!ops.empty()) {
        data.push(GetString(ops.top()));
        ops.pop();
    }

    std::stack<std::string> calcStack1(data);
    // 将前序表达式拼接到输出字符串中
    while (!data.empty()) {
        result += data.top();
        data.pop();
    }

    // 根据前序表达式，计算结果
    // 1. 反转前序表达式栈
    // 2. 数据栈保存数字，遇到操作符，从数据栈中获取2个数据，使用操作符进行计算，并将结果压入数据栈
    std::stack<std::string> calcStack;
    // 反转前序表达式，并保存到calcStack
    while (!calcStack1.empty()) {
        calcStack.push(calcStack1.top());
        calcStack1.pop();
    }
    std::stack<std::string> calcData;
    while (!calcStack.empty()) {
        // 如果是操作符，从数据栈上获取两个操作数（出栈）与操作符一起进行计算，并将结果压入数据栈
        if (IsOperator(calcStack.top())) {
            int operand1;
            int operand2;
            int r;
            operand1 = std::stoi(calcData.top());
            calcData.pop();
            operand2 = std::stoi(calcData.top());
            calcData.pop();
            if (calcStack.top() == "+") {
                r = operand1 + operand2;
            } else if (calcStack.top() == "-") {
                r = operand1 - operand2;
            } else if (calcStack.top() == "*") {
                r = operand1 * operand2;
            } else if (calcStack.top() == "/") {
                r = operand1 / operand2;
            }
            calcStack.pop();
            std::string rStr = std::to_string(r);
            calcData.push(rStr);
        } else { // 如果是数字，将之压入数据栈
            calcData.push(calcStack.top());
            calcStack.pop();
        }
    }
    int calcResult = std::stoi(calcData.top());
    std::cout << "(calcResult: " << calcResult << ")";

    return result;
}

/**
 * @brief : Convert inorderExpression to PostExpression
 * @param [in]  : inorderExpression
 * @param [out] :
 * @return : PostExpression string.
 */
std::string MathematicalExpression::GetPostExpression() {
    std::string result;
    std::queue<std::string> data; // 此处使用队列，方便输出后序表达式
    std::stack<char> ops;
    int i = 0;
    while (i < inorderExpression.size()) {
        // 1. 如果是数字，将它压入数据队列
        if (IsDigit(inorderExpression[i])) {
            std::string num;
            while (i < inorderExpression.size() && IsDigit(inorderExpression[i])) {
                num += GetString(inorderExpression[i]);
                i++;
            }
            data.push(num);
            continue;
        } else if (inorderExpression[i] == '(') { // 2. 如果是(压入操作符栈
            ops.push(inorderExpression[i]);
        } else if (inorderExpression[i] == ')') { // 3. 如果是），将操作符栈的元素入栈到数据队列，直到遇到），）弹出不要
            while (ops.top() != '(') {
                data.push(GetString(ops.top()));
                ops.pop();
            }
            ops.pop();
        } else { // 3. 如果是操作符
            // 3.1. 当操作符栈为空或者栈顶是（，又或者当前操作符的优先级高于栈顶操作符；将该操作符入操作符栈
            if (ops.empty() || ops.top() == '(' || IsHighPriorityForPost(inorderExpression[i], ops.top())) {
                ops.push(inorderExpression[i]);
            } else { // 3.2. 将操作符栈中的操作符入到数据队列，直到满足3.1后，将操作符入操作符栈
                while (!(ops.empty() || ops.top() == '(' || IsHighPriorityForPost(inorderExpression[i], ops.top()))) {
                    data.push(GetString(ops.top()));
                    ops.pop();
                }
                ops.push(inorderExpression[i]);
            }
        }
        i++;
    }

    // 将操作符栈中的操作符，压入到数据队列
    while (!ops.empty()) {
        data.push(GetString(ops.top()));
        ops.pop();
    }
    std::stack<std::string> calcStack1;
    while (!data.empty()) {
        result += data.front();
        calcStack1.push(data.front());
        data.pop();
    }

    std::stack<std::string> calcStack;
    while (!calcStack1.empty()) {
        calcStack.push(calcStack1.top());
        calcStack1.pop();
    }

    std::stack<std::string> calcData;
    while (!calcStack.empty()) {
        if (IsOperator(calcStack.top())) {
            int operand1;
            int operand2;
            int r;
            operand2 = std::stoi(calcData.top());
            calcData.pop();
            operand1 = std::stoi(calcData.top());
            calcData.pop();

            if (calcStack.top() == "+") {
                r = operand1 + operand2;
            } else if (calcStack.top() == "-") {
                r = operand1 - operand2;
            } else if (calcStack.top() == "*") {
                r = operand1 * operand2;
            } else if (calcStack.top() == "/") {
                r = operand1 / operand2;
            }

            calcStack.pop();
            std::string rStr = std::to_string(r);
            calcData.push(rStr);
        } else {
            calcData.push(calcStack.top());
            calcStack.pop();
        }
    }

    int calcResult = std::stoi(calcData.top());
    std::cout << "(calcResult: " << calcResult << ")";


    return result;
}

/**
 * @brief: judge the character is or not digit(0，1,2,3,4,5,6,7,8,9）
 * @param [in]: character c
 * @param [out]:
 * @return: true or false
 */
bool MathematicalExpression::IsDigit(char c) {
    return c >= '0' && c <= '9';
}

/**
* @brief: judge who has more priority between operator a and operator b, if same priority, return true;
* @param [in]: character a, character b
* @param [out]:
* @return: if a's priority lower than b, return false, else return true.
*/
bool MathematicalExpression::IsHighPriorityForPre(char a, char b) {
    if (b == '+' || b == '-') {
        return true;
    } else {
        return !(a == '+' || a == '-');
    }
}

/**
 * @brief: convert character to string
 * @param [in]: character c
 * @return: convert string
 */
std::string MathematicalExpression::GetString(char c) {
    std::string str(1, c);
    return str;
}

bool MathematicalExpression::IsOperator(const std::string &str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

bool MathematicalExpression::IsHighPriorityForPost(char a, char b) {
    return b == '+' || b == '-' ? !(a == '+' || a == '-') : false;
}































