#include "genlist.h"

typedef struct my_data
{
    char* vn;
    char* nn;
}my_data;

int my_print(my_data*);

int main()
{
    int err;
    node* my_list = NULL;
    my_data* elem = malloc(sizeof(my_data));
    elem->vn = "test";
    elem->nn = "popo";
    my_list = malloc(sizeof(node));
    my_list->next = NULL;
    my_list->data = (void*) elem;
    err = print(my_list, (int (*)(void*)) my_print );
    if(err == EXIT_FAILURE)
    {
        printf("ERROR: couldn't call print() from genlist.h\n");
    }
    return 0;
}

int my_print(my_data* elem)
{
    printf("%s, %s\n", elem->vn, elem->nn);
    return EXIT_SUCCESS;
}