#include "Matrix.h"
#include "MathFilter.h"
#include "Chapter1Sample.h"
#include "ch103/sample/CustomizeStack.h"
#include "ch103/extra/MathematicalExpression.h"
#include <iostream>

int main(int argc, char **argv) {
    // 第一章的一些例子
    Chapter1Sample chapter1Sample;
    //chapter1Sample.Run();

    // 测试自己实现矩阵运算的库
    Matrix matrix;
    //matrix.Run();

    // 1.1.34练习题
    MathFilter mathFilter;
    //mathFilter.Run();

    // 自定义stack
    CustomizeStack<int> stackTest;
    stackTest.push(1);
    stackTest.push(2);
    stackTest.push(3);
    stackTest.pop();
    std::cout << "stackTest's size: " << stackTest.size() << " top: " << stackTest.top() << std::endl;

    // 中序表达式，前序表达式，后序表达式
    const std::string inorderStr = "2+(1+2)*(14-3)/3-2";
    MathematicalExpression mathematicalExpression(inorderStr);
    std::cout << "inorderStr: " << inorderStr <<
              " PreExpression:" << mathematicalExpression.GetPreExpression() <<
              " PostExpression:" << mathematicalExpression.GetPostExpression() << std::endl;

    return 0;
}
