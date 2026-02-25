#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* data;
    int capacity;

public:
    Array(int n) : capacity(n) {
        data = new T[capacity](); 
    }

    ~Array() {
        delete[] data;
    }

    int size() const {
        return capacity;
    }

    void store(int index, const T& x) {
        if (index < 0 || index >= capacity)
            throw std::out_of_range("Index out of range");
        data[index] = x;
    }

    T retrieve(int index) const {
        if (index < 0 || index >= capacity)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    int search(const T& x) const {
        for (int i = 0; i < capacity; i++)
            if (data[i] == x) return i;
        return -1;
    }

    void output() const {
        std::cout << "[ ";
        for (int i = 0; i < capacity; i++)
            std::cout << data[i] << (i < capacity - 1 ? ", " : " ");
        std::cout << "]\n";
    }
};
