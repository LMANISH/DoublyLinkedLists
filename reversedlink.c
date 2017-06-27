

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
};


void Insert_head(struct Node *temp, int element)
{
    
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data  = element;
    newnode->prev = NULL;
    newnode->next = temp;
    
 
    
    if(temp !=  NULL)
      temp->prev = newnode ;
 
    temp = newnode;
}


void Delete(struct Node *temp,int x)
{

    while(temp->data != x)
    {
        temp = temp->next;
    }
    if(temp->prev != NULL)
        temp->prev->next =temp->next;
    if(temp->next == NULL)
        temp->next->prev = temp->prev;
}

void Insert_x(struct Node *temp,int nextElement ,int n)
{
    struct Node * newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data=n;
    newnode->prev=newnode->next=NULL;
    
    while(temp->data != nextElement)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev=temp;
    if(temp->next !=NULL)
        temp->next->prev=newnode;
    temp->next=newnode;
    

        
}

void Print(struct Node * node)
{

    while(node != NULL)
    {
        printf("%d",node->data);
        node=node->next;
    }
}

Reverse(struct Node * temp)
{
	struct Node * temporary = (struct Node *)malloc(sizeof(struct Node));
	temporary->next = temp->prev;
	temp->prev=temp->next;
	temp->next = temporary->next;
	
}


int main()
{
    struct Node * head= NULL;
    int noe,element,opt,repeat,nextElement;
    printf("Enter no. of elements");
    scanf("%d",&noe);
    for(int i=0;i<noe;i++)
    {
        scanf("%d",&element);
        Insert_head(head,element);
    }
    Print(head);
    
    do
    {
        printf("Enter 1 to insert || 2 to delete");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("Enter number to be inserted");
                scanf("%d",&element);
                printf("Enter element before which is to be inserted");
                scanf("%d",&nextElement);
                Insert_x(head,nextElement,element);
                break;
                
            case 2:
                printf("Enter the element to be deleted");
                scanf("%d",&element);
                Delete(head,element);
                break;

            printf("Enter 1 to repeat || 2 to exit");
            scanf("%d",&repeat);
        }


    }while(repeat==1);  

    Reverse(head); 
}