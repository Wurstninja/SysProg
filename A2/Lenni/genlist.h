#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* next;
    void* data;
}node; 

int free_list(node* list, int(*free_element)(void*));
int insert(node** list_ptr, void* data, int(*cmp)(void*));
int print(node* list, int (*print_element)(void*));