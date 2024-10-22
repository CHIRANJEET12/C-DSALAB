#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue{
    int element[MAX];
    int front;
    int rear;
}

void initial(struct queue element){
    queue->front =-1;
    queue->rear =-1;
}

void isempty(){
    if(queue->front ==-1 && queue->rear == -1){
        printf("queue is empty");
    }
}

void isfull(){
    if(queue->rear == MAX-1){
        printf("queue is full");
    }
}

void enqueue(struct queue item , int k){
    if(isfull){
        return;
    }
    if(queue->front==-1 && queue->rear ==-1){
        queue->front==0;
        queue->rear==0;
    }else{
        queue->rear++;
    }
    queue->element[rear] = k;
    printf("%d inserted",k);
}

void dequeue(struct queue item){
    if(isempty){
        return;
    }if(queue->front == queue->rear){
        printf("%d deleted",queue->item[front] );
        queue->front = queue->rear = -1;
    }else{
        printf("%d elements", queue->item[front]);
        queue->front++;
    }
}






int mian(){

    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    dequeue(queue);
    dequeue(queue);





    return 0;
}