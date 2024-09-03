; dört işlem
; kullanıcı girdisi
; sonuç çıktısı

global _start

section .data

  align 2

; sayi_gir: db 'sayi girin: '
; sayi_gir_c: equ $-sayi_gir

; islem: db 'islem girin: '
; islem_c: equ $-islem

  buf: db ' '
  buf_c: equ $-buf

section .bss

section .text

  _start:
    ; stack; islem, sayi1, sayi2
;   call _islem_p
    call _read

    cmp ecx, 43 ; +
    je _topla
;   cmp ecx, 42 ; *
;   je _carp
;   cmp ecx, 45 ; -
;   je _cikar
;   cmp ecx, 47 ;  /
;   je _bol
    jmp _exit

    _topla:
;   call _sayi_al
    call _read
    push ecx
    call _read
    push ecx

    pop eax
    pop ebx

    sub eax, 48
    sub ebx, 48

    add eax, ebx
    jmp _exit

    _read:
    mov eax, 0x3
    mov ebx, 0x0
    mov ecx, buf
    mov edx, 0x1
    int 0x80 ;; interrupt
    ret

;   _islem_p:
;   mov eax, 0x4
;   mov ebx, 0x1
;   mov ecx, islem
;   mov edx, islem_c
;   int 0x80
;   ret
    
;   _sayi_al:
;   call _sayi_gir_p
;   call _read
;   push ecx

;   call _sayi_gir_p
;   call _read
;   push ecx
;   ret

;   _sayi_gir_p:
;   mov eax, 0x4
;   mov ebx, 0x1
;   mov ecx, sayi_gir
;   mov edx, sayi_gir_c
;   int 0x80
;   ret
;   


    _exit:
    mov eax, 0x1
    xor ebx, ebx
    int 0x80

