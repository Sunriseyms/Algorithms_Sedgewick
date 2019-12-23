#include "Matrix.h"
#include "MathFilter.h"
#include "Chapter1Sample.h"
#include "ch103/sample/CustomizeStack.h"
#include "ch103/extra/MathematicalExpression.h"
#include "ch103/exercise/Ech103.h"
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
    //const std::string inorderStr = "2+(1+2)*(14-3)/3-2";
    //MathematicalExpression mathematicalExpression(inorderStr);
    //std::cout << "inorderStr: " << inorderStr <<
    //          " PreExpression:" << mathematicalExpression.GetPreExpression() <<
    //          " PostExpression:" << mathematicalExpression.GetPostExpression() << std::endl;

    Ech103 ech103;
    std::cout << ech103.Ech10309GetInOrderExpression("1+2)*3-4)*5-6)))") << std::endl;

    std::cout << "the kth last in input: " << ech103.Ech10315GetkthLastElementInInput(5) << std::endl;

    ech103.Ech10337Josephus(7, 2);
    return 0;
}
