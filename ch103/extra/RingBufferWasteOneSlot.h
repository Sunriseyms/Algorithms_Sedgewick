//
// 判断队列是否满和空时：
// 缓冲区中总是有一个存储单元保持未使用状态。缓冲区最多存入 size - 1个数据。如果读写指针指向同一位置，则缓冲区为空。
// 如果写指针位于读指针的相邻后一个位置，则缓冲区为满。这种策略的优点是简单、粗暴；缺点是语义上实际可存数据量与缓冲区容量不一致，测试缓冲区是否满需要做取余数计算
// Created by y00455335 on 2019/12/24.
//

#ifndef ALGORITHMS_SEDGEWICK_RINGBUFFERWASTEONESLOT_H
#define ALGORITHMS_SEDGEWICK_RINGBUFFERWASTEONESLOT_H

#include <mutex>
#include <memory>

template<class T>
class RingBufferWasteOneSlot {
public:
    explicit RingBufferWasteOneSlot(size_t size) : buf_(std::unique_ptr<T[]>(new T[size])), max_size_(size) {};

    bool empty() const;

    bool full() const;

    size_t size() const;

    size_t capacity() const;

    void put(T item);

    T get();

private:
    std::mutex mutex_;
    std::unique_ptr<T[]> buf_;
    size_t head_ = 0;
    size_t tail_ = 0;
    const size_t max_size_;
};

template<class T>
bool RingBufferWasteOneSlot<T>::empty() const {
    return head_ == tail_;
}

template<class T>
bool RingBufferWasteOneSlot<T>::full() const {
    return tail_ == (head_ + 1) % max_size_;
}

template<class T>
size_t RingBufferWasteOneSlot<T>::size() const {
    size_t size = max_size_;
    if (!full()) {
        if (head_ > tail_) {
            size = head_ - tail_;
        } else {
            size = head_ + max_size_ - tail_;
        }
    }

    return size;
}

template<class T>
size_t RingBufferWasteOneSlot<T>::capacity() const {
    return max_size_;
}

template<class T>
void RingBufferWasteOneSlot<T>::put(T item) {
    std::lock_guard<std::mutex> lock(mutex_);
    buf_[head_] = item;
    if (full()) {
        tail_ = (tail_ + 1) % max_size_;
    }
    head_ = (head_ + 1) % max_size_;
}

template<class T>
T RingBufferWasteOneSlot<T>::get() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (empty()) {
        return T();
    }

    auto val = buf_[tail_];
    tail_ = (tail_ + 1) % max_size_;
    return val;
}


#endif //ALGORITHMS_SEDGEWICK_RINGBUFFERWASTEONESLOT_H
