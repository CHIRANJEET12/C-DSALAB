#include<stdio.h>
#include<stdlib.h>
void sparse_matrix(int m,int n,int**ptr,int**ptr2,int k)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ptr[i][j]!=0)
                {
                    ptr2[k][0]=i;
                    ptr2[k][1]=j;
                    ptr2[k][2]=ptr[i][j];
                    k++;
                }
            }
        }
        return;
    }
    void output_matrix(int m,int n,int**ptr3)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d",ptr3[i][j]);
            }
            printf("\n");
        }
        return;
    }
    void search_neighbour(int row_index, int col_index, int **ptr3, int m, int n) 
{
    if (row_index < 0 || row_index >= m || col_index < 0 || col_index >= n) 
    {
        printf("Invalid index\n");
        return;
    }

    // Check top neighbor
    if (row_index - 1 >= 0)
    {
        printf("Top: %d ", ptr3[row_index - 1][col_index]);
    }
    
    if (row_index + 1 < m)
    {
        printf("Bottom: %d ", ptr3[row_index + 1][col_index]);
    }
    
    if (col_index - 1 >= 0)
    {
        printf("Left: %d ", ptr3[row_index][col_index - 1]);
    }
    
    if (col_index + 1 < n)
    {
        printf("Right: %d ", ptr3[row_index][col_index + 1]);
    }
    
    printf("\n");
}


int main()
{
    int m,n,nz=0,z=0,k=0,a,search,row_index,col_index;
    printf("enter no. of rows of matrix u want to store :");
    scanf("%d",&m);
    printf("enter no. of col of matrix stored in each row :");
    scanf("%d",&n);
    int**ptr=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        ptr[i]=(int*)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
        scanf("%d",&ptr[i][j]);
        if(ptr[i][j]==0)
        {
            z++;
        }
        else
        {
            nz++;
        }
        }
    }
    int**ptr2=(int**)malloc(nz*sizeof(int*));
    for(int i=0;i<nz;i++)
    {
        ptr2[i]=(int*)malloc(3*sizeof(int));
    }
    do
    {
    printf("\nEnter the value of a : ");
    scanf("%d",&a);
        switch(a)
        {
            case 1:
            if(z>nz)
            {
                printf("it is a sparse matrix \n");
            }
            else
            {
                printf("it is not a sparse matrix \n");
            }
            break;

            case 2:
            printf("printing original matrix : \n");
            output_matrix(m,n,ptr);
            break;

            case 3:
            sparse_matrix(m,n,ptr,ptr2,k);
            printf("printing compact sparse matrix is : \n"); 
            output_matrix(nz,3,ptr2);
            break;

            case 4:
            printf("enter the element to be searched : ");
            scanf("%d",&search);
            sparse_matrix(m,n,ptr,ptr2,k);
            for(int i=0;i<nz;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(ptr2[i][j]==search)
                    {
                        printf("searched element row_index is :%d\n",i);
                        printf("searched element col_index is :%d\n",j);
                    }
                }
            }
            break;

            case 5:
            printf("enter row index and col index  whose neighbour element to be found : ");
            scanf("%d\t%d",&row_index,&col_index);
            printf("neighbouring elements of main matrix are : ");
            search_neighbour(row_index,col_index,ptr,m,n);
            sparse_matrix(m,n,ptr,ptr2,k);
            break;
            case 6:
            break;
        }
    }
    while(a!=6);
    return 0;
}

    
