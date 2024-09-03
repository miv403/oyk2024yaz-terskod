---
  date: 2024-08-28T11:07
---

# terskod mühendisliği

[block and char devices](https://www.geeksforgeeks.org/block-and-character-devices-in-operating-system/)

## ls komutu

```terminal
$ ls -las1
total 0
0 drwxrwxrwx 1 mivuntu mivuntu 4096 Aug 28 11:00 .
0 drwxrwxrwx 1 mivuntu mivuntu 4096 Aug 28 10:58 ..
0 -rwxrwxrwx 1 mivuntu mivuntu    0 Aug 28 11:00 ornek
```

> izin sıralaması; kullanıcı > grup > herkes

**örnek kullanımlar;**

- `nasm  -f elf32 -o hello.o hello.S` [^1]
- `ld -m elf_i386 -o hello_elf32 hello.o` [^3]
- `objdump -M intel -D hello.o` [^2]

```terminal
$ file hello_elf32
hello_elf32: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), statically linked, not stripped
```

**LSP**: least significant bit (en az önemli bit [^4] ör.: 2^0)

**LE (little endian)**: sağdan

**BE (big endian)**: soldan

[little endian vs big endian](https://thebittheories.com/little-endian-vs-big-endian-b4046c63e1f2)

aynı ikil sayı dizisi farklı biçimlerde okunabilir:

```text
1011001
^
2^7

1011001
      ^
      2^7
```

işlemcinin sonluluk düzenine göre verilen karakter dizisi
farklı biçimlerde sıralanabilir.

## disassembling (parçalama)

[intel reference manual](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)

```terminal
$ objdump -M intel -D hello
             ^        ^
     söz dizim        ikil dosya-
  amd64 de ola-       nın adı
         bilir.
```

### sistem çağrıları

- **interrupt**: kesme
- **poll**: yapılan bir işin varlığını denetleme(?)

`int 0x80`: eax'deki numaradaki syscall çağırılıyor.

ön hazırlık (kaydedicilerin doldurulması) tamamlandıktan
sonra int çalıştırılıyor ve gerekli parametreler ile
sistem çağrısı gerçekleşiyor

- [linux int syscalls](https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md#x86-32_bit)
- [linux syscalls](https://x86.syscall.sh/)
- [linux sistem çağrıları kaynak kodları](https://elixir.bootlin.com/linux/v6.10.6/A/ident/sys_write)
- [read_write.c](https://elixir.bootlin.com/linux/v6.10.6/source/fs/read_write.c#L652)

### kaydediciler

**kaydedicilerin adları**:

- A: accumulator
- B: base
- C: counter
- D: destination
- IP: instruction pointer
- SP: stack pointer

`_start`'a breakpoint koyduktan sonra `disas _start` ile
`_start`ın içine bakıyoruz. `si` ile programı
ilerletiyoruz. `info registers <register>` ile
register(lar)'a bakılabiliyor.

> [!NOTE] kaydedicilerin içeriğine bakmak
>
> ```terminal
> (gdb) info registers eax
>
>  eax kaydedicisinin içeriğini gösterir
> ```

### gdb

`disas <fonksiyon-adı>`: belirtilen izlence
bölümünün parçalanması.

`run`: programı çalıştırma

`break <fonksiyon-adı>`: breakpoint, kırılma
noktası belirtme

> [!NOTE] intel gösteriminin kullanılması
>
> ```gdb
> (gdb) set disassembly-flavor intel
> ```

#### örnek gdb kullanımı

**continue**:

```gdb
(gdb) c 
```

**step instruction**:

```gdb
(gdb) disas _start
Dump of assembler code for function _start:
=> 0x08049000 <+0>:     mov    eax,0x4
   0x08049005 <+5>:     mov    ebx,0x1
   0x0804900a <+10>:    mov    ecx,0x804a000
   0x0804900f <+15>:    mov    edx,0x14
   0x08049014 <+20>:    int    0x80
   0x08049016 <+22>:    mov    eax,0x1
   0x0804901b <+27>:    xor    ebx,ebx
   0x0804901d <+29>:    int    0x80
End of assembler dump.
(gdb) si
0x08049005 in _start ()
(gdb) info registers eax
eax            0x4                 4
(gdb) si
0x0804900a in _start ()
(gdb) info registers ebx
ebx            0x1                 1
(gdb) si
0x0804900f in _start ()
(gdb) info registers ecx
ecx            0x804a000           134520832
(gdb) si
0x08049014 in _start ()
(gdb) info registers edx
edx            0x14                20
```

`(gdb) x <adrr>`: istenen adresin/kaydedicinin yazdırılması

`xxd <ikil dosya>`: ikil dosyanın ascii ve onaltılık gösteriminin çıktısı

```gdb
(gdb) x 0x08049000
0x8049000 <_start>:     0x000004b8
(gdb) x 0x804a000
0x804a000:      0x6c6c6548
(gdb) x/10 0x804a000
0x804a000:      0x6c6c6548      0x6f57206f      0x0a646c72      Cannot access memory at address 0x804a00c
(gdb) x/10c 0x804a000
0x804a000:      72 'H'  101 'e' 108 'l' 108 'l' 111 'o' 32 ' '  87 'W'  111 'o'
0x804a008:      114 'r' 108 'l'
(gdb) x/10s 0x804a000
        ^
        10 tane adresi gösterir.
        bu çıktıda diğer adreslere
        erişilemiyor.

0x804a000:      "Hello World\n"
```

[^1]: nesne (object) dosyasına dönüştürme
[^2]: bütüncül disassembler programı
[^3]: linkleme işlemi
[^4]: binary digit, ikil sayı
