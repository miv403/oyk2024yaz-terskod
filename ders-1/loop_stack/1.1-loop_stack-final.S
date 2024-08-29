global _start

section .data

  align 2
  hello: db 'Hello world! iter:  ', 0xa
  helloLen: equ $-hello
  hello_iter_loc: equ $-hello-2 ; hello'nun uzunluğundan iki çıkarma

section .bss

section .text

  _start:

  mov ecx, 10

  _dongu_bas:
  sub ecx, 1 ; dec ecx
  cmp ecx, 0
  jz _exit
  push ecx
  call _print
  pop ecx
  jmp _dongu_bas

  _print:
  mov eax, 0x4
  mov ebx, 0x1
  mov ecx, hello
  mov edx, helloLen
  int 0x80
  ret

  _exit:
  mov eax, 0x1
  xor ebx, ebx
  int 0x80