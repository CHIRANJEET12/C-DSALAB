#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *top, int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

struct Node *pop(struct Node *top, int *poppedData)
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    *poppedData = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

void printStack(struct Node *top)
{
    while (top!=NULL)
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main()
{
    struct Node *stack = NULL;
    struct Node *tempStack = NULL;
    int data, temp;

    printf("Enter 6 elements for the stack:\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &data);
        stack = push(stack, data);
    }

    while (stack != NULL)
    {
        stack = pop(stack, &temp);

        while (tempStack != NULL && temp > tempStack->data)
        {
            tempStack = pop(tempStack, &data);
            stack = push(stack, data);
        }

        tempStack = push(tempStack, temp);
    }

    printf("Sorted stack: ");
    printStack(tempStack);

    return 0;
}