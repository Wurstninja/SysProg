# Abgabe 3 - Lenni

contact computerscience@uni-bonn.de

## Aufgabe 8

`curl https://sh.rustup.rs -sSf | sh`

hello_rust.rs:

```rust
fn main()
{
    println!("Hello, Rust!");
}
```

```bash
rustc hello_rust.rs
./hello_rust
```

```bash
cargo new hello_cargo
mv hello_rust.rs hello_cargo/src/main.rs
pushd hello_cargo/
cargo run
popd
```

## Aufgabe 9



## Aufgabe 10

```C
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

    if(errno != 0 || ptr == argv[1])
    {
        fprintf(stderr, "ABORT: STRTOL[1] FAILED: %s\n", errno!=0?"ERRNO != 0":"NO NUMERICALS MATCHED");
        return EXIT_FAILURE;
    }

    assert(ptr==NULL || *ptr == 0);

    if(ptr != NULL && *ptr != 0)
    {
        fprintf(stderr, "WARNING: NOT ALL READ CHARACTERS OF THE FIRST ARGUMENT WERE NUMERICAL\n");
        printf("->READ: %i (ASCII), '%c' (CHAR)\n", (int) *ptr, *ptr);
    }

    int cols = strtol(argv[2], &ptr, 10);

    if(errno != 0 || ptr == argv[2])
    {
        fprintf(stderr, "ABORT: STRTOL[2] FAILED: %s\n", errno!=0?"ERRNO != 0":"NO NUMERICALS MATCHED");
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
```
