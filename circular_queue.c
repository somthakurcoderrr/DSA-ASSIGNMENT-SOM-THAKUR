#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((rear + 1) % SIZE == front);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Circular Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
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

void display() {
    if (isEmpty()) {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue elements: ");
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
    printf("Circular Queue Implementation\n");
    printf("----------------------------\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Inserted 10, 20, 30, 40\n");
    display();

    printf("Deleted element: %d\n", dequeue());
    printf("Deleted element: %d\n", dequeue());

    enqueue(50);
    enqueue(60);

    printf("After deleting two elements and inserting 50, 60\n");
    display();

    return 0;
}
