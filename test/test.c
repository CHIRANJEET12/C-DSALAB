#include <stdio.h>
#include <stdlib.h>


int main(){

    int a[3]={1,2,3};
    int b[5]={4,5};
    int k=0;
    for(int i =5-3;i<5;i++){
        b[i]=a[k++];
    }
    
    
    for(int i =0;i<5;i++){
        printf("%d",b[i]);
    }

    printrf("\n");

    for(int i=0;i<5-1;i++){
        for(int j=0;j<5-i-1;j++){
            if(b[j]>b[j+1]){
                int temp = b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }

    for(int i =0;i<5;i++){
        printf("%d",b[i]);
    }


    return 0;
}