#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <assert.h>
#include <signal.h>

void abortion(int sig)
{
    exit(EXIT_FAILURE);
}

#define MAX_VAL 20
#define MIN_VAL -20

int main(int argc, char* argv[])
{
    if(signal(SIGABRT, abortion) == SIG_ERR) exit(1);

    if(argc != 3)
    {
        fprintf(stderr, "WRONG NUMBER OF ARGUMENTS\n");
        return EXIT_FAILURE;
    }

    char* ptr;

    int rows = strtol(argv[1], &ptr, 10);

    assert(errno == 0);

    if(ptr == argv[1])
    {
        fprintf(stderr, "ABORT: STRTOL[1] FAILED: NO NUMERICALS MATCHED\n");
        return EXIT_FAILURE;
    }

    if(ptr != NULL && *ptr != 0)
    {
        fprintf(stderr, "WARNING: NOT ALL READ CHARACTERS OF THE FIRST ARGUMENT WERE NUMERICAL\n");
        printf("->READ: %i (ASCII), '%c' (CHAR)\n", (int) *ptr, *ptr);
    }

    int cols = strtol(argv[2], &ptr, 10);

    assert(errno == 0);
    
    if(ptr == argv[2])
    {
        fprintf(stderr, "ABORT: STRTOL[2] FAILED: NO NUMERICALS MATCHED\n");
        return EXIT_FAILURE;
    }

    if(ptr != NULL && *ptr != 0)
    {
        fprintf(stderr, "WARNING: NOT ALL READ CHARACTERS OF THE SECOND ARGUMENT WERE NUMERICAL\n");
        printf("->READ: %i (ASCII), '%c' (CHAR)\n", (int) *ptr, *ptr);
    }

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