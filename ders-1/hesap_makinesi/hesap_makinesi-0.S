global _start

section .data

	align 2
	hello: db 'Hello world!', 0xa
	helloLen: equ $-hello
	num1: db ' '
	num1_len: equ $-num1
	num2: db ' '
	num2_len: equ $-num2
	islem: db ' '
	islem_len: equ $-islem
	nl: db 0xa
	nl_len: equ $-nl
section .bss

section .text

	_start:

	_num1:
	mov eax, 0x3
	mov ebx, 0x0
	mov ecx, num1
	mov edx, num1_len
	int 0x80

	_num2:
	mov eax, 0x3
	mov ebx, 0x0
	mov ecx, num2
	mov edx, num2_len
	int 0x80

	_islem:
	mov eax, 0x3
	mov ebx, 0x0
	mov ecx, islem
	mov edx, islem_len
	int 0x80

	_num1_print:
	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, num1
	mov edx, num1_len
	int 0x80

	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, nl
	mov edx, nl_len
	int 0x80

	_num2_print:
	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, num2
	mov edx, num2_len
	int 0x80

	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, nl
	mov edx, nl_len
	int 0x80

	_islem_print:
	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, islem
	mov edx, islem_len
	int 0x80

	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, nl
	mov edx, nl_len
	int 0x80

	_islem_yap:
	xor eax, eax
	mov al, [num1]
	xor ebx, ebx
	mov bl, [num2]
	xor ecx, ecx
	mov cl, [islem]
	cmp ecx, 43 ; +
	je _topla
	cmp ecx, 45 ; -
	je _cikart
	cmp ecx, 47 ; /
	je _bol
	cmp ecx, 42 ; *
	je _carp

	_topla:
	add eax,ebx
	jmp _res_print

	_cikart:
	sub eax, ebx
	jmp _res_print

	_carp:
	MUL ebx
	JMP _res_print

	_bol:
	div ebx
	jmp _res_print

	_res_print:
	mov eax, num1
	add eax, 48
	mov [num1], eax

	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, num1
	mov edx, num1_len
	int 0x80


	_hello_print:
	mov eax, 0x4
	mov ebx, 0x1
	mov ecx, hello
	mov edx, helloLen
	int 0x80

	_exit:
	mov eax, 0x1
	xor ebx, ebx
	int 0x80
