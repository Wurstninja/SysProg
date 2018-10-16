#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// change

typedef struct node
{
    struct node* head;
    struct node* next;
    struct node* prev;
    int data;
}node;

node* add(node* head, int data);
void printList(node*);
int main()
{
    node* list = NULL;
    list = add(list,1);
    // works up to here
    list = add(list,2);
    list = add(list,3);
    return 0;
}

node* add(node* head, int data)
{
    if(head==NULL)
    {
        node* new = malloc(sizeof(node));
        new->data=data;
        new->next=NULL;
        return new;
    }
    else
    {
        node* cur;
        cur=malloc(sizeof(node));
        head->next=cur;
        while(cur!=NULL)
        {
            printf("in\n");cur->next=cur;
        }
        cur->data=data;
        cur->next=NULL;
    }
    return head;
}

void printList(node* head)
{
    node* cur;
    while (cur!=NULL)
    {
        printf("%i\n",cur->data);
    }
}