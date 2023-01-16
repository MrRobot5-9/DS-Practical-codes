#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void splitList() {
    Node *temp = head;
    Node *head1 = head;
    Node *head2 = NULL;
    Node *prev = NULL;
    int count = 0;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    count++;
    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid; i++) {
        prev = temp;
        temp = temp->next;
    }
    head2 = temp;
    prev->next = head1;
    while (temp->next != head1) {
        temp = temp->next;
    }
    temp->next = head2;
    printf("First Circular Linked List: ");
    temp = head1;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head1);
    printf("\n");
    printf("Second Circular Linked List: ");
    temp = head2;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head2);
    printf("\n");
}

int main() {
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    splitList();
    return 0;
}
