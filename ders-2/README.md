# akışkan bellek

`rbp`: `rsp` (stack pointer)'ın tuttuğu adresin görüntüsünü tutar. böylece önceki
işlem sürecinin yeri kaybedilmez.

```asm
0000000000001149 <topla>:
    1149:       f3 0f 1e fa   endbr64
    114d:       55            push   rbp
    114e:       48 89 e5      mov    rbp,rsp
    1151:       89 7d fc      mov    DWORD PTR [rbp-0x4],edi
    1154:       89 75 f8      mov    DWORD PTR [rbp-0x8],esi
    1157:       8b 55 fc      mov    edx,DWORD PTR [rbp-0x4]
    115a:       8b 45 f8      mov    eax,DWORD PTR [rbp-0x8]
    115d:       01 d0         add    eax,edx
    115f:       5d            pop    rbp
    1160:       c3            ret
```

- `[rbp-0x4]`: `rbp`'nin gösterdiği değerden 4 geri.
- `esi`: source index
- `edi`: destination index
- `eax`: geri dönüş değeri *accumulator*'a döner.
- `lea`: load effective address

> [!NOTE]
>
> statik derleme
>
> ```terminal
> gcc -static hello.c -o hello
> ```
>
> kullanılan kütüphaneler ikil dosyaya eklenir.

## veri yapıları

### bağlı listeler

```C
struct Node {
    void *next;
    int data;
}
```

```text
|----| |----|       |----| |-\-/-|
| 15 | |  o-|-----> | 10 | |  X  |
|----| |----|       |----| |-/-\-|
                             NULL  
```

## crack me easy

```gdb
    122c:       c1 e0 02                shl    eax,0x2  2^4 ile çarpma
    122f:       01 d0                   add    eax,edx  kendi ile toplama
```

eax beş ile çarpılmış olur.

```gdb
(gdb) info registers eax
eax            0x1fe               510
(gdb) x/x $rbp-0x10
0x7fffffffdbb0: 0x0000001f
(gdb)
```

`x/s $ ---` string

cmp'de break sonrasında stackdeki değere bakma

rbp-0x10'de (..?)

istenen değer karşılaştırma yapılan stack adresinde bulunur.

[changing register value](https://stackoverflow.com/questions/15440154/how-to-change-the-eflags-register-value-in-gdb)

`hexedit`

```gdb
    1247:       3b 45 f0                cmp    eax,DWORD PTR [rbp-0x10]
    124a:       75 0e                   jne    125a <main+0xb1>
```

`3b 45 f0 75 0e` ilgili emirlerin kodları

```hexedit
00001234   83 45 E8 05  8B 55 E8 89  D0 01 C0 01  D0 89 45 E8  8B 45 E8 3B  .E...U........E..E.;
                                                                        ^
00001248   45 F0 75 0E  48 8D 3D 15  0E 00 00 E8  28 FE FF FF  EB 0C 48 8D  E.u.H.=.....(.....H.
                  ^
```

`jne` emiri `je` ile değiştirilir. bir nibble
değiştirilir böylece her değer için zıplama sağlanır.
75 74'e değiştirilir.

`je` : 74
`jne` : 75
