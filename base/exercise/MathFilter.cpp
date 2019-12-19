//
// Created by y00455335 on 2019/12/5.
//

#include "MathFilter.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void MathFilter::Run() {
    std::cout << "----------MathFilter begin----------" << std::endl;
    //PrintMaxAndMinNum();
    //PrintMedian();
    //PrintkthMinNum();
    //PrintSumOfSquare();
    //PrintSumOfSquare();
    PrintAverageNum();
    std::cout << "----------MathFilter end----------" << std::endl;
}

void MathFilter::ResetCin() {
    std::cin.ignore(INT_MAX);
    std::cin.clear();
    std::cin.sync();
}

void MathFilter::PrintMaxAndMinNum() {
    int maxNum = INT_MIN;
    int minNum = INT_MAX;
    int inputNum;
    std::cout << "Please input nums(will return the Max and min value)" << std::endl;
    while (std::cin >> inputNum) {
        maxNum = maxNum > inputNum ? maxNum : inputNum;
        minNum = minNum < inputNum ? minNum : inputNum;
    }
    std::cout << "Max:" << maxNum << " Min:" << minNum << std::endl;
    ResetCin();
}

void MathFilter::PrintMedian() {
    int median = 0;
    std::vector<int> inputVec;
    int inputNum;
    std::cout << "Please input nums(will return the median)" << std::endl;
    while (std::cin >> inputNum) {
        inputVec.push_back(inputNum);
    }

    std::sort(inputVec.begin(), inputVec.end());
    int inputVecSize = inputVec.size();
    if (inputVecSize == 0) {
        std::cout << "please input nums" << std::endl;
    }

    if (inputVecSize == 1) {
        median = inputVec[0];
    } else if (inputVecSize % 2 == 0) {
        median = (inputVec[inputVecSize / 2] + inputVec[(inputVecSize / 2) - 1]) / 2;
    } else {
        median = inputVec[(inputVecSize - 1) / 2];
    }
    std::cout << "the median is " << median << std::endl;
    ResetCin();
}

void MathFilter::PrintkthMinNum() {
    std::cout << "Please input nums and k, will return the kth number" << std::endl;
    std::vector<int> inputVec;
    int inputNum;
    int k;
    int kThNum;
    while (std::cin >> inputNum) {
        inputVec.push_back(inputNum);
    }
    ResetCin();
    std::cout << "please input a number(k)" << std::endl;
    std::cin >> k;
    if (k > inputVec.size()) {
        std::cout << "Error: the k large than inputVec's size " << std::endl;
    }
    std::nth_element(inputVec.begin(), inputVec.begin() + k - 1, inputVec.end(),
                     [](int i, int j) -> bool { return (i < j); });
    kThNum = inputVec[k - 1];
    std::cout << "kth nums is " << kThNum << std::endl;
}

void MathFilter::PrintSumOfSquare() {
    int sumOfSquare = 0;
    int inputNum;
    std::cout << "please input nums(will return sum of each number's square)" << std::endl;
    while (std::cin >> inputNum) {
        sumOfSquare += (inputNum * inputNum);
    }
    std::cout << "the sum of each number's square is " << sumOfSquare << std::endl;
    ResetCin();
}

void MathFilter::PrintAverageNum() {
    int averageNum = 0;
    int inputSize = 0;
    int inputNum;
    int sumNum = 0;
    std::cout << "Please input the numbers, will return the average of numbers." << std::endl;
    while (std::cin >> inputNum) {
        sumNum += inputNum;
        inputSize++;
    }
    averageNum = sumNum / inputSize;
    std::cout << "The average of numbers is " << averageNum << std::endl;
    ResetCin();

}

void MathFilter::PrintPercentOfLargerThanAverage() {
    double averageNum = 0;
    int inputNum;
    int sumNum = 0;
    std::vector<int> inputVec;
    std::cout << "Please input the numbers, will return the average of numbers." << std::endl;
    while (std::cin >> inputNum) {
        sumNum += inputNum;
        inputVec.push_back(inputNum);
    }
    averageNum = sumNum / inputVec.size();
    std::cout << "The average of numbers is " << averageNum << std::endl;


}


