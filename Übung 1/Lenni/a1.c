#include <stdio.h> // printf etc
#include <stdlib.h> // malloc, free, etc
#include <string.h> // string comparison

#define FAILURE 1
#define SUCCESS 0

typedef struct node
{
    struct node* n;
    char* surname;
    char* forename;
}node;

int compare(node*, node*);
int insert(node** list, char* surname, char* forename);


int main()
{
    node* list = NULL;

    FILE* file = fopen("file.txt", "r");
    if(!file) return FAILURE;

    
    char* buf1 = malloc(128);
    char* buf2 = malloc(128);
    if(!buf1 || !buf2) return FAILURE;

    int res;

    loop:
        res = fscanf(file, "%127s %127s", buf1, buf2);
        if(res == EOF || !res) goto cont;
        res = insert(&list, buf2, buf1);
        if(res == FAILURE) return FAILURE;
        buf1 = malloc(128);
        buf2 = malloc(128);
    goto loop;
    cont:
    free(buf1);
    free(buf2);
    for(node* cur = list; cur!=NULL;)
    {
        printf("%s %s\n", cur->forename, cur->surname);

        node* next = cur->n;
        free(cur->forename);
        free(cur->surname);
        free(cur);
        cur = next;
    }
    fclose(file);
    return SUCCESS;
}

int insert(node** list, char* surname, char* forename)
{
    node* new = malloc(sizeof(node));
    new->surname = surname;
    new->forename = forename;
    if (new == NULL) return FAILURE;
    node* cur = *list;
    if(compare(*list, new)>=0)
    {
        new->n = *list;
        *list = new;
        return SUCCESS;
    }
    loop:
        if(compare(cur->n, new) >= 0)
        {
            new->n = cur->n;
            cur->n = new;
            return SUCCESS;
        }
        cur = cur->n;
    goto loop;
}

int compare(node* a, node* b)
{
    if(!a) return 1;
    int res = strcmp(a->surname, b->surname);
    return res != 0? res : strcmp(a->forename, b->forename);
}