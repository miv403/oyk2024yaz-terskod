;; iki sayı ata
;; topla
;; "Hello world" üzerine yaz
;; write ile ekrana yaz

global _start

section .data

    align 2
    hello: db 'Hello World!', 0xa
    helloLen: equ $-hello

section .bss

section .text

    _start:
        mov eax, 0x4
        mov ebx, 0x1
        mov ecx, hello
        mov edx, helloLen
        int 0x80

        mov eax, 30
        mov ebx, 60
        add eax, ebx
        xor ecx, ecx
        mov ecx, eax

        mov [hello + 9], cl ;; <<< ecx

        mov eax, 0x4
        mov ebx, 0x1
        mov ecx, hello
        mov edx, helloLen
        int 0x80
        
        mov eax, 0x1
        xor ebx, ebx
        int 0x80
