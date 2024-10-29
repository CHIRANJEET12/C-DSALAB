#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    int arr[n][n];
    // squarematrix(arr, n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==j){
                printf("is there any self loop in the particular vertex %d and %d :",i, j);
                scanf("%d",&arr[i][j]);
            }else{
                
                printf("is there any connection between %d and %d :",i,j);
                scanf("%d",&arr[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}