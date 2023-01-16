#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE], front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Error: Queue overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Error: Queue underflow\n");
    } else {
        front++;
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Error: Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void print_queue() {
    int i;
    printf("Queue: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    print_queue();
    peek();
    dequeue();
    print_queue();
    return 0;
}
