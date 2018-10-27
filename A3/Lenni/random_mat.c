#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include "bwuassert.h"

#define MAX_VAL 20
#define MIN_VAL -20

int main(int argc, char* argv[])
{
    bwuah_msg(argc == 3, "WRONG NUMBER OF ARGUMENTS");

    char* ptr;

    int rows = strtol(argv[1], &ptr, 10);

    bwuah(errno == 0);

    bwuah_msg(ptr!=argv[1], "STRTOL[1] FAILED: NO NUMERICALS MATCHED");

    if(ptr != NULL && *ptr != 0)
    {
        fprintf(stderr, "WARNING: NOT ALL READ CHARACTERS OF THE FIRST ARGUMENT WERE NUMERICAL\n");
        fprintf(stderr, "->READ: %i (ASCII), '%c' (CHAR)\n", (int) *ptr, *ptr);
    }

    int cols = strtol(argv[2], &ptr, 10);

    bwuah(errno == 0);
    
    bwuah_msg(ptr!=argv[2], "STRTOL[2] FAILED: NO NUMERICALS MATCHED");

    if(ptr != NULL && *ptr != 0)
    {
        fprintf(stderr, "WARNING: NOT ALL READ CHARACTERS OF THE SECOND ARGUMENT WERE NUMERICAL\n");
        printf("->READ: %i (ASCII), '%c' (CHAR)\n", (int) *ptr, *ptr);
    }

    bwuah_warn(MIN_VAL != MAX_VAL, "MIN_VAL equals MAX_VAL");

    srand(time(NULL));

    for(int i = 0; i < rows; i++)  
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%i%s", rand() % (MAX_VAL+1-MIN_VAL) + MIN_VAL, j+1 == cols ? (i+1 == rows ? "" : ";") : ",");
        }
    }  

    return EXIT_SUCCESS;
}