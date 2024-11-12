#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *rear = NULL;
struct node *front = NULL;

int is_empty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int num)
{
    struct node *current = malloc(sizeof(struct node));

    if (current == NULL)
    {
        printf("memory allocacation failed");
        exit(1);
    }
    current->data = num;
    current->next = NULL;

    if (is_empty())
    {
        front = rear = current;
        rear->next = front;
    }
    else
    {
        rear->next = current;
        rear = current;
        current->next = front;
    }
}
void dequeue()
{
    if (is_empty())
    {
        printf("no items can be dequeued as queue is empty ");
    }
    if (rear == front)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node *temp = front->next;
        free(front);
        front = temp;
        rear->next = front;
    }
}

void display()
{
    if (is_empty())
    {
        printf("no items can be dequeued as queue is empty ");
        return;
    }
    struct node *temp = front;
    printf("data are : \n");
    do
    {
        printf("%d", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main()
{
    int n, num, m;
    printf("enter no. of nodes u want to enqueue");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("enter data for queue node %d", i + 1);
        scanf("%d", &num);
        enqueue(num);
    }

    printf("enter no. of nodes u want to dequeue");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        dequeue();
    }

    display();

    return 0;
}