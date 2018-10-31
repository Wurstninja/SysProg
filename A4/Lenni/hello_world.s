section .data
    hello: db "Hello, World!", 10    ; 10 for ASCII LF 
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
