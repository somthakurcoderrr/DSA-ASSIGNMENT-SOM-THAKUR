/*
 * Queue Programming Question 3: Double Ended Queue (Deque)
 * Write a C program to implement a Deque using an array.
 * Perform the following operations:
 * - Insert 10 from Front.
 * - Insert 20 from Rear.
 * - Insert 30 from Front.
 * - Delete one element from Front.
 * - Delete one element from Rear.
 * - Display the remaining elements.
 */

#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

// Check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Check if deque is full
int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

// Function to insert element from Front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    
    deque[front] = value;
    printf("Inserted %d from Front\n", value);
}

// Function to insert element from Rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    
    deque[rear] = value;
    printf("Inserted %d from Rear\n", value);
}

// Function to delete element from Front
int deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    
    int value = deque[front];
    
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
    
    return value;
}

// Function to delete element from Rear
int deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -1;
    }
    
    int value = deque[rear];
    
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
    
    return value;
}

// Function to display deque elements
void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    
    printf("Remaining elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    printf("=================================\n");
    printf("DEQUE (DOUBLE ENDED QUEUE)\n");
    printf("IMPLEMENTATION\n");
    printf("=================================\n\n");
    
    // Insert 10 from Front
    printf("Step 1: Insert 10 from Front\n");
    insertFront(10);
    display();
    printf("\n");
    
    // Insert 20 from Rear
    printf("Step 2: Insert 20 from Rear\n");
    insertRear(20);
    display();
    printf("\n");
    
    // Insert 30 from Front
    printf("Step 3: Insert 30 from Front\n");
    insertFront(30);
    display();
    printf("\n");
    
    // Delete one element from Front
    printf("Step 4: Delete one element from Front\n");
    int deletedFront = deleteFront();
    printf("Deleted %d from Front\n", deletedFront);
    display();
    printf("\n");
    
    // Delete one element from Rear
    printf("Step 5: Delete one element from Rear\n");
    int deletedRear = deleteRear();
    printf("Deleted %d from Rear\n", deletedRear);
    display();
    printf("\n");
    
    // Display the remaining elements
    printf("Step 6: Display remaining elements\n");
    display();
    printf("\n");
    
    printf("=================================\n");
    
    return 0;
}
