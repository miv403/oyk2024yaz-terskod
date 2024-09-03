---
   date: 2024-08-29T16:33
---
# ders 1

relocation truncated to fit

`global _start`: `_start` etiketi ile başla

## Stack

ilgili `push` talimatlarına `breakpoint` koyduktan sonra `run` ile program çalıştırılır.
`c` komutu ile program breakpointlerden sonra devam ettirilir. `info registers esp` ile
stack ptr kaydedicisininin içeriği denetlenebilir.

- `call` çağrıldığı adresi stack'e koyuyor. [^1]
- `ret` stackdeki son adres değerine geri dönüyor. [^2]

`si`: step instruction
`pop <register>`: intel man s.1729

- `(gdb) x/10x $esp`: stack görüntüleme

```gdb
(gdb) x/10x $esp
0xffffceac:     0x00000009      0x00000001      0xffffd02b      0x00000000
0xffffcebc:     0xffffd076      0xffffd086      0xffffd09e      0xffffd0ab
0xffffcecc:     0xffffd0c2      0xffffd0cd
```

**push kullanımı**:

```gdb
Dump of assembler code for function _push:
   0x08049016 <+0>:     push   0xa
   0x08049018 <+2>:     push   0x14
   0x0804901a <+4>:     push   0x1e
   0x0804901c <+6>:     push   0x28
   0x0804901e <+8>:     push   0x32
   0x08049020 <+10>:    mov    eax,0x1
   0x08049025 <+15>:    xor    ebx,ebx
   0x08049027 <+17>:    int    0x80
End of assembler dump.
(gdb) run

Merhabalar, Dostum!

Breakpoint 1, 0x08049016 in _push ()
(gdb) info registers esp
esp            0xffffce20          0xffffce20
(gdb) info registers eax
eax            0x14                20
(gdb) si
0x08049018 in _push ()
(gdb) si
0x0804901a in _push ()
(gdb) info registers esp
esp            0xffffce18          0xffffce18
(gdb) si
0x0804901c in _push ()
(gdb) info registers esp
esp            0xffffce14          0xffffce14
```

**push ve pop kullanımı**:

```gdb
(gdb) disas _start
Dump of assembler code for function _start:
   0x08049000 <+0>:     mov    eax,0x4
   0x08049005 <+5>:     mov    ebx,0x1
   0x0804900a <+10>:    mov    ecx,0x804a000
   0x0804900f <+15>:    mov    edx,0x14
   0x08049014 <+20>:    int    0x80
End of assembler dump.
(gdb) disas _push
Dump of assembler code for function _push:
   0x08049016 <+0>:     push   0xa
   0x08049018 <+2>:     push   0x14
   0x0804901a <+4>:     push   0x1e
   0x0804901c <+6>:     push   0x28
   0x0804901e <+8>:     push   0x32
   0x08049020 <+10>:    pop    ebx
   0x08049021 <+11>:    pop    ebx
   0x08049022 <+12>:    pop    ebx
   0x08049023 <+13>:    pop    ebx
   0x08049024 <+14>:    pop    ebx
   0x08049025 <+15>:    mov    eax,0x1
   0x0804902a <+20>:    xor    ebx,ebx
   0x0804902c <+22>:    int    0x80
End of assembler dump.
(gdb) break *0x0804901c
Breakpoint 1 at 0x804901c
(gdb) break *0x0804901e
Breakpoint 2 at 0x804901e
(gdb) break *0x08049020
Breakpoint 3 at 0x8049020
(gdb) break *0x08049021
Breakpoint 4 at 0x8049021
(gdb) break *0x08049024
Breakpoint 5 at 0x8049024
(gdb) run
Starting program: /mnt/c/Users/ahmet emin/programming/kamp/ders-1/bin/stack_elf32
Merhabalar, Dostum!

Breakpoint 1, 0x0804901c in _push ()
(gdb) info registers esp
esp            0xffffce14          0xffffce14
(gdb) si

Breakpoint 2, 0x0804901e in _push ()
(gdb) info registers esp
esp            0xffffce10          0xffffce10
(gdb) si

Breakpoint 3, 0x08049020 in _push ()
(gdb) info registers esp ebx
esp            0xffffce0c          0xffffce0c
ebx            0x1                 1
(gdb) si

Breakpoint 4, 0x08049021 in _push ()
(gdb) info registers esp ebx
esp            0xffffce10          0xffffce10
ebx            0x32                50
(gdb) si
0x08049022 in _push ()
(gdb) info registers esp ebx
esp            0xffffce14          0xffffce14
ebx            0x28                40
(gdb) si
0x08049023 in _push ()
(gdb) info registers esp ebx
esp            0xffffce18          0xffffce18
ebx            0x1e                30
(gdb) si

Breakpoint 5, 0x08049024 in _push ()
(gdb) info registers esp ebx
esp            0xffffce1c          0xffffce1c
ebx            0x14                20
(gdb) si
0x08049025 in _push ()
(gdb) info registers esp ebx
esp            0xffffce20          0xffffce20
ebx            0xa                 10
```

### stack döngüsü

>[!NOTE]
>
> **döngü yalancı kodu**
>
> ```text
> c = 10
> _dongu_bas: c = (c - 1)
> if (c == 0)
>     exit()
> else
>     print
>     jump dongu_bas
> ```
<!---->
> [!NOTE]
>
> **yanlış çalışan döngünün hata ayıklaması**
>
> ```gdb
> (gdb) break _start
> Breakpoint 1 at 0x8049000
> (gdb) break _dongu_bas
> Breakpoint 2 at 0x8049005
> (gdb) break _print
> Breakpoint 3 at 0x804900f
> (gdb) run
> Starting program: /mnt/c/Users/ahmet emin/programming/kamp/ders-1/bin/loop_stack_elf32
> 
> Breakpoint 1, 0x08049000 in _start ()
> (gdb) si
> 
> Breakpoint 2, 0x08049005 in _dongu_bas ()
> (gdb) c
> Continuing.
> 
> Breakpoint 3, 0x0804900f in _print ()
> (gdb) c
> Continuing.
> Meraba:
> 
> Breakpoint 2, 0x08049005 in _dongu_bas ()
> (gdb) infor registers ecx
> Undefined command: "infor".  Try "help".
> (gdb) info registers ecx
> ecx            0x804a000           134520832
> ```

`ecx` kaydedicisi `_print` alt işleminde
değiştirildiğinden ötürü `ecx` kaydedicisi
`push` ile stack'e aktarıldıktan sonra `_print` alt
işlemine atlanmalı. böylece `_dongu_bas` alt işlemine
dönünce *stack*'deki döngü değişkeni tekrar
kullanılabilir.

## programın çıkış çağrısının olmaması

kaynak dosyası: `./hello_wo_return.S`

>[!NOTE]
>
> **segmentation fault**
>
> ```gdb
> Breakpoint 1, 0x08049000 in _start ()
> (gdb) disas _start
> Dump of assembler code for function _start:
> = 0x08049000 <+0>:     mov    eax,0x4
>    0x08049005 <+5>:     mov    ebx,0x1
>    0x0804900a <+10>:    mov    ecx,0x804a000
>    0x0804900f <+15>:    mov    edx,0x14
>    0x08049014 <+20>:    int    0x80
> End of assembler dump.
> (gdb) si
> 0x08049005 in _start ()
> (gdb) si
> 0x0804900a in _start ()
> (gdb) si
> 0x0804900f in _start ()
> (gdb) si
> 0x08049014 in _start ()
> (gdb) si
> Merhabalar, Dostum!
> 0x08049016 in ?? ()
> (gdb) si
>
> Program received signal SIGSEGV, Segmentation fault.
> 0x08049016 in ?? ()
> ```

[^1]: intel ref man s.155 ; intel ref man s.755
[^2]: s.1771
