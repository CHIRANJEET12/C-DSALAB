#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteSecondLast(struct Node* head) {
    if (head == NULL || head->next == head) {
        return head;  
    }

    struct Node* current = head;

    if (head->next->next == head) {
        struct Node* toDelete = head;  
        head = head->next;  
        head->next = head;  
        free(toDelete);  
        return head;
    }

    while (current->next->next->next != head) {
        current = current->next;
    }

    struct Node* toDelete = current->next;  
    current->next = toDelete->next;  

    free(toDelete);  

    return head;
}

void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;  
    return newNode;
}

struct Node* appendNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

int main() {
    struct Node* head = NULL;
    
    head = appendNode(head, 10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    head = appendNode(head, 40);
    
    printf("Original list: \n");
    printList(head);

    head = deleteSecondLast(head);

    printf("After deleting second last: \n");
    printList(head);

    return 0;
}
