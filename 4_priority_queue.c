/*
 * Queue Programming Question 4: Priority Queue
 * Write a C program to implement a Priority Queue using an array.
 * Perform the following operations:
 * - Insert 10 with priority 2.
 * - Insert 20 with priority 1.
 * - Insert 30 with priority 3.
 * - Delete the element having the highest priority.
 * - Display the remaining elements with their priorities.
 */

#include <stdio.h>
#define SIZE 10

struct Node {
    int value;
    int priority;
};

struct Node priorityQueue[SIZE];
int count = 0;

// Function to insert element with priority
void enqueue(int value, int priority) {
    if (count == SIZE) {
        printf("Priority Queue is Full\n");
        return;
    }
    
    int i = count - 1;
    
    // Shift elements with lower priority
    while (i >= 0 && priorityQueue[i].priority > priority) {
        priorityQueue[i + 1] = priorityQueue[i];
        i--;
    }
    
    priorityQueue[i + 1].value = value;
    priorityQueue[i + 1].priority = priority;
    count++;
    printf("Inserted %d with priority %d\n", value, priority);
}

// Function to delete element with highest priority
int dequeueHighestPriority() {
    if (count == 0) {
        printf("Priority Queue is Empty\n");
        return -1;
    }
    
    int value = priorityQueue[0].value;
    
    // Shift all elements one position forward
    for (int i = 0; i < count - 1; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }
    
    count--;
    return value;
}

// Function to display all elements with their priorities
void display() {
    if (count == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }
    
    printf("Remaining elements with priorities: ");
    for (int i = 0; i < count; i++) {
        printf("(Value: %d, Priority: %d) ", priorityQueue[i].value, priorityQueue[i].priority);
    }
    printf("\n");
}

int main() {
    printf("=================================\n");
    printf("PRIORITY QUEUE IMPLEMENTATION\n");
    printf("=================================\n");
    printf("Note: Lower priority number = Higher Priority\n\n");
    
    // Insert 10 with priority 2
    printf("Step 1: Insert 10 with priority 2\n");
    enqueue(10, 2);
    display();
    printf("\n");
    
    // Insert 20 with priority 1
    printf("Step 2: Insert 20 with priority 1\n");
    enqueue(20, 1);
    display();
    printf("\n");
    
    // Insert 30 with priority 3
    printf("Step 3: Insert 30 with priority 3\n");
    enqueue(30, 3);
    display();
    printf("\n");
    
    // Delete the element having the highest priority
    printf("Step 4: Delete the element having the highest priority\n");
    int deletedValue = dequeueHighestPriority();
    printf("Deleted %d (highest priority element)\n", deletedValue);
    printf("\n");
    
    // Display the remaining elements with their priorities
    printf("Step 5: Display remaining elements with their priorities\n");
    display();
    printf("\n");
    
    printf("=================================\n");
    
    return 0;
}
