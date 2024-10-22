#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
void createnode(struct node*current,int i)
{    
    struct node*newnode = (struct node*)malloc(sizeof (struct node));
    current->next=newnode;
}

int main()
{
    int n;
    printf("Enter 1 for insertion: \n");
    printf("Enter 2 for traversing: \n");
    printf("Enter 3 for deletion :\n");
    printf("enter 4 for reversing : \n\n\n");

    printf("\nenter no. of nodes u want to create : ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("no node has been created\n");
        printf("thanks for using the code ");
        return 0;
    }
    struct node*head;  
    head=malloc(sizeof (struct node));
    printf("enter data for node 1 : ");
    scanf("%d",&head->data);
    struct node*current=head;
    for(int i=1;i<n;i++)
    {        
        printf("enter data for node %d : ",i+1);
        createnode(current,i);
        current=current->next;
        scanf("%d",&current->data);
        
    }
        current->next=NULL;

    current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    current=head;
    int q;
    do
    { 
        printf("\nenter case no. to be find : ");
        scanf("%d",&q);
        switch(q)
        {
            case 1:
            printf(" insert at beginning :        insert at middle          insertion at end \n");
            int a;
            printf("enter the position where u want to insert the node : ");
            scanf("%d",&a);
            if(a==1)
            {
            printf("enter data for insertion node : ");
            struct node* insert=malloc(sizeof(struct node));
            scanf("%d",&insert->data);
            insert->next=head;
            head=insert;
            n=n+1;
            current=head ;
            while(current!=NULL)
            {
                printf("%d ",current->data);
                current=current->next;
            } 
            }
            current=head;
            struct node *ptr2;
            
            if(a>n+1)
            {
                printf("no such node is there kindly input valid node no.\n");
            }
            if(a>1&&a<=n+1)
            {
                printf("enter data for insertion node : ");
                struct node* insert=malloc(sizeof(struct node));
                scanf("%d",&insert->data);
                a--;
                while(a!=1)
                {
                    current=current->next;
                    a--;
                }
                ptr2=current->next;
                current->next=insert;
                insert->next=ptr2;
                n=n+1;
                current=head;
                while(current!=NULL)
                {
                    printf("%d ",current->data);
                    current=current->next;
                }      
            }
            current=head; 
            break;

            case 2:
            printf("            1.search element in a node                      2.update the data in a node   \n");
            int b;
            printf("enter the index what u want to do in question 2 : ");
            scanf("%d",&b);

            if(b==1)
            {
                int search;
                printf("enter the element to be searched : ");
                scanf("%d",&search);
                int temp=0;
                while(current!=NULL)
                {
                    if(current->data==search)
                    {
                        temp=1;
                    }
                    current=current->next;
                }
                if(temp!=0)
                {
                    printf("searched element is present in a linked list\n");
                }
                else{
                    printf("searched element is not present in a linked list.\n");
                }
                current=head;
            }

            if(b==2)
            {
                int modify;
                printf("ENTER THE NODE NO. WHERE U WANT TO MODIFY :");
                scanf("%d",&modify);
                if(modify>n)
                {
                    printf("no such node exists \n");
                }
                else
                {
                    for(int i=1;i<modify;i++)
                    {
                        current=current->next;
                    }
                    int upd;
                    printf("enter the updated value : ");
                    scanf("%d",&upd);
                    current->data=upd;
                    current=head;
                    while(current!=NULL)
                    {
                        printf("%d ",current->data);
                        current=current->next;
                    }    
                    current=head;  
                }
            }
            break;
            int del;
            struct node*ptr3;
            case 3:            
            printf("enter the node which u want to delete : ");
            scanf("%d",&del);
            if(del==1)
            {
                ptr3=head->next;
                free(head);
                head=ptr3;
                current=head;

                while(current!=NULL)
                {
                printf("%d ",current->data);
                current=current->next;
                }    
                current=head;  
            }
            else
        {
            for(int i=1;i<del-1;i++)
            {
                current=current->next;
            }
            ptr3=current->next;
            current->next=ptr3->next;
            free(ptr3);
            current=head;
            
            while(current!=NULL)
            {
                printf("%d ",current->data);
                current=current->next;
            }    
            current=head;

         }
            break;
            current=head;
            struct node*ahead=NULL;
            struct node*prev=NULL;
            case 4:            
            printf("reversing the singly linked list\n");
            while(current->next!=NULL)
            {
                ahead=current->next;
                current->next=prev;
                prev=current;
                current=ahead;
            }
            current->next=prev;
            head=current;
            ahead=NULL;
            prev=NULL;
            while(current!=NULL)
            {
                printf("%d ",current->data);
                current=current->next;
            }
            current=head;
                
                break;
            case 5:
            printf("exiting the code");
        }
         
    }      
    while(q!=5);
}
