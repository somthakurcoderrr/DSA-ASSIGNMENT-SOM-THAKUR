/*
 * Program: Linear Queue Implementation using an Array in C
 * Assignment: DSA Assignment - Queue Programming Questions
 * 
 * Operations Performed:
 * 1. Insert 10, 20, and 30 into the queue.
 * 2. Delete two elements from the Front.
 * 3. Insert 40 into the Rear.
 * 4. Display the remaining elements.
 */

#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// Function to check if the queue is full
int isFull() {
    return (rear == MAX_SIZE - 1);
}

// Function to insert an element into the rear of the queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d (Queue is full).\n", value);
        return;
    }

    if (front == -1) {
        front = 0; // First element being inserted
    }

    rear++;
    queue[rear] = value;
    printf("Successfully inserted %d at Rear (Index: %d).\n", value, rear);
}

// Function to delete an element from the front of the queue (Dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }

    int deletedValue = queue[front];
    printf("Successfully deleted %d from Front (Index: %d).\n", deletedValue, front);

    front++;

    // Reset queue pointers if all elements have been removed
    if (front > rear) {
        front = -1;
        rear = -1;
    }

    return deletedValue;
}

// Function to display remaining elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is currently empty.\n");
        return;
    }

    printf("Queue elements (Front to Rear): [ ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("] (Front index: %d, Rear index: %d)\n", front, rear);
}

int main() {
    printf("=====================================================\n");
    printf("           QUESTION 1: LINEAR QUEUE                  \n");
    printf("=====================================================\n\n");

    // Operation 1: Insert 10, 20, and 30 into the queue
    printf("--- Operation 1: Insert 10, 20, and 30 into the queue ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 2: Delete two elements from the Front
    printf("--- Operation 2: Delete two elements from the Front ---\n");
    dequeue();
    dequeue();
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 3: Insert 40 into the Rear
    printf("--- Operation 3: Insert 40 into the Rear ---\n");
    enqueue(40);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 4: Display the remaining elements
    printf("--- Operation 4: Display the remaining elements ---\n");
    display();

    printf("\n=====================================================\n");
    printf("          Program Execution Completed Successfully   \n");
    printf("=====================================================\n");

    return 0;
}

