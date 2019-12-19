//
// Created by y00455335 on 2019/12/16.
//

#include "SmartPointDemo.h"
#include <memory>
#include <iostream>

void SmartPointDemo::Demo() {
    std::unique_ptr<int> ptr = std::make_unique<int>();
    if (ptr) {
        std::cout << "ptr is true" << std::endl;
    } else {
        std::cout << "ptr is false" << std::endl;
    }
    *ptr = 3;
    std::cout << "ptr: " << *ptr << std::endl;
}
