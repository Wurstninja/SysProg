# Rust

contact rust@bwuah.me

## General

### Format

- `{}` for general purpose
- `{?}` for debug

### Unwrap Error

`my_vector.last().unwrap()` to get the last element, and not a wrapper including errors.

### String to Int

`my_string.parse::<i64>().unwrap()`

### Enumerate

`for (index, element) in ___.into_iter().enumerate() {...}`

### Command Line Parameter

`let args: Vec<String> = std::env::args().collect()`  
`std::env::args()` returns an iterator, `collect()` converts it into a vector.

### Type Hints

`let mat1: Vec<Vec<i64>> = ...`  
Annotate the type, usually rustc can infere the type.

## Flow Control

### For Loop

```rust
for x in 0..10
{
    println!("{}", x);
}
```

## Pattern Matching

```rust
match args[2].as_str()
{
    "+" => mat3 = mat_add(mat1, mat2),
    "-" => mat3 = mat_sub(mat1, mat2),
     _  => panic!("Fuck"),
}
```

## Assertions

conditional termination of the programme

- with `assert!(expr)` you check `expr`'s boolean value
- with `assert!(expr, msg_string)` you customise the message