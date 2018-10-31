# Abgabe 4 - Lenni

[Assignment PDF](https://paste.bwuah.me/Uebungsblatt04-WS1819.pdf)  
contact computerscience@uni-bonn.de

## Aufgabe 14

```rust
fn main()
{
    let mut test = [32, 45, 86, 91, 12, 45, 2, 71];
    print_arr  (&     test);
    bubble_sort(& mut test);
    print_arr  (&     test);
}

fn bubble_sort(array: & mut [i64])
{
    let mut modified = true;
    while modified
    {
        modified = false;
        for i in 1..array.len()
        {
            if array[i - 1] > array[i]
            {
                modified = true;
                array[i - 1] = array[i - 1] + array[i];
                array[  i  ] = array[i - 1] - array[i];
                array[i - 1] = array[i - 1] - array[i];
            }
        }
    }
}

fn print_arr(array: & [i64])
{
    for (i, e) in array.iter().enumerate()
    {
        print!("{}{}", e, if i + 1 < array.len() { ", " } else { "" });
    }
    println!();
}
```