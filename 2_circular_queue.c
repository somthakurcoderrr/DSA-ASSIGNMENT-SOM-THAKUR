/*
 * Queue Programming Question 2: Circular Queue
 * Write a C program to implement a Circular Queue using an array of size 5.
 * Perform the following operations:
 * - Insert 10, 20, 30, and 40.
 * - Delete two elements from the Front.
 * - Insert 50 and 60 into the queue.
 * - Display the elements of the Circular Queue.
 */

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to insert element into circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is Full\n");
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted %d into the queue\n", value);
}

// Function to delete element from circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is Empty\n");
        return -1;
    }
    
    int value = queue[front];
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    
    return value;
}

// Function to display circular queue elements
void display() {
    if (isEmpty()) {
        printf("Circular Queue is Empty\n");
        return;
    }
    
    printf("Elements in Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    printf("=================================\n");
    printf("CIRCULAR QUEUE IMPLEMENTATION\n");
    printf("(Array Size = 5)\n");
    printf("=================================\n\n");
    
    // Insert 10, 20, 30, and 40
    printf("Step 1: Inserting 10, 20, 30, 40 into the queue\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("\n");
    
    // Delete two elements from the Front
    printf("Step 2: Deleting two elements from the Front\n");
    int deleted1 = dequeue();
    printf("Deleted %d from the queue\n", deleted1);
    
    int deleted2 = dequeue();
    printf("Deleted %d from the queue\n", deleted2);
    display();
    printf("\n");
    
    // Insert 50 and 60 into the queue
    printf("Step 3: Inserting 50 and 60 into the queue\n");
    enqueue(50);
    enqueue(60);
    printf("\n");
    
    // Display the elements of the Circular Queue
    printf("Step 4: Display elements of the Circular Queue\n");
    display();
    printf("\n");
    
    printf("=================================\n");
    
    return 0;
}
