# mdisass
Minimal Disassembler

````
$ echo -ne "\x46\x38\x55\x41\x2F\x01\xDC\x32\x3F" | ./mdisass -
00000000  46      inc esi
00000001  385541      cmp [ebp+0x41],dl
00000004  2F      das
00000005  01DC      add esp,ebx
00000007  323F      xor bh,[edi]
````

