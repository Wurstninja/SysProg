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

```rust
use std::env;

fn main()
{
    let args: Vec<String> = env::args().collect();
    if args.len() != 4
    {
        panic!("Fuck");
    }

    let mat1: Vec<Vec<i64>> = read_mat(args[1].as_str());
    let mat2: Vec<Vec<i64>> = read_mat(args[3].as_str());
    print_mat(&mat1);
    print!("\n");
    print_mat(&mat2);
    print!("\n");

    let mat3: Vec<Vec<i64>>;

    match args[2].as_str()
    {
        "+" => mat3 = mat_add(&mat1, &mat2),
        "-" => mat3 = mat_sub(&mat1, &mat2),
        _ => panic!("Fuck"),
    }

    print_mat(&mat3);
}

fn read_mat(s: &str) -> Vec<Vec<i64>>
{
    let mut mat: Vec<Vec<i64>> = Vec::new();
    let rows = s.split(";");
    let rows_iter = rows.into_iter().enumerate();
    for (i, r) in rows_iter
    {
        mat.push(Vec::new());
        let col = r.split(",");
        for c in col
        {
            mat[i].push(c.parse::<i64>().unwrap());
        }
    }
    return mat;
}

fn mat_add(m1: &Vec<Vec<i64>>, m2: &Vec<Vec<i64>>) -> Vec<Vec<i64>>
{
    let num_rows = m1.len();
    let num_cols = m1[0].len();
    assert!(num_rows == m2.len() && num_cols == m2[0].len(), "wrong dimensions");

    let mut mat: Vec<Vec<i64>> = Vec::with_capacity(num_rows);

    for i in 0..num_rows
    {
        mat.push(Vec::with_capacity(num_cols));
        for j in 0..num_cols
        {
            mat[i].push(m1[i][j] + m2[i][j]);
        }
    }

    return mat;
}

fn mat_sub(m1: &Vec<Vec<i64>>, m2: &Vec<Vec<i64>>) -> Vec<Vec<i64>>
{
    let num_rows = m1.len();
    let num_cols = m1[0].len();
    assert!(num_rows == m2.len() && num_cols == m2[0].len(), "wrong dimensions");

    let mut mat: Vec<Vec<i64>> = Vec::with_capacity(num_rows);

    for i in 0..num_rows
    {
        mat.push(Vec::with_capacity(num_cols));
        for j in 0..num_cols
        {
            mat[i].push(m1[i][j] - m2[i][j]);
        }
    }

    return mat;
}

fn print_mat(mat: &Vec<Vec<i64>>)
{
    for i in mat
    {
        for j in i
        {
            print!("{} ", j);
        }
        println!("")
    }
}
```

## Aufgabe 10

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define bwuah(expr) bwuah_msg(expr, NULL)

#define bwuah_msg(expr, msg) \
    if (!(expr)) \
        __assertion_failed__(__FILE__, __LINE__, msg)

#define bwuah_warn(expr, msg) if(!(expr))fprintf(stderr, "BWUARN: %s\n", msg)

void __assertion_failed__(char* file, int line, char* msg);

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

void __assertion_failed__(char* file, int line, char* msg)
{
    fprintf(stderr, "BWUASSERTION: %s : %i\n", file, line);
    if(msg) fprintf(stderr, "     MESSAGE: %s\n", msg);
    exit(EXIT_FAILURE);
}
```
