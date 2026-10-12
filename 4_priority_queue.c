/*
 * Program: Priority Queue Implementation using an Array in C
 * Assignment: DSA Assignment - Queue Programming Questions
 * 
 * Priority Convention:
 * Lower priority number indicates higher priority (e.g., Priority 1 > Priority 2 > Priority 3).
 * 
 * Operations Performed:
 * 15. Insert 10 with priority 2.
 * 16. Insert 20 with priority 1.
 * 17. Insert 30 with priority 3.
 * 18. Delete the element having the highest priority.
 * 19. Display the remaining elements with their priorities.
 */

#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int value;
    int priority;
} Element;

Element pq[MAX_SIZE];
int size = 0;

// Function to check if the priority queue is empty
int isEmpty() {
    return (size == 0);
}

// Function to check if the priority queue is full
int isFull() {
    return (size == MAX_SIZE);
}

// Function to insert an element with a given priority (Ascending Priority Queue)
// Elements are arranged such that the element with highest priority (lowest priority number) is at index 0.
void enqueue(int value, int priority) {
    if (isFull()) {
        printf("Priority Queue Overflow! Cannot insert %d (Queue is full).\n", value);
        return;
    }

    int i = size - 1;

    // Shift elements that have lower priority (higher priority number) to the right
    while (i >= 0 && pq[i].priority > priority) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].value = value;
    pq[i + 1].priority = priority;
    size++;

    printf("Successfully inserted Value: %d with Priority: %d.\n", value, priority);
}

// Function to delete the element having the highest priority (lowest priority number at index 0)
int deleteHighestPriority() {
    if (isEmpty()) {
        printf("Priority Queue Underflow! Queue is empty.\n");
        return -1;
    }

    // Element at index 0 has the highest priority
    int deletedValue = pq[0].value;
    int deletedPriority = pq[0].priority;

    // Shift remaining elements one position to the left
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;

    printf("Successfully deleted element with highest priority: Value: %d (Priority: %d).\n", 
           deletedValue, deletedPriority);
    return deletedValue;
}

// Function to display all remaining elements along with their priorities
void display() {
    if (isEmpty()) {
        printf("Priority Queue is currently empty.\n");
        return;
    }

    printf("Priority Queue elements [Value (Priority)]: ");
    for (int i = 0; i < size; i++) {
        printf("[%d (P:%d)] ", pq[i].value, pq[i].priority);
    }
    printf("(Total elements: %d)\n", size);
}

int main() {
    printf("=====================================================\n");
    printf("             QUESTION 4: PRIORITY QUEUE              \n");
    printf("  (Rule: Lower priority number = Higher priority)    \n");
    printf("=====================================================\n\n");

    // Operation 15: Insert 10 with priority 2
    printf("--- Operation 15: Insert 10 with priority 2 ---\n");
    enqueue(10, 2);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 16: Insert 20 with priority 1
    printf("--- Operation 16: Insert 20 with priority 1 ---\n");
    enqueue(20, 1);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 17: Insert 30 with priority 3
    printf("--- Operation 17: Insert 30 with priority 3 ---\n");
    enqueue(30, 3);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 18: Delete the element having the highest priority
    printf("--- Operation 18: Delete the element having the highest priority ---\n");
    deleteHighestPriority();
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 19: Display the remaining elements with their priorities
    printf("--- Operation 19: Display the remaining elements with their priorities ---\n");
    display();

    printf("\n=====================================================\n");
    printf("          Program Execution Completed Successfully   \n");
    printf("=====================================================\n");

    return 0;
}

