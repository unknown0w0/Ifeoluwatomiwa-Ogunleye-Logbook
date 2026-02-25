#pragma once
#include <iostream>
#include <stdexcept>


template <typename T>
class DoublyLinkedList {
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

    Node* getNode(int index) const {
        Node* current;
        if (index <= length / 2) {
            current = head;
            for (int i = 0; i < index; i++)
                current = current->next;
        } else {
            current = tail;
            for (int i = length - 1; i > index; i--)
                current = current->prev;
        }
        return current;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~DoublyLinkedList() {
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
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == x) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    void insert(int index, const T& x) {
        if (index < 0 || index > length)
            throw std::out_of_range("Index out of range");

        Node* newNode = new Node(x);

        if (length == 0) {
            head = tail = newNode;
        } else if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (index == length) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            Node* after = getNode(index);
            Node* before = after->prev;
            newNode->next = after;
            newNode->prev = before;
            before->next = newNode;
            after->prev = newNode;
        }
        length++;
    }

    void deleteAt(int index) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of range");

        Node* toDelete = getNode(index);

        if (toDelete->prev) toDelete->prev->next = toDelete->next;
        else head = toDelete->next;

        if (toDelete->next) toDelete->next->prev = toDelete->prev;
        else tail = toDelete->prev;  

        delete toDelete;
        length--;
    }

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

    void outputReverse() const {
        Node* current = tail;
        std::cout << "[ ";
        while (current) {
            std::cout << current->data;
            if (current->prev) std::cout << ", ";
            current = current->prev;
        }
        std::cout << " ]\n";
    }
};
