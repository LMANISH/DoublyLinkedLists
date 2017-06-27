
#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node* head = NULL;
 
void Insert(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
 
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    (*head_ref)    = new_node;
}
 
void insertAfter(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
    new_node->data  = new_data;
 
    new_node->next = prev_node->next;
    if (prev_node->next != NULL)
    {
        prev_node->next->prev = new_node;    
    }
    
    prev_node->next = new_node;
    new_node->prev = prev_node;
 
    
}
 
void Insert_last(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;  
 
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;
    new_node->prev = last;

}
 
void Print(struct Node *node)
{
    struct Node *last;
    printf("\nOriginal Dlinked list ");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
 
    printf("\nReversed Dlinked list ");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

void Reverse(struct Node * temp)
{

    struct Node * temporary = (struct Node *)malloc(sizeof(struct Node));
    temporary=temp;
    while(temporary != NULL)
    {
        temporary = temp->prev;
        temp->prev = temp->next;
        temp->next = temporary;
        temporary = temp->prev;
    }
    head = temp;
} 


int main()
{
    Insert_last(&head, 2); 
    Insert(&head, 90);
    Insert(&head, 31);
    Insert_last(&head, 47);
    Insert(&head, 15);

    Reverse(head);
    Print(head);
    return 0;
}