#include "Matrix.h"
#include "MathFilter.h"
#include "Chapter1Sample.h"
#include "ch103/sample/CustomizeStack.h"
#include "ch103/extra/MathematicalExpression.h"
#include "ch103/exercise/Ech103.h"
#include "RingBufferFullFlag.h"
#include "RingBufferWasteOneSlot.h"
#include "RingBufferMirrorIndicator.h"
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

    //Ech103 ech103;
    //std::cout << ech103.Ech10309GetInOrderExpression("1+2)*3-4)*5-6)))") << std::endl;

    //std::cout << "the kth last in input: " << ech103.Ech10315GetkthLastElementInInput(5) << std::endl;

    // 循环队列：3种实现方式（判断队列为空或满）
    // 1、添加变量(是否为满),来协助判断为空和为满；  2、队列中始终保持一个空元素，进行判断是否为空（头和尾相等）和为满（头尾相邻，头在前）
    // 3、镜像指示位，头尾的最大值是2倍的队列大小（通过判断头尾是否在同一镜像位置来判断为空和为满）； 当队列是2的倍数时，使用位操作，进行判断和向后+1
    // RingBufferFullFlag<int> ringBufferFullFlag(3);
    // ringBufferFullFlag.put(1);
    // ringBufferFullFlag.put(2);
    // ringBufferFullFlag.put(3);
    // ringBufferFullFlag.put(4);
    // ringBufferFullFlag.reset();

    //RingBufferWasteOneSlot<int> ringBufferWasteOneSlot(3);
    //ringBufferWasteOneSlot.put(1);
    //ringBufferWasteOneSlot.put(2);
    //ringBufferWasteOneSlot.put(3);

    // RingBufferMirrorIndicator<int > ringBufferMirrorIndicator(4);
    // ringBufferMirrorIndicator.put(1);
    // ringBufferMirrorIndicator.put(2);
    // ringBufferMirrorIndicator.put(3);
    // ringBufferMirrorIndicator.put(4);
    // ringBufferMirrorIndicator.put(6);
    // ringBufferMirrorIndicator.put(7);
    // ringBufferMirrorIndicator.put(8);
    // ringBufferMirrorIndicator.put(9);
    // ringBufferMirrorIndicator.put(10);
    // ringBufferMirrorIndicator.put(11);

    // std::cout << "get(): " << ringBufferMirrorIndicator.get() << std::endl;

    ech103.Ech10337Josephus(7, 2);
    return 0;
}
