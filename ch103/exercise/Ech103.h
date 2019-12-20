//
// 第1.3章习题
// Created by y00455335 on 2019/12/19.
//

#ifndef ALGORITHMS_SEDGEWICK_ECH103_H
#define ALGORITHMS_SEDGEWICK_ECH103_H

#include <string>

class Ech103 {
public:
    /**
     * @brief Complete brackets for expression to complete in-orderExpression
     * @param expression
     * @return the full in-order expression string
     */
    std::string GetInOrderExpression(const std::string &expression);

private:
    std::string GetStringFromChar(char c);

    bool IsDigit(char c);
};


#endif //ALGORITHMS_SEDGEWICK_ECH103_H
