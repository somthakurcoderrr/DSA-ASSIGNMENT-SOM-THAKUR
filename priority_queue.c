#include <stdio.h>
#define SIZE 10

struct Node {
    int value;
    int priority;
};

struct Node priorityQueue[SIZE];
int count = 0;

void enqueue(int value, int priority) {
    if (count == SIZE) {
        printf("Priority Queue is full\n");
        return;
    }

    int i = count - 1;

    while (i >= 0 && priorityQueue[i].priority > priority) {
        priorityQueue[i + 1] = priorityQueue[i];
        i--;
    }

    priorityQueue[i + 1].value = value;
    priorityQueue[i + 1].priority = priority;
    count++;
}

int dequeueHighestPriority() {
    if (count == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }

    int value = priorityQueue[0].value;

    for (int i = 0; i < count - 1; i++) {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    count--;
    return value;
}

void display() {
    if (count == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Remaining elements with priorities: ");
    for (int i = 0; i < count; i++) {
        printf("(%d, %d) ", priorityQueue[i].value, priorityQueue[i].priority);
    }
    printf("\n");
}

int main() {
    printf("Priority Queue Implementation\n");
    printf("----------------------------\n");
    printf("Note: Lower priority number means higher priority\n\n");

    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);

    printf("Before deletion:\n");
    display();

    printf("Deleted highest priority element: %d\n", dequeueHighestPriority());

    printf("After deletion:\n");
    display();

    return 0;
}
