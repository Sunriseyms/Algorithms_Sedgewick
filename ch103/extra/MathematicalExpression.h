//
// 数学表达式的前序、中序、后序表示方法；前序：波兰表示法、后序：逆波兰表示法
// 中序表示转换为前序表示，中序转化为后序
// Created by y00455335 on 2019/12/18.
//

#ifndef ALGORITHMS_SEDGEWICK_MATHEMATICALEXPRESSION_H
#define ALGORITHMS_SEDGEWICK_MATHEMATICALEXPRESSION_H

#include <string>

class MathematicalExpression {
public:
    MathematicalExpression(const std::string &expression) : inorderExpression(expression) {};

    /**
    * @brief : Convert inorderExpression to PreExpression
    * @param [in]  : inorderExpression
    * @param [out] :
    * @return : PreExpression string.
    */
    std::string GetPreExpression();

    /**
     * @brief : Convert inorderExpression to PostExpression
     * @param [in]  : inorderExpression
     * @param [out] :
     * @return : PostExpression string.
     */
    std::string GetPostExpression();

private:
    std::string inorderExpression;

    /**
     * @brief: judge the character is or not digit(0，1,2,3,4,5,6,7,8,9）
     * @param [in]: character c
     * @param [out]:
     * @return: true or false
     */
    bool IsDigit(char c);

    bool IsOperator(const std::string &str);

    /**
    * @brief: judge who has more priority between operator a and operator b, if same priority, return true;
    * @param [in]: character a, character b
    * @param [out]:
    * @return: if a's priority lower than b, return false, else return true.
    */
    bool IsHighPriorityForPre(char a, char b);

    /**
    * @brief: judge who has more priority between operator a and operator b, if same priority, return false;
    * @param [in]: character a, character b
    * @param [out]:
    * @return: if a's priority higher than b, return true, else return false.
    */
    bool IsHighPriorityForPost(char a, char b);

    /**
     * @brief: convert character to string
     * @param [in]: character c
     * @return: convert string
     */
    std::string GetString(char c);
};


#endif //ALGORITHMS_SEDGEWICK_MATHEMATICALEXPRESSION_H
