#include<stdio.h>
int main(){

    int *p;

    int(*ptr)[25];
    int arr[5];

    p =arr;
    ptr=&arr;
    
    printf("p=%p\n",p);
    printf("ptr=%p\n",ptr);
     printf("after doing the p++ and ptr++ we get \n");
     p++;
     ptr++;
     printf("p=%p\nptr=%p\n",p,ptr);
    return 0;
}