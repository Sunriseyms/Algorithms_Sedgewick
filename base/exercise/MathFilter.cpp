//
// Created by y00455335 on 2019/12/5.
//

#include "MathFilter.h"
#include <iostream>

void MathFilter::Run() {

}

void MathFilter::PrintMaxAndMinNum() {
    int maxNum = INT_MIN;
    int minNUm = INT_MAX;
    int temp;
    while (cin >> temp) {
        maxNum = maxNum > temp ? maxNum : temp;
    }

}
