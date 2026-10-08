#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full\n");
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
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full\n");
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
}

int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
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

int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
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

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
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
    printf("Deque (Double Ended Queue) Implementation\n");
    printf("----------------------------------------\n");

    insertFront(10);
    insertRear(20);
    insertFront(30);

    printf("After insertion: ");
    display();

    printf("Deleted from Front: %d\n", deleteFront());
    printf("Deleted from Rear: %d\n", deleteRear());

    printf("After deletions: ");
    display();

    return 0;
}
