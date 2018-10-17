#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node* head;
    struct node* next;
    struct node* prev;
    int data;
}node;

node* add(node* head, int data);
void printList(node*);
void freeList(node*);
int main()
{
    node* list = NULL;
    list = add(list,1);
    list = add(list,2);
    list = add(list,3);
    printList(list);
    list = add(list,4);
    printList(list);      
    freeList(list);                
    printList(list);
    return 0;
}

node* add(node* head, int data)
{
    node* new = malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    if(head==NULL)
    {
        return new;
    }
    else
    {
        node* cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = new;
        return head;
    }
}

void printList(node* head)
{
    node* cur = head;
    while (cur!=NULL)
    {
        printf("%i%s",cur->data, cur->next?", ":"\n");
        cur = cur->next;
    }
}

void freeList(node* head)
{
    node* cur=head;
    node* nex;
    while(cur!=NULL)
    {
        nex=cur->next;
        free(cur->data);
        free(cur);
        cur=nex;
    }
}