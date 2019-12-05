//
// Created by y00455335 on 2019/12/5.
//

#include "Chapter1Sample.h"
#include <iostream>
#include <math.h>
#include <algorithm>

int Chapter1Sample::Rank(int key, const std::vector<int> &v) {
    int start = 0;
    int end = v.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (key < v[mid]) {
            end = mid - 1;
        } else if (key > v[mid]) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int Chapter1Sample::Log(int N) {
    int result = 1;
    while (true) {
        int temp = N / 2;
        if (temp <= 1) {
            return result;
        } else {
            N = temp;
            result++;
        }
    }
}

int Chapter1Sample::LargesetCommonDivisor(int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (m % n == 0) return n;

    int q = m % n;
    return LargesetCommonDivisor(n, q);
}

void Chapter1Sample::Run() {
    std::cout << "----------Chapter1Sample begin----------" << std::endl;
    std::vector<int> v{1, 4, 5, 6, 7, 8, 11, 15};
    std::cout << "find 5 in v, the index is : " << Rank(5, v) << std::endl;
    std::cout << "log(8)" << log(8) << "math.Log(8)" << log2(8) << std::endl;

    // 如果下标i，j互质，则将a[i][j]设置为true
    bool a[8][8]{{false}};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j] = LargesetCommonDivisor(i, j) == 1;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << std::boolalpha << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "----------Chapter1Sample end----------\n" << std::endl;
}
