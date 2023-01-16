#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int deque[MAX_SIZE], front = -1, rear = -1;

void insert_front(int data) {
    if (front == 0) {
        printf("Error: Deque overflow (front)\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            front--;
        }
        deque[front] = data;
    }
}

void insert_rear(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Error: Deque overflow (rear)\n");
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = data;
    }
}

void delete_front() {
    if (front == -1) {
        printf("Error: Deque underflow (front)\n");
    } else {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void delete_rear() {
    if (front == -1) {
        printf("Error: Deque underflow (rear)\n");
    } else {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear--;
        }
    }
}

void peek_front() {
    if (front == -1) {
        printf("Error: Deque is empty\n");
    } else {
        printf("Front element: %d\n", deque[front]);
    }
}

void peek_rear() {
    if (front == -1) {
        printf("Error: Deque is empty\n");
    } else {
        printf("Rear element: %d\n", deque[rear]);
    }
}

void print_deque() {
    int i;
    printf("Deque: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    insert_front(1);
    insert_front(2);
    insert_rear(3);
    insert_rear(4);
    print_deque();
    peek_front();
    peek_rear();
    delete_front();
    delete_rear();
    print_deque();
    return 0;
}
