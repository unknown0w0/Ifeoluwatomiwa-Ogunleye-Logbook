#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    T* data;
    int capacity;
    int frontIdx;
    int backIdx;
    int count;

    void resize() {
        int newCap = capacity * 2;
        T* newData = new T[newCap];
        for (int i = 0; i < count; i++)
            newData[i] = data[(frontIdx + i) % capacity];
        delete[] data;
        data = newData;
        frontIdx = 0;
        backIdx = count;
        capacity = newCap;
    }

public:
    Queue(int cap = 10) : capacity(cap), frontIdx(0), backIdx(0), count(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    // Returns true if the queue is empty
    bool is_empty() const {
        return count == 0;
    }

    void enqueue(const T& x) {
        if (count == capacity) resize();
        data[backIdx] = x;
        backIdx = (backIdx + 1) % capacity;
        count++;
    }

    T dequeue() {
        if (is_empty())
            throw std::underflow_error("Queue is empty");
        T val = data[frontIdx];
        frontIdx = (frontIdx + 1) % capacity;
        count--;
        return val;
    }

    T front() const {
        if (is_empty())
            throw std::underflow_error("Queue is empty");
        return data[frontIdx];
    }

    void output() const {
        std::cout << "Queue (front -> back): ";
        for (int i = 0; i < count; i++)
            std::cout << data[(frontIdx + i) % capacity] << " ";
        std::cout << "\n";
    }
};
