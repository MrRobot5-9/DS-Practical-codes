#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head; 
struct Node* GetNewNode(int x) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(int x) {
    struct Node* temp = head;
    struct Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next != NULL) temp = temp->next; 
    temp->next = newNode;
}
void Print() {
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int key) {
    struct Node* temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next; 
        free(temp);        
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
}
int main() {
    head = NULL; 
    InsertAtTail(2);
    InsertAtTail(3);
    InsertAtHead(1);
    InsertAtHead(0);
    printf("Created Linked List is: ");
    Print();
    Delete(3);
    printf("Linked List after Deletion of 1: ");
    Print();
}
