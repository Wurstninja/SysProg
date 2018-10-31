# Abgabe 4 - Lenni

[Assignment PDF](https://paste.bwuah.me/Uebungsblatt04-WS1819.pdf)  
contact computerscience@uni-bonn.de

## Aufgabe 12 (incomplete)

*alle sources als NASM files*

### Hello World

```nasm
section .data
    hello: db "Hello, World!", 10   ; 10 for ASCII LF
    hello_strlen equ $ - hello      ; substract the addresses

section .text
global _start

_start:
    mov rax, 1              ; sys_write
    mov rdi, 1              ; stdout
    mov rsi, hello          ; pointer to buf
    mov rdx, hello_strlen   ; length of string
    syscall                 ; /sys_write

    mov rax, 60             ; sys_exit
    mov rdi, 0              ; EXIT_SUCCESS
    syscall                 ; /sys_exit

```

`nasm -f elf64 hello_world.s`  
`ld hello_world.o`  
`./a.out`

### Print Num

```nasm
section .text
global _start

print_num:

    mov rbp, rsp    ; save base_ptr
    mov rbx, 10     ; our base

build:
    xor rdx, rdx    ; clear rdx
    idiv rbx
    add dl, 48      ; single digit to ASCII
    sub rsp, 1      ; make space for one byte on stack
    mov [rsp], dl   ; put on stack

    cmp rax, 0
    jne build       ; if rax now 0, then we seperated all digits now 

    mov rax, 1
    mov rdi, 1
    lea rsi, [rsp]

    mov rdx, rbp    ; since the stack grows downwards
    sub rdx, rsp    ; rbp-rsp is the length of the string

    syscall         ; sys_write(stdout, string, stringlen);

    mov rsp, rbp    ; revert stack_ptr
    mov rax, 0      ; EXIT_SUCCESS
    ret

_start:

    mov rax, 13892
    call print_num

    sub rsp, 1
    mov BYTE [rsp], 10
    mov rax, 1
    mov rdx, 1
    mov rsi, rsp
    mov rdx, 1
    syscall                 ; printf("\n");

    mov rax, 60             ; sys_exit
    mov rdi, 0              ; EXIT_SUCCESS
    syscall                 ; /sys_exit

```

## Aufgabe 13

### a)

```nasm
xor eax, eax
```

Entspricht eax := 0

### b) 

```assembly
lea eax, [eax+eax+4]
```

Entspricht eax:=eax+eax+4.  
~~mov eax, eax+eax+4~~ ist nicht gültig.

### c)

```assembly
xor   ecx, ecx
cmp   eax, VAR_1
setnz cl
dec   ecx
and   ecx, VAR_2
add   ecx, VAR_3
```

wenn `eax != VAR_1` dann wird der low Bereich von edx auf 1 gesetzt  
mit `xor ecx, ecx` gilt also insgesamt: `edx:=(eax==VAR_1)?0:1`  
mit `dec edx`gilt also insgesamt: `edx:= (eax==VAR_1) ? -1 : 0`  
mit `and ecx, VAR_2` gilt also insgesamt: `edx:= (eax==VAR_1) ? (VAR_2-VAR_3) : 0`  
mit `add ecx, VAR_3` gilt also insgesamt: `edx:= (eax==VAR_1) ? VAR_2 : VAR_3`

### d)

```assembly
mov   edx, 0xcccccccd
mul   edx
shr   edx, 3
```

multipliziert den Wert in `eax` mit `419430.4`. Dabei werden nur 32bit integer Multiplikationen und Bitshifts verwendet.

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
