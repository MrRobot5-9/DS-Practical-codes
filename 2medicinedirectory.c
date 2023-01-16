#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item_no;
    char medicine_name[50];
    int quantity;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int item_no, char medicine_name[], int quantity) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->item_no = item_no;
    strcpy(newNode->medicine_name, medicine_name);
    newNode->quantity = quantity;
    newNode->next = head;
    head = newNode;
}

void bubbleSort() {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->quantity < ptr1->next->quantity) {
                int temp_item_no = ptr1->item_no;
                ptr1->item_no = ptr1->next->item_no;
                ptr1->next->item_no = temp_item_no;
                char temp_medicine_name[50];
                strcpy(temp_medicine_name, ptr1->medicine_name);
                strcpy(ptr1->medicine_name, ptr1->next->medicine_name);
                strcpy(ptr1->next->medicine_name, temp_medicine_name);
                int temp_quantity = ptr1->quantity;
                ptr1->quantity = ptr1->next->quantity;
                ptr1->next->quantity = temp_quantity;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void display() {
    Node *temp = head;
    printf("Item No.\tMedicine Name\tQuantity\n");
    while (temp != NULL) {
        printf("%d\t\t%s\t\t%d\n", temp->item_no, temp->medicine_name, temp->quantity);
        temp = temp->next;
    }
}

void main() {
    int item_no, quantity, i;
    char medicine_name[50];
    printf("Enter the number of medicine records: ");
    scanf("%d", &i);
    for (int j = 0; j < i; j++) {
        printf("Enter the Item no, Medicine name and Quantity available: ");
        scanf("%d %s %d", &item_no, medicine_name, &quantity);
        insert(item_no, medicine_name, quantity);
    }

    printf("Original List:\n");
    display();

    bubbleSort();

    printf("\nSorted List:\n");
    display();
}
