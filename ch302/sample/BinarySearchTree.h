/**
* @file BinarySearchTree.h
* Copyright (c) Huawei Technologies Co., Ltd. 2012-2018. All rights reserved.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/


#ifndef ALGORITHMS_SEDGEWICK_BINARYSEARCHTREE_H
#define ALGORITHMS_SEDGEWICK_BINARYSEARCHTREE_H

template <class K, class V>
class BinarySearchTree {
private:
    class Node {
    private:
        K key;
        V value;
        Node* left;
        Node* right;
    public:
        Node(K key, V value) : key(key), value(value){};
    };
    Node* root;

    Node* put(Node* node, K key, V value);
public:
    int size();
    V get(K key);
    void put(K key, V value);
};

template<class K, class V>
void BinarySearchTree<K, V>::put(K key, V value)
{
    root = put(root, key, value);
}

template<class K, class V>
BinarySearchTree::Node* BinarySearchTree<K, V>::put(BinarySearchTree::Node* node, K key, V value)
{
    if (node == nullptr) {
        return new Node(key, value);
    }

    if (node->key > key) {
        // right
    } else if (node->key < key){
        // left
    } else {
        // update
    }

    return nullptr;
}

#endif //ALGORITHMS_SEDGEWICK_BINARYSEARCHTREE_H
