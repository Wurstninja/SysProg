section .text
global _start

print_num:

    rbp, rsp        ; save base_ptr
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
