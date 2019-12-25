//
// ring buffer, cyclic buffer, circular buffer, circular queue
// 循环缓冲区，圆形队列
// 判断队列是否为空时，采用一个bool的标志位full，来判断队列是否为满，是否为空。
// Use a bool flag and additional logic to differentiate states::
//      Full state is full
//      Empty state is (head == tail) && !full
// Created by y00455335 on 2019/12/23.
//

#ifndef ALGORITHMS_SEDGEWICK_RINGBUFFERFULLFLAG_H
#define ALGORITHMS_SEDGEWICK_RINGBUFFERFULLFLAG_H

#include <mutex>
#include <memory>

template<class T>
class RingBufferFullFlag {
public:
    explicit RingBufferFullFlag(size_t size) : buf_(std::unique_ptr<T[]>(new T[size])), max_size_(size) {};

    bool empty() const;

    bool full() const;

    size_t size() const;

    size_t capacity() const;

    void put(T item);

    T get();

    void reset();

private:
    std::mutex mutex_;
    std::unique_ptr<T[]> buf_;
    size_t head_ = 0;
    size_t tail_ = 0;
    const size_t max_size_;
    bool full_ = false;
};

template<class T>
bool RingBufferFullFlag<T>::empty() const {
    return (!full_ && head_ == tail_);
}

template<class T>
bool RingBufferFullFlag<T>::full() const {
    return full_;
}

template<class T>
size_t RingBufferFullFlag<T>::size() const {
    size_t size = max_size_;

    if (!full_) {
        if (head_ >= tail_) {
            size = head_ - tail_;
        } else {
            size = max_size_ + head_ - tail_;
        }
    }

    return size;
}

template<class T>
size_t RingBufferFullFlag<T>::capacity() const {
    return max_size_;
}

template<class T>
void RingBufferFullFlag<T>::put(T item) {
    std::lock_guard<std::mutex> lock(mutex_);
    buf_[head_] = item;
    if (full_) {
        tail_ = (tail_ + 1) % max_size_;
    }

    head_ = (head_ + 1) % max_size_;
    full_ = tail_ == head_;
}

template<class T>
T RingBufferFullFlag<T>::get() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (empty()) {
        return T();
    }

    auto val = buf_[tail_];
    full_ = false;
    tail_ = (tail_ + 1) % max_size_;
    return val;
}

template<class T>
void RingBufferFullFlag<T>::reset() {
    std::lock_guard<std::mutex> lock(mutex_);
    head_ = tail_;
    full_ = false;
}


#endif //ALGORITHMS_SEDGEWICK_RINGBUFFERFULLFLAG_H
