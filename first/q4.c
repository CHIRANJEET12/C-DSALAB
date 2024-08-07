#include<stdio.h>
#include<stdlib.h>

int main(){

    int n,m,z=0,nz=0;
            int q;
    printf("enter the 2 values");
    scanf("%d %d",&n,&m);
    int **ptr = (int**)malloc(sizeof(int));
    for(int i=0;i<n;i++){
        ptr[i]= (int*)malloc(n*(sizeof(int)));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&ptr[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ptr[i][j]==0){
                z++;
            }else{
                nz++;
            }
        }
    }
                    int k=0;
        int **ptr2 = (int**)malloc(sizeof(int));
        for(int i=0;i<nz;i++){
        ptr2[i]= (int*)malloc(nz*(sizeof(int)));
        }

    int a;
    printf("enter the value of a\n");
    scanf("%d",&a);
    if(a==1){
        if(nz>z){
            printf("sparce matrix is not possible\n");
        }else{
            printf("sparce matrix is possible\n");
        }

    }
    if(a==2){
                for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("%d",ptr[i][j]);
            }
            printf("\n");
        }

    }
    if(a==3){

        for(int i=0;i<nz;i++){
            for(int j=0;j<3;j++){
                if(ptr[i][j]!=0){
                ptr2[k][0]=i;
                ptr2[k][1]=j;
                ptr2[k][2]=ptr[i][j];
                k++;
                }
            }
            printf("\n");
        }
    
    
        for(int i= 0;i<nz;i++){
            for(int j=0;j<3;j++){
                printf("%d",ptr2[i][j]);
            }
            printf("\n");
        }
                printf("serach\n");
        scanf("%d",&q);
        for(int i= 0;i<nz;i++){
            for(int j=0;j<3;j++){
                if(ptr2[i][j]==q){
                    int t= i;
                    int p = j;
                    printf("%d %d",t,p);
                }
        }
        }
    }
    if(a==4){

    }





   
	return 0;
}
