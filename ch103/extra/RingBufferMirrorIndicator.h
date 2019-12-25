//
// Created by y00455335 on 2019/12/25.
// 镜像指示位，头尾的最大值是2倍的队列大小（通过判断头尾是否在同一镜像位置来判断为空和为满）； 当队列是2的倍数时，使用位操作，进行判断和向后+1
//

#ifndef ALGORITHMS_SEDGEWICK_RINGBUFFERMIRRORINDICATOR_H
#define ALGORITHMS_SEDGEWICK_RINGBUFFERMIRRORINDICATOR_H

#include <memory>
#include <mutex>

template<class T>
class RingBufferMirrorIndicator {
public:
    explicit RingBufferMirrorIndicator(size_t size) : buf_(std::unique_ptr<T[]>(new T[size])), max_size_(size) {};

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
bool RingBufferMirrorIndicator<T>::full() const {
    return head_ == (tail_ ^ max_size_);
}

template<class T>
size_t RingBufferMirrorIndicator<T>::size() const {
    return head_ - tail_;
}

template<class T>
size_t RingBufferMirrorIndicator<T>::capacity() const {
    return max_size_;
}

template<class T>
void RingBufferMirrorIndicator<T>::put(T item) {
    std::lock_guard<std::mutex> lock(mutex_);
    buf_[head_ & (max_size_ - 1)] = item; // 镜像位置映射到真正的逻辑地址。
    if (full()) {
        tail_ = (tail_ + 1) & (2 * max_size_ - 1); // 2倍队列大小之内：+1，之外：+1-2倍队列大小
    }
    head_ = (head_ + 1) & (2 * max_size_ - 1);
}

template<class T>
T RingBufferMirrorIndicator<T>::get() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (empty()) {
        return T();
    }
    auto val = buf_[tail_ & (max_size_ - 1)];
    tail_ = (tail_ + 1) & (2 * max_size_ - 1);
    return val;
}

template<class T>
bool RingBufferMirrorIndicator<T>::empty() const {
    return head_ == tail_;
}


#endif //ALGORITHMS_SEDGEWICK_RINGBUFFERMIRRORINDICATOR_H
