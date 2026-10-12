/*
 * Program: Circular Queue Implementation using an Array (Size 5) in C
 * Assignment: DSA Assignment - Queue Programming Questions
 * 
 * Operations Performed:
 * 5. Insert 10, 20, 30, and 40.
 * 6. Delete two elements from the Front.
 * 7. Insert 50 and 60 into the queue.
 * 8. Display the elements of the Circular Queue.
 */

#include <stdio.h>

#define SIZE 5

int cQueue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the circular queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if the circular queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to insert an element into the circular queue (Enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue Overflow! Cannot insert %d (Queue is full).\n", value);
        return;
    }

    if (front == -1) {
        // First element being inserted
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    cQueue[rear] = value;
    printf("Successfully inserted %d at Rear (Index: %d).\n", value, rear);
}

// Function to delete an element from the circular queue (Dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue Underflow! Queue is empty.\n");
        return -1;
    }

    int deletedValue = cQueue[front];
    printf("Successfully deleted %d from Front (Index: %d).\n", deletedValue, front);

    if (front == rear) {
        // Only one element was present, queue is now empty
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return deletedValue;
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Circular Queue is currently empty.\n");
        return;
    }

    printf("Circular Queue elements (Front to Rear): [ ");
    int i = front;
    while (1) {
        printf("%d ", cQueue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("] (Front index: %d, Rear index: %d)\n", front, rear);
}

int main() {
    printf("=====================================================\n");
    printf("          QUESTION 2: CIRCULAR QUEUE (SIZE = 5)       \n");
    printf("=====================================================\n\n");

    // Operation 5: Insert 10, 20, 30, and 40
    printf("--- Operation 5: Insert 10, 20, 30, and 40 into the queue ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 6: Delete two elements from the Front
    printf("--- Operation 6: Delete two elements from the Front ---\n");
    dequeue();
    dequeue();
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 7: Insert 50 and 60 into the queue
    printf("--- Operation 7: Insert 50 and 60 into the queue ---\n");
    enqueue(50);
    enqueue(60);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 8: Display the elements of the Circular Queue
    printf("--- Operation 8: Display the elements of the Circular Queue ---\n");
    display();

    printf("\n=====================================================\n");
    printf("          Program Execution Completed Successfully   \n");
    printf("=====================================================\n");

    return 0;
}
