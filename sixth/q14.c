#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* deleteOdd(struct Node* head) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (head != NULL && head->data % 2 != 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    current = head;
    while (current != NULL) {
        if (current->data % 2 != 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

int main() {
    // Creating the linked list manually
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->next->next->next = createNode(9);
    head->next->next->next->next->next->next->next->next->next = createNode(10);

    // Print the original linked list
    printf("Original linked list: ");
    printList(head);

    // Delete odd numbers from the list
    head = deleteOdd(head);

    // Print the modified linked list
    printf("Linked list after deleting odd numbers: ");
    printList(head);

    return 0;
}
