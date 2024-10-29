#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("enter the size of array");
    scanf("%d",&n);
    
    int arr[n];
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    return 0;
}