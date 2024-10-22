#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*prev;
    int data;
    struct node*next;
};

int main()
{
    int n;
    printf("enter no. of nodes u want to create : ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("NO NODE IS CREATED");
        return 0;
    }
    struct node*head=(struct node*)malloc(sizeof(struct node));
    struct node*current=head;
    struct node*ptr=current;
    printf("Enter data for node 1 : ");
    scanf("%d",&head->data);
    head->prev=NULL;
    head->next=NULL;
    int count=1;
    while(count<n)
    {
        printf("enter data for node %d ",count+1);
        current->next=malloc(sizeof(struct node));
        current=current->next;
        current->prev=ptr;
        scanf("%d",&current->data);
        ptr=ptr->next;
        count++;
    }
    struct node *tail=current;
    printf("--------------%p",tail);
    printf("\n");
    tail->next=head;
    head->prev=tail;
    current=head;
    printf("CURRENT NODE        NODE PREV      NODE DATA      NODE NEXT   \n");
    for(int i=1;i<=n;i++)
    {
        printf(" %p          ",current);
        printf(" %p          ",current->prev);
        printf("%d          ",current->data);
        printf("%p          ",current->next);
        printf("\n");
        if(i<n)
        current=current->next;
    }
    printf("\n");
    current=head;
    printf("\n\n");
    printf("Enter 1 for insertion \n");
    printf("Enter 2 for tranversal \n");
    printf("enter 3 for deletion \n");
    printf("enter 4 for reversal\n");
    int a;

    do
    {
        printf("enter which case you want to run : ");
        scanf("%d",&a);
        switch (a)
        {
            int pos;
            case 1:           
            printf("enter the position where u want to insert the node : ");
            scanf("%d",&pos);
            struct node*insert=malloc(sizeof(struct node));
            printf("enter data for insertion node : ");
            scanf("%d",&insert->data);
            if(pos==1)
            {
                insert->prev=tail;
                insert->next=head;
                head->prev=insert;
                tail->next=insert;
                head=insert;
                current=head;
                n++;

                //printing the value

               printf("CURRENT NODE        NODE PREV      NODE DATA      NODE NEXT   \n");
                for(int i=1;i<=n;i++)
                {
                    printf(" %p          ",current);
                    printf(" %p          ",current->prev);
                    printf("%d          ",current->data);
                    printf("%p          ",current->next);
                    printf("\n");
                    if(i<n)
                    current=current->next;
                }
                current=head;
                printf("\n");
            }

            if(pos>1&&pos<=n+1)
            {
                for(int i=1;i<pos-1;i++)
                {
                    current=current->next;
                }
                struct node*temp=current->next;
                insert->prev=current;  
                current->next=insert;              
                insert->next=temp;
                temp->prev=insert;
                current=head;
                if(pos==n+1)
                {
                    tail=insert;
                }
                n++;
                //printing the value;
               printf("CURRENT NODE        NODE PREV      NODE DATA      NODE NEXT   \n");
                for(int i=1;i<=n;i++)
                {
                    printf(" %p          ",current);
                    printf(" %p          ",current->prev);
                    printf("%d          ",current->data);
                    printf("%p          ",current->next);
                    printf("\n");
                    if(i<n)
                    current=current->next;
                }
                printf("\n");
                current=head;
            }

            break;

            int idx,search,modify;
            case 2:
            printf("1.............1.for searching                  .............2.for modification\n");
            printf("Enter what index u want to choose : ");
            scanf("%d",&idx);
            if(idx==1)
            {
                printf("enter the element to be searched : ");
                scanf("%d",&search);
                for(int i=1;i<=n;i++)
                {
                    if(current->data==search)
                    {
                        printf("%d is present in node no. %d of linked list .\n",search,i);
                        break;
                    }
                    if(i<n)
                    current=current->next;
                }
                current=head;
            }
            if(idx==2)
            {
                printf("enter the node no. to be modified :");
                scanf("%d",&search);
                printf("entered the modified value : ");
                scanf("%d",&modify);
                for(int i=1;i<=search;i++)
                {
                    if(i<n)
                    current=current->next;
                }
                current->data=modify;
                current=head;
                for(int i=1;i<=n;i++)
                {
                    printf("%d ",current->data);
                    if(i<n)
                    current=current->next;
                }
                current=head;
            }
            break;
            int ab;
            case 3: 
            printf("enter the node which u want to delete : ");
            scanf("%d",&ab);
            if(ab==1)
            {
                struct node*temp=head->next;
                tail->next=temp;
                temp->prev=tail;
                free(current);
                head=temp;
                current=head;
                n--;
                printf("CURRENT NODE        NODE PREV      NODE DATA      NODE NEXT   \n");
                for(int i=1;i<=n;i++)
                {
                    printf(" %p          ",current);
                    printf(" %p          ",current->prev);
                    printf("%d          ",current->data);
                    printf("%p          ",current->next);
                    printf("\n");
                    if(i<n)
                    current=current->next;
                }
                printf("\n");
                current=head;

            }
            if(ab>1&&ab<=n)
            {
                for(int i=1;i<ab;i++)
                {
                    current=current->next;
                }
                struct node *prev=current->prev;
                struct node *ahead=current->next;
                prev->next=ahead;
                ahead->prev=prev;
                free(current);
                current=head;
                n--;
                printf("CURRENT NODE        NODE PREV      NODE DATA      NODE NEXT   \n");
                for(int i=1;i<=n;i++)
                {
                    printf(" %p          ",current);
                    printf(" %p          ",current->prev);
                    printf("%d          ",current->data);
                    printf("%p          ",current->next);
                    printf("\n");
                    if(i<n)
                    current=current->next;
                }
                    printf("\n");
                    current=head;
            }
            break;
            case 4:
            printf("reverse the circular doubly linked list :\n");
            for(int i=1;i<=n;i++)
            {
                struct node*temp=current->next;
                current->next=current->prev;
                current->prev=temp;
                if(i<n)
                {
                    current=current->next;
                }
            }
            current=tail;

            for(int i=1;i<=n;i++)
            {
                printf(" %p          ",current);
                printf(" %p          ",current->prev);
                printf("%d          ",current->data);
                printf("%p          ",current->next);
                printf("\n");
                if(i<n)
                current=current->next;
            }
            head=tail;
            tail=current;
            current=head;

        }
    }
    while(a!=5);
}
