
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;

void swap ( int * a, int * b )
{   int t = *a;
    *a = *b;       
    *b = t;   
}

struct Node *lastNode(struct Node *root)
{
    while (root->next != NULL)
    {
        root = root->next;
    }
    return root;
}

struct Node * partition(struct Node *start, struct Node *h)
{
    int x  = h->data;

    struct Node *i = start->prev;
    struct Node * j= (struct Node *)malloc(sizeof(struct Node));

    for (struct Node *j = start; j != h; j = j->next)
    {
        if (j->data <= x)
        {
            i = (i == NULL)? start : i->next;

            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL)? start : i->next; 
    swap(&(i->data), &(h->data));
    return i;
}

void Qs(struct Node* start, struct Node *h)
{
    if (h != NULL && start != h && start != h->next)
    {
        struct Node *p = partition(start, h);
        Qs(start, p->prev);
        Qs(p->next, h);
    }
}

void quickSort(struct Node *head) 
{
    struct Node *h = lastNode(head);/*h is the last node which is taken as the pivot*/ 
    Qs(head, h);
}

void Print(struct Node *head)
{
    while (head)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

void Insert_head(struct Node** head_ref, int new_data)
{
    struct Node * new_node =(struct Node * )malloc(sizeof(struct Node));
    new_node->data  = new_data;

    new_node->prev = NULL;

    new_node->next = (*head_ref);

    if ((*head_ref) !=  NULL)  (*head_ref)->prev = new_node ;

    (*head_ref)    = new_node;
}

int main()
{
    Insert_head(&head, 5);
    Insert_head(&head, 20);
    Insert_head(&head, 4);
    Insert_head(&head, 3);
    Insert_head(&head, 30);
    printf("Linked List before sorting \n");
    Print(head);

    quickSort(head);

    printf("Linked List after sorting \n");
    Print(head);

    return 0;
}