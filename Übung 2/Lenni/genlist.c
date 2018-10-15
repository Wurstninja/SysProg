#include "genlist.h"

int print(node* list, int (*print_element)(void*))
{
    int err;
    node* cur = list;
    while(cur)
    {
        err = print_element(cur->data);
        if(err == EXIT_FAILURE)
        {
            printf("ERROR: Printing out Data failed!\n");
            return EXIT_FAILURE;
        }
        cur = cur->next;
    }
    return EXIT_SUCCESS;    
}