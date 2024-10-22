#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* head = NULL;


void deloddvalue() {
    struct node* current = head;
    struct node* prev = NULL;

    while (current != NULL) {
        
        if (current->data % 2 == 1) {
           
            if (current == head) {
                head = current->link;
                free(current);
                current = head;
            } else {
               
                prev->link = current->link;
                free(current);
                current = prev->link;
            }
        } else {
            prev = current;
            current = current->link;
        }
    }
}

void printList() {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main() {
    int n, d;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("The linked list is empty\n");
        return 0;
    }

    printf("Enter the data in node 1: ");
    scanf("%d", &d);
    head = (struct node*)malloc(sizeof(struct node));
    head->data = d;
    head->link = NULL;

    struct node* ptr = head;
    for (int i = 1; i < n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data in node %d: ", i + 1);
        scanf("%d", &d);
        newNode->data = d;
        newNode->link = NULL;
        ptr->link = newNode;
        ptr = newNode;
    }

    printf("The elements in the linked list are:\n");
    printList();

    deloddvalue();

    printf("The elements after deleting the odd values are:\n");
    printList();

   return 0;
}