/*
 * Program: Double Ended Queue (Deque) Implementation using an Array in C
 * Assignment: DSA Assignment - Queue Programming Questions
 * 
 * Operations Performed:
 * 9.  Insert 10 from Front.
 * 10. Insert 20 from Rear.
 * 11. Insert 30 from Front.
 * 12. Delete one element from Front.
 * 13. Delete one element from Rear.
 * 14. Display the remaining elements.
 */

#include <stdio.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if the deque is full
int isFull() {
    return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
}

// Function to insert an element at the Front of the Deque
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at Front (Deque is full).\n", value);
        return;
    }

    if (isEmpty()) {
        // If deque is initially empty
        front = 0;
        rear = 0;
    } else if (front == 0) {
        // Wrap around to the last index
        front = MAX_SIZE - 1;
    } else {
        front--;
    }

    deque[front] = value;
    printf("Successfully inserted %d at Front (Index: %d).\n", value, front);
}

// Function to insert an element at the Rear of the Deque
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d at Rear (Deque is full).\n", value);
        return;
    }

    if (isEmpty()) {
        // If deque is initially empty
        front = 0;
        rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        // Wrap around to the first index
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("Successfully inserted %d at Rear (Index: %d).\n", value, rear);
}

// Function to delete an element from the Front of the Deque
int deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from Front (Deque is empty).\n");
        return -1;
    }

    int deletedValue = deque[front];
    printf("Successfully deleted %d from Front (Index: %d).\n", deletedValue, front);

    if (front == rear) {
        // Only one element was present, queue is now empty
        front = -1;
        rear = -1;
    } else if (front == MAX_SIZE - 1) {
        // Wrap around
        front = 0;
    } else {
        front++;
    }

    return deletedValue;
}

// Function to delete an element from the Rear of the Deque
int deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Cannot delete from Rear (Deque is empty).\n");
        return -1;
    }

    int deletedValue = deque[rear];
    printf("Successfully deleted %d from Rear (Index: %d).\n", deletedValue, rear);

    if (front == rear) {
        // Only one element was present, queue is now empty
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        // Wrap around
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }

    return deletedValue;
}

// Function to display the remaining elements of the Deque
void display() {
    if (isEmpty()) {
        printf("Deque is currently empty.\n");
        return;
    }

    printf("Deque elements (Front to Rear): [ ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX_SIZE;
    }
    printf("] (Front index: %d, Rear index: %d)\n", front, rear);
}

int main() {
    printf("=====================================================\n");
    printf("         QUESTION 3: DOUBLE ENDED QUEUE (DEQUE)      \n");
    printf("=====================================================\n\n");

    // Operation 9: Insert 10 from Front
    printf("--- Operation 9: Insert 10 from Front ---\n");
    insertFront(10);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 10: Insert 20 from Rear
    printf("--- Operation 10: Insert 20 from Rear ---\n");
    insertRear(20);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 11: Insert 30 from Front
    printf("--- Operation 11: Insert 30 from Front ---\n");
    insertFront(30);
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 12: Delete one element from Front
    printf("--- Operation 12: Delete one element from Front ---\n");
    deleteFront();
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 13: Delete one element from Rear
    printf("--- Operation 13: Delete one element from Rear ---\n");
    deleteRear();
    printf("Current state: ");
    display();
    printf("\n");

    // Operation 14: Display the remaining elements
    printf("--- Operation 14: Display the remaining elements ---\n");
    display();

    printf("\n=====================================================\n");
    printf("          Program Execution Completed Successfully   \n");
    printf("=====================================================\n");

    return 0;
}

