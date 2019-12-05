//
// Created by y00455335 on 2019/12/3.
//

#include "Matrix.h"
#include <iostream>
#include <algorithm>

double Matrix::dot(const std::vector<double> &x, const std::vector<double> &y) {
    double result = 0.0;
    if (x.size() != y.size()) {
        std::cout << "x's size(" << x.size() << ") is not equal with y's size(" << y.size() << ". x y cannot dot"
                  << std::endl;
        return result;
    } else {
        for (int i = 0; i < x.size(); i++) {
            result += (x[i] * y[i]);
        }
    }
    return result;
}

std::vector<std::vector<double>>
Matrix::mult(const std::vector<std::vector<double>> &x, const std::vector<std::vector<double>> &y) {
    std::vector<std::vector<double>> result;
    if (x.empty() || y.empty()) {
        return result;
    }
    int xColumn = x[0].size();
    int yRows = y.size();
    if (xColumn != yRows) {
        std::cout << "x's column(" << xColumn << ") is not equal y's row(" << yRows << ")" << std::endl;
        return result;
    } else {
        result.resize(x.size());
        for (int i = 0; i < x.size(); ++i) {
            for (int j = 0; j < y[0].size(); ++j) {
                double tempSum = 0;
                for (int k = 0; k < xColumn; ++k) {
                    tempSum += (x[i][k] * y[k][j]);
                }
                result[i].push_back(tempSum);
            }
        }
    }
    return result;
}

std::vector<std::vector<double>> Matrix::transpose(const std::vector<std::vector<double>> &x) {
    int xRows = x.size();
    int xColumn = x[0].size();
    std::vector<std::vector<double>> result;
    result.resize(xColumn);
    for (int i = 0; i < xColumn; ++i) {
        for (int j = 0; j < xRows; ++j) {
            result[i].push_back(x[j][i]);
        }
    }
    return result;
}

std::vector<double> Matrix::mult(const std::vector<double> &x, const std::vector<std::vector<double>> &y) {
    std::vector<double> result;
    if (x.empty() || y.empty() || (x.size() != y.size())) {
        return result;
    }

    for (int i = 0; i < y[0].size(); ++i) {
        double sum = 0;
        for (int j = 0; j < x.size(); ++j) {
            sum += x[j] * y[j][i];
        }
        result.push_back(sum);
    }

    return result;
}

void Matrix::Run() {
    std::cout << "----------Matrix begin----------" << std::endl;
    // 点乘
    std::vector<double> v1 = {0.01, 0.02};
    std::vector<double> v2 = {1, 2};
    double v1Dotv2;
    v1Dotv2 = dot(v1, v2);
    std::cout << "v1 dot v2: " << v1Dotv2 << std::endl;
    // 矩阵之积
    std::vector<std::vector<double>> v11 = {{1, 2},
                                            {3, 4}};
    std::vector<std::vector<double>> v22 = {{1, 2},
                                            {3, 4}};
    std::vector<std::vector<double>> v33;
    v33 = mult(v11, v22);
    std::cout << "v11*v22=v33: " << std::endl;
    for (int i = 0; i < v33.size(); ++i) {
        for (int j = 0; j < v33[0].size(); ++j) {
            std::cout << v33[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // 转置矩阵
    std::vector<std::vector<double>> v111 = {{1, 2},
                                             {3, 4}};
    std::vector<std::vector<double>> v333;
    v333 = transpose(v111);
    std::cout << "v111's transpose v333: " << std::endl;
    for (int i = 0; i < v333.size(); ++i) {
        for (int j = 0; j < v333[0].size(); ++j) {
            std::cout << v333[i][j] << " ";
        }
        std::cout << std::endl;
    }
    // 向量和矩阵之积
    std::vector<std::vector<double>> v1111 = {{1, 2},
                                              {3, 4}};
    std::vector<double> v2222 = {1, 2};
    std::vector<double> v3333 = mult(v2222, v1111);
    std::cout << "v2222 * v1111 = v3333: " << std::endl;
    std::for_each(v3333.begin(), v3333.end(), [](double elem) { std::cout << elem << " "; });
    std::cout << "----------Matrix begin----------\n" << std::endl;
}
