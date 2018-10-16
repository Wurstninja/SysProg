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
    node* new=malloc(sizeof(node));
    new=NULL;
    new = add(new,1);
    new = add(new,2);
    new = add(new,3);
    return 0;
}

node* add(node* head, int data)
{
    if(head==NULL)
    {
        head->data=data;
        head->next=NULL;
    }
    else
    {
        node* cur;
        cur=malloc(sizeof(node));
        head->next=cur;
        printf("pre\n")
        while(cur!=NULL)
        {
            printf("in\n");
            cur->next=cur;
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