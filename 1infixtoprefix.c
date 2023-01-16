#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

Node *head = NULL;

void push(char value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

char pop() {
    if (head == NULL) {
        printf("Stack Underflow\n");
        exit(0);
    }
    Node *temp = head;
    char value = temp->data;
    head = head->next;
    free(temp);
    return value;
}

int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

void convertToInfix(char prefix[]) {
    int i;
    int length = strlen(prefix);
    char infix[length + 2];
    for (i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            char op1 = pop();
            char op2 = pop();
            char temp[3];
            temp[0] = op1;
            temp[1] = prefix[i];
            temp[2] = op2;
            temp[3] = '\0';
            push(temp);
        } else {
            push(prefix[i]);
        }
    }
    printf("Infix notation: %s\n", head->data);
}

void main() {
    char prefix[100];
    int choice;
    while (1) {
        printf("1. Convert prefix to infix\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the prefix expression: ");
                scanf("%s", prefix);
                convertToInfix(prefix);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
