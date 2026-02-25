#include <iostream>
#include "Array.h"
#include "LinearList.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "BinaryTree.h"
#include "Integer.h"

using namespace std;

void printInt(const int& x) {
    cout << x << " ";
}

int main() {

    cout << "=== Array ADT ===\n";
    Array<int> arr(5);           // fixed size of 5
    arr.store(0, 10);
    arr.store(1, 20);
    arr.store(2, 30);
    arr.store(3, 40);
    arr.store(4, 50);
    arr.output();                // [ 10, 20, 30, 40, 50 ]
    cout << "Size: " << arr.size() << "\n";
    cout << "Retrieve index 2: " << arr.retrieve(2) << "\n";
    cout << "Search for 40: index " << arr.search(40) << "\n";
    cout << "\n";

    // --- Integer Demo ---
    cout << "=== Integer ADT ===\n";
    Integer a(20), b(4);
    cout << "a = " << a.getValue() << ", b = " << b.getValue() << "\n";
    cout << "Add: " << a.Add(b).getValue() << "\n";  // 24
    cout << "Sub: " << a.Sub(b).getValue() << "\n";  // 16
    cout << "Mul: " << a.Mul(b).getValue() << "\n";  // 80
    cout << "Div: " << a.Div(b).getValue() << "\n";  // 5
    cout << "\n";

    // --- LinearList Demo (array-based) ---
    cout << "=== LinearList (Array-based) ===\n";
    LinearList<int> list;
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 15);
    list.output();       // [ 10, 15, 20, 30 ]
    cout << "Index of 20: " << list.indexOf(20) << "\n";
    list.deleteAt(2);
    list.output();       // [ 10, 15, 30 ]
    cout << "Size: " << list.Listsize() << "\n\n";

    // --- LinkedList Demo (pointer-based) ---
    cout << "=== LinkedList (Pointer-based) ===\n";
    LinkedList<int> linked;
    linked.insert(0, 10);
    linked.insert(1, 20);
    linked.insert(2, 30);
    linked.insert(1, 15);
    linked.output();     // [ 10, 15, 20, 30 ]
    cout << "Index of 20: " << linked.indexOf(20) << "\n";
    linked.deleteAt(2);
    linked.output();     // [ 10, 15, 30 ]
    cout << "Size: " << linked.Listsize() << "\n\n";

    // --- Doubly Linked List Demo ---
    cout << "=== Doubly Linked List ===\n";
    DoublyLinkedList<int> doubly;
    doubly.insert(0, 10);
    doubly.insert(1, 20);
    doubly.insert(2, 30);
    doubly.insert(1, 15);
    doubly.output();                  // [ 10, 15, 20, 30 ]
    cout << "Reverse: ";
    doubly.outputReverse();           // [ 30, 20, 15, 10 ]
    doubly.deleteAt(2);
    doubly.output();                  // [ 10, 15, 30 ]
    cout << "Size: " << doubly.Listsize() << "\n\n";

    // --- Circular Linked List Demo ---
    cout << "=== Circular Linked List ===\n";
    CircularLinkedList<int> circular;
    circular.insert(0, 10);
    circular.insert(1, 20);
    circular.insert(2, 30);
    circular.insert(1, 15);
    circular.output();                // [ 10, 15, 20, 30 ]
    circular.outputCircular(2);       // shows the circle wrapping around
    circular.deleteAt(2);
    circular.output();                // [ 10, 15, 30 ]
    cout << "Index of 15: " << circular.indexOf(15) << "\n";
    cout << "\n";

    // --- Stack Demo ---
    cout << "=== LIFO Stack ===\n";
    Stack<char> stack;
    stack.push('A');
    stack.push('B');
    stack.push('C');
    stack.output();
    cout << "Top: " << stack.top() << "\n";
    cout << "Pop: " << stack.pop() << "\n";
    stack.output();
    cout << "\n";

    // --- Expression Notation Demo ---
    cout << "=== Stack: Expression Notations ===\n";
    string infix = "3 + 4 * 2";
    string postfix = infixToPostfix(infix);
    string prefix  = infixToPrefix(infix);

    cout << "Infix:   " << infix   << "\n";
    cout << "Postfix: " << postfix << "\n";
    cout << "Prefix:  " << prefix  << "\n";
    cout << "Evaluated (postfix): " << evaluatePostfix(postfix) << "\n";
    cout << "Evaluated (prefix):  " << evaluatePrefix(prefix)  << "\n";
    cout << "\n";

    // Another example with brackets
    string infix2   = "( 5 + 3 ) * 2";
    string postfix2 = infixToPostfix(infix2);
    string prefix2  = infixToPrefix(infix2);
    cout << "Infix:   " << infix2   << "\n";
    cout << "Postfix: " << postfix2 << "\n";
    cout << "Prefix:  " << prefix2  << "\n";
    cout << "Evaluated (postfix): " << evaluatePostfix(postfix2) << "\n";
    cout << "Evaluated (prefix):  " << evaluatePrefix(prefix2)  << "\n";
    cout << "\n";

    // --- Deque Demo ---
    cout << "=== Deque (Double-Ended Queue) ===\n";
    Deque<int> deque;
    deque.enqueueBack(10);       // [ 10 ]
    deque.enqueueBack(20);       // [ 10, 20 ]
    deque.enqueueBack(30);       // [ 10, 20, 30 ]
    deque.enqueueFront(5);       // [ 5, 10, 20, 30 ]
    deque.enqueueFront(1);       // [ 1, 5, 10, 20, 30 ]
    deque.output();
    cout << "Dequeue front: " << deque.dequeueFront() << "\n";  // 1
    cout << "Dequeue back:  " << deque.dequeueBack()  << "\n";  // 30
    deque.output();              // [ 5, 10, 20 ]
    cout << "Peek front: "   << deque.peekFront() << "\n";      // 5
    cout << "Peek back:  "   << deque.peekBack()  << "\n";      // 20
    cout << "\n";

    // --- Queue Demo ---
    cout << "=== Queue (FIFO) ===\n";
    Queue<char> queue;
    queue.enqueue('A');
    queue.enqueue('B');
    queue.enqueue('C');
    queue.output();
    cout << "Dequeue: " << queue.dequeue() << "\n";
    queue.enqueue('G');
    queue.output();
    cout << "\n";

    // --- Binary Tree (AVL) Demo ---
    cout << "=== Binary Tree (AVL) ===\n";
    BinaryTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    cout << "Size: "   << tree.size()   << "\n";
    cout << "Height: " << tree.height() << " (plain BST would be 7)\n";
    cout << "PreOrder:  "; tree.preOrder(printInt);  cout << "\n";
    cout << "InOrder:   "; tree.inOrder(printInt);   cout << "\n";
    cout << "PostOrder: "; tree.postOrder(printInt); cout << "\n";
    tree.remove(40);
    cout << "After removing 40 -> InOrder: "; tree.inOrder(printInt); cout << "\n";

    return 0;
}
