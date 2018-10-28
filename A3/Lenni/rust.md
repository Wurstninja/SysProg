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