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
    std::string Ech10309GetInOrderExpression(const std::string &expression);

    /**
     * @brief get kth last element in input strings; use queue data struct
     * @param k
     * @return kth last string
     */
    std::string Ech10315GetkthLastElementInInput(int k);

    int Ech10337Josephus(int m, int n);

private:
    std::string GetStringFromChar(char c);

    bool IsDigit(char c);
};

// 前缀编码
template<class T>
class Ech10340LRU {
    struct List {
        explicit List(T item) : item_(item), next(nullptr) {};
        T item_;
        List *next;
    };

public:
    void insert(T item);

    T get();
    //bool IsExit(T item);
private:
    List *head_;
};

template<class T>
void Ech10340LRU<T>::insert(T item) {
    List *newNode = new List(item);

    if (head_ == nullptr) {
        head_ = newNode;
    } else {
        if (head_->item_ == item) { // 头重复
            return;
        }

        if (head_->next == nullptr) { // 只包含一个节点
            List *tempHead = head_;
            head_ = newNode;
            head_->next = tempHead;
            return;
        }

        List *fastHead = head_->next;
        List *lowHead = head_;

        bool found = false;
        while (fastHead->next != nullptr) {
            if (fastHead->next->item_ == item) {
                found = true;
                break;
            }
            fastHead = fastHead->next;
            lowHead = lowHead->next;
        }
        if (!found && fastHead->item_ == item) { // 尾重复
            free(lowHead->next);
            lowHead->next = nullptr; // 删除尾节点
        }

        if (found) { // 其他节点重复
            free(fastHead->next);
            fastHead->next = fastHead->next->next;
        }

        // 插入到链表头
        List *tempHead = head_;
        head_ = newNode;
        head_->next = tempHead;
        return;
    }
}

template<class T>
T Ech10340LRU<T>::get() {
    return head_->item_;
}

#endif //ALGORITHMS_SEDGEWICK_ECH103_H
