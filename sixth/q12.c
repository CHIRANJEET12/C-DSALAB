#include <stdio.h>
#include <stdlib.h>

int main(){

    int n,m;
    printf("enter the numbers:");
    scanf("%d %d",&n,&m);

    int arr[n][m];

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]%2!=0){
                arr[i][j]=arr[i][j]+1;
            }
        }
    }
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}