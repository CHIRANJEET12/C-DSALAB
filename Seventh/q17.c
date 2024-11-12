#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue {
    int element[MAX];
    int front;
    int rear;
};

void initialize(struct queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isempty(struct queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int isfull(struct queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(struct queue *q, int k) {
    if (isfull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1 && q->rear == -1) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->element[q->rear] = k;
    printf("%d inserted\n", k);
}

void dequeue(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return;
    }
    if (q->front == q->rear) {
        printf("%d deleted\n", q->element[q->front]);
        q->front = q->rear = -1;
    } else {
        printf("%d deleted\n", q->element[q->front]);
        q->front++;
    }
}
void printlist(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->element[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    initialize(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    // dequeue(&q);
    // dequeue(&q);
    printlist(&q);

    return 0;
}
