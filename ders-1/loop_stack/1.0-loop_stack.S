global _start

section .data

  align 2
  hello: db 'Meraba:  ', 0xa
  helloLen: equ $-hello

section .bss

section .text

  _start:

    mov ecx, 11
    push ecx
    _dongu_bas:
    pop ecx
    sub ecx, 1 ; dec ecx 
    cmp ecx, 0
    je _exit ; jump zero
    push ecx
    jmp _print

    _print:

    pop edx
    add edx, 47
    mov [hello + 8], dl
    mov ebx, 10
    mov [hello + 9], bl
    sub edx, 47
    push edx

    mov eax, 0x4
    mov ebx, 0x1
    mov ecx, hello
    mov edx, helloLen
    int 0x80 ;; interrupt
    jmp _dongu_bas

    _exit:
    mov eax, 0x1
    xor ebx, ebx
    int 0x80

