#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinearList {
private:
    T* data;
    int capacity;
    int length;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < length; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    LinearList(int cap = 10) : capacity(cap), length(0) {
        data = new T[capacity];
    }

    ~LinearList() {
        delete[] data;
    }

    // Returns true if the list is empty, false otherwise
    bool Isempty() const {
        return length == 0;
    }

    // Returns the number of elements in the list
    int Listsize() const {
        return length;
    }

    // Returns the element at position index (0-based)
    T get(int index) const {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Returns the index of the first occurrence of element x, or -1
    int indexOf(const T& x) const {
        for (int i = 0; i < length; i++)
            if (data[i] == x) return i;
        return -1;
    }

    // Removes element at position index; elements after shift left
    void deleteAt(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        for (int i = index; i < length - 1; i++)
            data[i] = data[i + 1];
        length--;
    }

    // Inserts element x at position index; elements after shift right
    void insert(int index, const T& x) {
        if (index < 0 || index > length)
            throw std::out_of_range("Index out of range");
        if (length == capacity) resize();
        for (int i = length; i > index; i--)
            data[i] = data[i - 1];
        data[index] = x;
        length++;
    }

    // Outputs all elements from left to right
    void output() const {
        std::cout << "[ ";
        for (int i = 0; i < length; i++)
            std::cout << data[i] << (i < length - 1 ? ", " : " ");
        std::cout << "]\n";
    }
};
