#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top,int k){
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data= k;
    newnode->next=top;
    return newnode;
}

void print(struct Node* top ){
    while(top!=NULL){
        printf("%d",top->data);
        top=top->next;
    }
}

struct Node* pop(struct Node* top){
    struct Node* temp = top;
    top=top->next;
    free(temp); 
    return top;
}


int main(){
    struct Node* stack = NULL;
    printf("enter the elements:");
    int a;
    for(int i =0;i<5;i++){
        scanf("%d",&a);
        stack=push(stack,a);
    }
     
    print(stack);

    int k;
    printf("enter k");
    scanf("%d",&k);

    stack = push(stack,k);
    print(stack);



    stack = pop(stack);
    printf("\n");
    print(stack);
    




    return 0;
}