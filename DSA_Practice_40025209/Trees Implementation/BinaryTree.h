#pragma once
#include <iostream>
#include <algorithm>

/* AVL Tree - a self-balancing Binary Search Tree
 After every insert/delete, rotations are performed to keep
 the height difference (balance factor) of every node within [-1, 0, 1]
*/

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        Node(const T& val) : data(val), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    // --- Helper utilities ---

    int height(Node* node) const {
        return node ? node->height : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }

    // Balance factor: positive = left heavy, negative = right heavy
    int balanceFactor(Node* node) const {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // --- Rotations ---

    //        y                x
    //       / \              / \
    //      x   T3   -->    T1   y
    //     / \                  / \
    //    T1  T2               T2  T3
    Node* rotateRight(Node* y) {
        Node* x  = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left  = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    //      x                  y
    //     / \                / \
    //    T1   y    -->      x   T3
    //        / \           / \
    //       T2  T3        T1  T2
    Node* rotateLeft(Node* x) {
        Node* y  = x->right;
        Node* T2 = y->left;
        y->left  = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    // Re-balance a node after insert/delete
    Node* rebalance(Node* node) {
        updateHeight(node);
        int bf = balanceFactor(node);

        // Left heavy
        if (bf > 1) {
            if (balanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left);  // Left-Right case
            return rotateRight(node);                 // Left-Left case
        }

        // Right heavy
        if (bf < -1) {
            if (balanceFactor(node->right) > 0)
                node->right = rotateRight(node->right); // Right-Left case
            return rotateLeft(node);                    // Right-Right case
        }

        return node; // already balanced
    }

    // --- Core recursive operations ---

    void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    int size(Node* node) const {
        if (!node) return 0;
        return 1 + size(node->left) + size(node->right);
    }

    Node* insert(Node* node, const T& val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left  = insert(node->left,  val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            return node; // duplicate, ignore

        return rebalance(node);
    }

    // Find the minimum node in a subtree (used for delete)
    Node* minNode(Node* node) const {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, const T& val) {
        if (!node) return nullptr;

        if (val < node->data)
            node->left  = deleteNode(node->left,  val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            // Node to delete found
            if (!node->left || !node->right) {
                Node* child = node->left ? node->left : node->right;
                delete node;
                return child;
            }
            // Two children: replace with inorder successor
            Node* successor  = minNode(node->right);
            node->data       = successor->data;
            node->right      = deleteNode(node->right, successor->data);
        }

        return rebalance(node);
    }

    // --- Traversals ---

    void preOrder(Node* node, void (*visit)(const T&)) const {
        if (!node) return;
        visit(node->data);
        preOrder(node->left,  visit);
        preOrder(node->right, visit);
    }

    void inOrder(Node* node, void (*visit)(const T&)) const {
        if (!node) return;
        inOrder(node->left,  visit);
        visit(node->data);
        inOrder(node->right, visit);
    }

    void postOrder(Node* node, void (*visit)(const T&)) const {
        if (!node) return;
        postOrder(node->left,  visit);
        postOrder(node->right, visit);
        visit(node->data);
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() { destroy(root); }

    // Returns true if empty, false otherwise
    bool empty() const { return root == nullptr; }

    // Returns number of nodes in the tree
    int size() const { return size(root); }

    // Returns height of the tree
    int height() const { return height(root); }

    // Insert a value — tree auto-balances after insertion
    void insert(const T& val) { root = insert(root, val); }

    // Delete a value — tree auto-balances after deletion
    void remove(const T& val) { root = deleteNode(root, val); }

    // Preorder traversal with a visit function
    void preOrder(void (*visit)(const T&)) const { preOrder(root, visit); }

    // Inorder traversal with a visit function (always sorted for BST)
    void inOrder(void (*visit)(const T&)) const { inOrder(root, visit); }

    // Postorder traversal with a visit function
    void postOrder(void (*visit)(const T&)) const { postOrder(root, visit); }
};
