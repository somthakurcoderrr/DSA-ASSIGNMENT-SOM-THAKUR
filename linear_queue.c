#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

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
}

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

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Remaining elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("Linear Queue Implementation\n");
    printf("-------------------------\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("After inserting 10, 20, 30\n");
    display();

    printf("Deleted element: %d\n", dequeue());
    printf("Deleted element: %d\n", dequeue());

    enqueue(40);

    printf("After deleting two elements and inserting 40\n");
    display();

    return 0;
}
