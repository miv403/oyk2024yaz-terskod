global _start

section .data

  align 2
  hello: db 'Merhabalar, Dostum!', 0xa
  helloLen: equ $-hello

section .bss

section .text

  _start:
    mov eax, 0x4
    mov ebx, 0x1
    mov ecx, hello
    mov edx, helloLen
    int 0x80 ;; interrupt

    ;mov eax, 0x1
    ;xor ebx, ebx
    ;int 0x80

