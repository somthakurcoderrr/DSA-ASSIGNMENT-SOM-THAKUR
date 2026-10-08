/*
 * Queue Programming Question 1: Linear Queue
 * Write a C program to implement a Linear Queue using an array.
 * Perform the following operations:
 * - Insert 10, 20, and 30 into the queue.
 * - Delete two elements from the Front.
 * - Insert 40 into the Rear.
 * - Display the remaining elements.
 */

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert element into queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted %d into the queue\n", value);
}

// Function to delete element from queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    
    int value = queue[front];
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    
    return value;
}

// Function to display queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Remaining elements in queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("=================================\n");
    printf("LINEAR QUEUE IMPLEMENTATION\n");
    printf("=================================\n\n");
    
    // Insert 10, 20, and 30 into the queue
    printf("Step 1: Inserting 10, 20, 30 into the queue\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
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
    
    // Insert 40 into the Rear
    printf("Step 3: Inserting 40 into the Rear\n");
    enqueue(40);
    printf("\n");
    
    // Display the remaining elements
    printf("Step 4: Display remaining elements\n");
    display();
    printf("\n");
    
    printf("=================================\n");
    
    return 0;
}
