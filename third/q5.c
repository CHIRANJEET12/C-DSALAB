#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void createnode(struct node* current) {
    printf("Enter the element: ");
    scanf("%d", &current->data);
    current->next = NULL;
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct node* head = (struct node*) malloc(sizeof(struct node));
    struct node* current = head;

    for (int i = 1; i <= n; i++) {
        createnode(current);
        if (i < n) {
            current->next = (struct node*) malloc(sizeof(struct node));
            current = current->next;
        }
    }

    printf("Original list: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    int a;
    printf("Enter the value of a (1 to add at the beginning, 2 to add at the end, 3 to add at a position): ");
    scanf("%d", &a);

    switch (a) {
        case 1: {
            printf("Enter a data value to add at the beginning: ");
            struct node* nd = (struct node*) malloc(sizeof(struct node));
            scanf("%d", &nd->data);
            nd->next = head;
            head = nd;
            break;
        }
        case 2: {
            printf("Enter a data value to add at the end: ");
            struct node* end = (struct node*) malloc(sizeof(struct node));
            scanf("%d", &end->data);
            end->next = NULL;

            struct node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = end;
            break;
        }
        case 3: {
            printf("Enter the element to add at any position: ");
            struct node* mid = (struct node*) malloc(sizeof(struct node));
            scanf("%d", &mid->data);
            printf("Enter the position: ");
            int pos;
            scanf("%d", &pos);

            if (pos == 1) {
                mid->next = head;
                head = mid;
            } else {
                struct node* ptr1 = head;
                for (int i = 1; i < pos - 1 && ptr1 != NULL; i++) {
                    ptr1 = ptr1->next;
                }
                if (ptr1 != NULL) {
                    mid->next = ptr1->next;
                    ptr1->next = mid;
                } else {
                    printf("Invalid position!\n");
                }
            }
            break;
        }
        default:
            printf("Invalid option.\n");
            break;
    }

    printf("Updated list: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
