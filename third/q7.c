#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void createnode(struct node *ptr) {
    printf("Enter the element: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;  // Initialize the next pointer to NULL
}

void printList(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* reverseList(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;
    }
    head = prev;  
    return head;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of nodes must be positive.\n");
        return 0;
    }

    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;

    for (int i = 0; i < n; i++) {   
        createnode(ptr);
        if (i < n - 1) { 
            ptr->next = (struct node *)malloc(sizeof(struct node));
            ptr = ptr->next;
        } else {
            ptr->next = NULL; 
        }
    }

    printf("Original list: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
