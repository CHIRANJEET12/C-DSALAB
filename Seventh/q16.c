#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int k) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    else if (front == -1 && rear == -1) { 
        front = 0;
        rear = 0;
    }
    else {
        rear++; 
    }
    
    queue[rear] = k;
    printf("%d inserted into queue\n", k);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    } 
    else if (front == rear) { 
        printf("%d deleted\n", queue[front]);
        front = rear = -1; 
    } 
    else {
        printf("%d deleted\n", queue[front]);
        front++; 
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    dequeue(); 
    dequeue(); 
    dequeue(); 

    return 0;
}
