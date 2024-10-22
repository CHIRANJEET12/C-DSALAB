#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int a) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack_arr[++top] = a;
}
int pop(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }
    int value;
    value  = stack_arr[top--];
    return value;
}
void print() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements to push: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of elements exceeds stack capacity\n");
        return 1;
    }

    int a;
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        push(a);
    }

    printf("Stack elements are:\n");
    print();

    int data=pop();
    printf("%d \n",data);
    print();
    return 0;
}
