//
// Created by y00455335 on 2019/12/16.
//

#ifndef ALGORITHMS_SEDGEWICK_CUSTOMIZESTACK_H
#define ALGORITHMS_SEDGEWICK_CUSTOMIZESTACK_H

#include <memory>

template<class T>
class CustomizeStack {
public:
    bool isEmpty();

    int size();

    void push(T item);

    T top();

    void pop();

private:
    class Node {
    public:
        T item;
        Node *next;
    };

    Node *first;
    int N = 0;
};

template<class T>
bool CustomizeStack<T>::isEmpty() {
    return first == nullptr;
}

template<class T>
int CustomizeStack<T>::size() {
    return N;
}

template<class T>
void CustomizeStack<T>::push(T item) {
    Node *newItem = new Node();
    newItem->item = item;
    Node *oldFirst = first;
    first = newItem;
    first->next = oldFirst;
    N++;
}

template<class T>
T CustomizeStack<T>::top() {
    return first->item;
}

template<class T>
void CustomizeStack<T>::pop() {
    Node *oldFirst = first;
    first = first->next;
    free(oldFirst);
    oldFirst = nullptr;
    N--;
}

#endif //ALGORITHMS_SEDGEWICK_CUSTOMIZESTACK_H
