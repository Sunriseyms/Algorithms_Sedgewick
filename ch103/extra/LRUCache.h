//
// LRU Least Recently Used
// 使用map + double linked list实现的LRUCache
// Created by y00455335 on 2019/12/26.
//

#ifndef ALGORITHMS_SEDGEWICK_LRUCACHE_H
#define ALGORITHMS_SEDGEWICK_LRUCACHE_H

#include <map>
#include <utility>
#include <algorithm>

template<class T>
class LRUCache {

    // 双向链表的节点
    class Node {
    public:
        int key_;
        T value_;
        Node *prev_, *next_;

        Node(int k, T value) : key_(k), value_(value), prev_(nullptr), next_(nullptr) {}
    };

    // 双向链表，用于存储缓存
    class DoubleLinkedList {
        Node *headDummy, *tailDummy; // 创建两个哨兵节点，方便处理
    public:
        DoubleLinkedList() {
            headDummy = new Node(0, T());
            tailDummy = new Node(0, T());
            headDummy->next_ = tailDummy;
            tailDummy->prev_ = headDummy;
            headDummy->prev_ = nullptr;
            tailDummy->next_ = nullptr;
        }

        // 添加节点到链表头
        Node *AddPageToHead(int key, T value) {
            Node *page = new Node(key, value);
            page->next_ = headDummy->next_;
            headDummy->next_->prev_ = page;
            headDummy->next_ = page;
            page->prev_ = headDummy;
            return headDummy->next_;
        }

        // 将节点移动到链表头
        void MovePageToHead(Node *page) {
            if (page == headDummy->next_) {
                return;
            }

            // 删除节点
            page->prev_->next_ = page->next_;
            page->next_->prev_ = page->prev_;

            // 将节点移至链表头
            page->next_ = headDummy->next_;
            headDummy->next_->prev_ = page;
            headDummy->next_ = page;
            page->prev_ = headDummy;
        }

        // 将链表尾节点删除
        void RemoveTailPage() {
            if (tailDummy->prev_ == headDummy) {
                return;
            }
            Node *temp = tailDummy->prev_->prev_;
            tailDummy->prev_->prev_->next_ = tailDummy;
            delete tailDummy->prev_;
            tailDummy->prev_ = temp;
        }

        // 获取链表尾节点
        Node *GetTailPage() {
            return tailDummy->prev_;
        }
    };

    int capacity_, size_;
    DoubleLinkedList *pageList;
    std::map<int, Node *> pageMap;

public:
    // 创建LRU缓存
    LRUCache(int capacity) : capacity_(capacity), size_(0) {
        pageList = new DoubleLinkedList();
        pageMap = std::map<int, Node *>();
    }

    // 从缓冲区中获取元素，不在则返回T(),存在，将给节点移至链表头，并返回
    T get(int key) {
        if (pageMap.find(key) == pageMap.end()) {
            return T();
        }

        auto val = pageMap[key]->value_;
        pageList->MovePageToHead(pageMap[key]);
        return val;
    }

    // 将元素放入缓存区，已经存在，更新值，并移至链表头；如果缓存区满，删除尾节点；添加元素至链表头，并更新map
    void put(int key, T value) {
        if (pageMap.find(key) != pageMap.end()) {
            pageMap[key]->value_ = value;
            pageList->MovePageToHead(pageMap[key]);
            return;
        }

        if (size_ == capacity_) {
            int k = pageList->GetTailPage()->key_;
            pageMap.erase(k);
            pageList->RemoveTailPage();
            size_--;
        }

        Node *page = pageList->AddPageToHead(key, value);
        pageMap[key] = page;
        size_++;
    }

    // 析构，释放堆上的对象
    ~LRUCache() {
        std::for_each(pageMap.begin(), pageMap.end(), [](std::pair<int, Node *> pagePair) {
            delete pagePair.second;
        });

        delete pageList;
    }
};


#endif //ALGORITHMS_SEDGEWICK_LRUCACHE_H
