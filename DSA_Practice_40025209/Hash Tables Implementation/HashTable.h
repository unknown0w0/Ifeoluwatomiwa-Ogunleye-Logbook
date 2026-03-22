#pragma once
#include <iostream>
#include <stdexcept>
#include <string>


template <typename K, typename V>
class HashTable {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v) : key(k), value(v), next(nullptr) {}
    };

    Node** buckets;   
    int    capacity;  
    int    count;     

    int hash(const K& key) const {
        std::hash<K> hasher;
        return (int)(hasher(key) % capacity);
    }

public:
    
    HashTable(int cap = 16) : capacity(cap), count(0) {
        buckets = new Node*[capacity]();  
    }

    ~HashTable() {
        for (int i = 0; i < capacity; i++) {
            Node* current = buckets[i];
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] buckets;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int tableLength() const {
        return count;
    }

    void Insert(const K& key, const V& value) {
        int index = hash(key);
        Node* current = buckets[index];

        while (current) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node* newNode  = new Node(key, value);
        newNode->next  = buckets[index];
        buckets[index] = newNode;
        count++;
    }

    void Delete(const K& key) {
        int index = hash(key);
        Node* current = buckets[index];
        Node* prev    = nullptr;

        while (current) {
            if (current->key == key) {
                if (prev) prev->next      = current->next;
                else      buckets[index]  = current->next;
                delete current;
                count--;
                return;
            }
            prev    = current;
            current = current->next;
        }
        throw std::runtime_error("Key not found");
    }

    V Retrieve(const K& key) const {
        int index     = hash(key);
        Node* current = buckets[index];

        while (current) {
            if (current->key == key) return current->value;
            current = current->next;
        }
        throw std::runtime_error("Key not found");
    }
    void output() const {
        for (int i = 0; i < capacity; i++) {
            Node* current = buckets[i];
            while (current) {
                std::cout << "[" << current->key << " -> " << current->value << "] ";
                current = current->next;
            }
        }
        std::cout << "\n";
    }
};
