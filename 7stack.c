#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE], top = -1;

void push(int data) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack overflow\n");
    } else {
        top++;
        stack[top] = data;
    }
}

void pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
    } else {
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Error: Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void print_stack() {
    int i;
    printf("Stack: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    print_stack();
    peek();
    pop();
    print_stack();
    return 0;
}
