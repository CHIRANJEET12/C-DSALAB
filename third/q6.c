#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};


    void create_node(struct node *current)
    {
    printf("enter the data : ");
    scanf("%d",&current->data);
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    current->next=newnode; 
    }

int main()
{
    int n;
    printf("enter no. of terms u want to create a node : ");
    scanf("%d",&n);
    struct node*head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    struct node*current;
    struct node*ptr=head;
    current=head;
    if(head==NULL)
    {
        printf("No node is created");
    }
    for(int i=1;i<=n;i++)
    {
        create_node(current);
        current=current->next;
    }   
    current->next=NULL; 
     while(ptr->next!=NULL)
    { 
       printf("%d",ptr->data);
       ptr=ptr->next;
    }

    ptr=head;

    int search;
    printf("enter the element to be searched : ");
    scanf("%d",&search);

   while(ptr->next!=NULL)
    { 
        if(ptr->data==search)
        {      
        printf("here search element is present in linked list : ");
        break;
        }
        ptr=ptr->next;
    }
    ptr=head;
    int a;
    printf("enter the node no. u want to modify :");
    scanf("%d",&a);
    for(int i=1;i<a;i++)
    {
        ptr=ptr->next;
    }
    int upd;
    printf("enter updated value : ");
    scanf("%d",&upd);
    ptr->data=upd;

    ptr=head;

    while(ptr->next!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
        printf("\n");
    }

    ptr=head;

    int del;
    printf("enter node u want to delete : ");
    scanf("%d",&del);
    for(int i=1;i<del-1;i++)
    {
        ptr=ptr->next;
    }
    struct node *ptr2=ptr->next;
    ptr->next=ptr2->next;
    
    free(ptr2);
    
    ptr=head;

    while(ptr->next!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
        printf("\n");
    }
    return 0;

}