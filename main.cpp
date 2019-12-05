#include "base/exercise/Matrix.h"
#include "Chapter1Sample.h"

int main(int argc, char **argv) {
    // 第一章的一些例子
    Chapter1Sample chapter1Sample;
    chapter1Sample.Run();

    // 测试自己实现矩阵运算的库
    Matrix matrix;
    matrix.Run();

    return 0;
}
