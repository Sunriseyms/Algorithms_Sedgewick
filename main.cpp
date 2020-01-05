#include "Matrix.h"
#include "MathFilter.h"
#include "Chapter1Sample.h"
#include "ch103/sample/CustomizeStack.h"
#include "ch103/extra/MathematicalExpression.h"
#include "ch103/exercise/Ech103.h"
#include "RingBufferFullFlag.h"
#include "RingBufferWasteOneSlot.h"
#include "RingBufferMirrorIndicator.h"
#include "LRUCache.h"
#include "SortContinar.h"
#include <iostream>
#include <algorithm>

using  namespace std;

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
    //ech103.Ech10337Josephus(7, 2);

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

    // 简单链表实现的前缀编码
    //Ech10340LRU<int> ech10340Lru;
    //ech10340Lru.insert(1);
    //std::cout << ech10340Lru.get() << std::endl;
    //ech10340Lru.insert(2);
    //std::cout << ech10340Lru.get() << std::endl;
    //ech10340Lru.insert(3);
    //std::cout << ech10340Lru.get() << std::endl;
    //ech10340Lru.insert(2);
    //std::cout << ech10340Lru.get() << std::endl;

    //// map+双向链表实现的完整LRUCache
    //LRUCache<int> lruCache(4);
    //lruCache.put(1, 1);
    //lruCache.put(2, 2);
    //lruCache.put(3, 3);
    //lruCache.put(4, 4);
    //lruCache.put(5, 5);
    //std::cout << lruCache.get(5) << std::endl;

    std::vector<int> input{1,4,5,3,8,2,7,9,6,0};
    cout << "input: ";
    for_each(input.begin(), input.end(), [](int val) {cout << val << " ";});
    cout << endl;
    std::vector<int> chooseSortInput = SortContinar<int>::ChooseSort(input);
    cout << "after choose sort: ";
    for_each(chooseSortInput.begin(), chooseSortInput.end(), [](int val) {cout << val << " ";});
    cout << endl;
    std::vector<int> insertSortInput = SortContinar<int>::InsertSort(input);
    cout << "after insert sort: ";
    for_each(insertSortInput.begin(), insertSortInput.end(), [](int val) {cout << val << " ";});
    cout << endl;
    std::vector<int> shellSortInput = SortContinar<int>::ShellSort(input);
    cout << "after shell sort: ";
    for_each(shellSortInput.begin(), shellSortInput.end(), [](int val) {cout << val << " ";});
    cout << endl;
    return 0;
}
