#pragma once
#include <iostream>
#include <stdexcept>



template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* tail;   
    int length;

    Node* getNode(int index) const {
        Node* current = tail->next; 
        for (int i = 0; i < index; i++)
            current = current->next;
        return current;
    }

public:
    CircularLinkedList() : tail(nullptr), length(0) {}

    ~CircularLinkedList() {
        if (!tail) return;
        Node* head = tail->next;
        tail->next = nullptr;  
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool Isempty() const {
        return length == 0;
    }

    int Listsize() const {
        return length;
    }

    T get(int index) const {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");
        return getNode(index)->data;
    }

    int indexOf(const T& x) const {
        if (!tail) return -1;
        Node* current = tail->next;
        for (int i = 0; i < length; i++) {
            if (current->data == x) return i;
            current = current->next;
        }
        return -1;
    }

    void insert(int index, const T& x) {
        if (index < 0 || index > length)
            throw std::out_of_range("Index out of range");

        Node* newNode = new Node(x);

        if (length == 0) {
            newNode->next = newNode;
            tail = newNode;
        } else if (index == 0) {
            newNode->next = tail->next;
            tail->next = newNode;
        } else if (index == length) {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        } else {
            Node* prev = getNode(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
        }
        length++;
    }

    void deleteAt(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");

        Node* toDelete;

        if (length == 1) {
            toDelete = tail;
            tail = nullptr;
        } else if (index == 0) {
            toDelete = tail->next;
            tail->next = toDelete->next;
        } else {
            Node* prev = getNode(index - 1);
            toDelete = prev->next;
            prev->next = toDelete->next;
            if (toDelete == tail) tail = prev;
        }

        delete toDelete;
        length--;
    }

    void output() const {
        if (!tail) { std::cout << "[ ]\n"; return; }
        Node* head = tail->next;
        Node* current = head;
        std::cout << "[ ";
        for (int i = 0; i < length; i++) {
            std::cout << current->data;
            if (i < length - 1) std::cout << ", ";
            current = current->next;
        }
        std::cout << " ]\n";
    }

    void outputCircular(int loops = 2) const {
        if (!tail) { std::cout << "[ ]\n"; return; }
        Node* current = tail->next;
        int total = length * loops;
        std::cout << "Circular (" << loops << " loops): ";
        for (int i = 0; i < total; i++) {
            std::cout << current->data;
            if (i < total - 1) std::cout << " -> ";
            current = current->next;
        }
        std::cout << " -> ...\n";
    }
};
