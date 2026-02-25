#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// stacks
int stack[MAX];
int top = -1; // -1 means empty

// Task 3: Check if a stack is empty
bool isStackEmpty() {
    return top == -1;
}

// queues
int queue[MAX];
int front = -1, rear = -1;

// Task 1: Insertion in a queue using arrays
void insertQueue(int value) {
    if (rear == MAX - 1){
        printf("Overflow, Cannot insert %d\n", value);
        return;
    }
    if (front == -1){
        front = 0;
    } 
    rear++;
    queue[rear] = value;
    printf("Inserted %d into Queue.\n", value);
}

// list 
int list[MAX] = {10, 20, 30, 40, 50};
int listSize = 5;

// Task 4: Get position of an item in a list
int getPosition(int item) {
    for (int i = 0; i < listSize; i++) {
        if (list[i] == item) {
            return i + 1; 
        }
    }
    return -1;
}

void displayList() {
    printf("List: ");
    for (int i = 0; i < listSize; i++) printf("%d ", list[i]);
    printf("\n");
}

// Task 2: Deletion in a list using array
void deleteFromList(int position) {
    int index = position - 1;
    if (index < 0 || index >= listSize) {
        printf("Cannot delete from this position. \n");
        return;
    }

    int removed = list[index];
    // Shift elements to the left
    for (int i = index; i < listSize - 1; i++) {
        list[i] = list[i + 1];
    }
    listSize--;
    printf("Deleted %d from position %d.\n", removed, position);
}

int main() {
    printf("Test:\n\n");

    // Insertion test
    insertQueue(167);
    insertQueue(241);

    // 2. Test Stack Empty Check
    printf("Is stack empty? %s\n", isStackEmpty() ? "Yes" : "No");

    // 3. Test List Operations
    displayList();
    
    // Search
    int item = 30;
    int pos = getPosition(item);
    if (pos != -1) printf("Item %d found at position: %d\n", item, pos);
    else printf("Item not found.\n");

    // Delete
    deleteFromList(2);
    displayList();

    return 0;
}