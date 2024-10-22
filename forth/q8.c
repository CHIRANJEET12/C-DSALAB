#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct Node* last = (*head)->prev;

        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void position(struct Node* head,int pos,struct Node* ptr2->data){
    struct Node* ptr = createNode;
    struct Node* current = head;
    pos--;
    while(pos!=1){
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->prev = ptr2;
    current->next = ptr2;
    ptr2->prev = current;
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Doubly Circular Linked List: ");
    display(head);

    // struct Node* current =head;
    int pd;
    printf("enter the node.data");
    scanf("%d",&pd);
    struct Node* ptr2=(struct Node*)malloc(sizeof(struct Node));
    ptr2->data= pd;    
    int pos;
    printf("enter the position u want to add a node");
    scanf("%d",&pos);

    position(head,pos,ptr2->data);




    return 0;
}
