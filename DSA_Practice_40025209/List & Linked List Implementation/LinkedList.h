#pragma once
#include <iostream>
#include <stdexcept>

// Linked List implementation of the LinearList ADT
// Uses nodes instead of an array — no fixed capacity needed

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    int length;

    // Helper: returns pointer to node at given index
    Node* getNode(int index) const {
        Node* current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current;
    }

public:
    LinkedList() : head(nullptr), length(0) {}

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
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
        return getNode(index)->data;
    }

    // Returns the index of the first occurrence of element x, or -1
    int indexOf(const T& x) const {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == x) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    // Removes element at position index; elements after shift left
    void deleteAt(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");

        Node* toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
        } else {
            Node* prev = getNode(index - 1);
            toDelete = prev->next;
            prev->next = toDelete->next;
        }
        delete toDelete;
        length--;
    }

    // Inserts element x at position index; elements after shift right
    void insert(int index, const T& x) {
        if (index < 0 || index > length)
            throw std::out_of_range("Index out of range");

        Node* newNode = new Node(x);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* prev = getNode(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }
        length++;
    }

    // Outputs all elements from left to right
    void output() const {
        Node* current = head;
        std::cout << "[ ";
        while (current) {
            std::cout << current->data;
            if (current->next) std::cout << ", ";
            current = current->next;
        }
        std::cout << " ]\n";
    }
};
