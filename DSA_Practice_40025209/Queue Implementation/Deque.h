#pragma once
#include <iostream>
#include <stdexcept>


template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    Deque() : head(nullptr), tail(nullptr), length(0) {}

    ~Deque() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Returns true if the deque is empty
    bool is_empty() const {
        return length == 0;
    }

    // Returns the number of elements
    int size() const {
        return length;
    }

    // Returns the front element without removing it
    T peekFront() const {
        if (is_empty()) throw std::underflow_error("Deque is empty");
        return head->data;
    }

    // Returns the back element without removing it
    T peekBack() const {
        if (is_empty()) throw std::underflow_error("Deque is empty");
        return tail->data;
    }

    // Adds element x to the FRONT
    void enqueueFront(const T& x) {
        Node* newNode = new Node(x);
        if (is_empty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev    = newNode;
            head          = newNode;
        }
        length++;
    }

    // Adds element x to the BACK
    void enqueueBack(const T& x) {
        Node* newNode = new Node(x);
        if (is_empty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next    = newNode;
            tail          = newNode;
        }
        length++;
    }

    // Removes and returns element from the FRONT
    T dequeueFront() {
        if (is_empty()) throw std::underflow_error("Deque is empty");
        Node* toDelete = head;
        T val = toDelete->data;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;  // deque is now empty
        delete toDelete;
        length--;
        return val;
    }

    // Removes and returns element from the BACK
    T dequeueBack() {
        if (is_empty()) throw std::underflow_error("Deque is empty");
        Node* toDelete = tail;
        T val = toDelete->data;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;  // deque is now empty
        delete toDelete;
        length--;
        return val;
    }

    // Outputs all elements front to back
    void output() const {
        Node* current = head;
        std::cout << "front [ ";
        while (current) {
            std::cout << current->data;
            if (current->next) std::cout << ", ";
            current = current->next;
        }
        std::cout << " ] back\n";
    }
};
