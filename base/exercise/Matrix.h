//
// Created by y00455335 on 2019/12/3.
// 1.1.33 矩阵库的实现
//

#ifndef ALGORITHMS_SEDGEWICK_MATRIX_H
#define ALGORITHMS_SEDGEWICK_MATRIX_H

#include <vector>

class Matrix {
public:
    void Run();

private:
    double dot(const std::vector<double> &x, const std::vector<double> &y);

    std::vector<std::vector<double>>
    mult(const std::vector<std::vector<double>> &x, const std::vector<std::vector<double>> &y);

    std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>> &x);

    std::vector<double> mult(const std::vector<double> &x, const std::vector<std::vector<double>> &y);
};

#endif //ALGORITHMS_SEDGEWICK_MATRIX_H
