# I_know

This code is under the Public domain : available, usable, editable, sharable... for everyone. 
I't great. I know. 

Code by - Mewily : https://github.com/Thomas-Mewily
Thank to THEWORLD for helping me with this logic : https://github.com/THEWORLD210202

```cpp
1 : true.
0 : false.

11 : this is true
10 : I don't care
01 : this is false
00 : I don't know

111 : I   know,   that this is true 
110 : I ignore,   that this is true 
101 : I   know,   that I don't care 
100 : I ignore,   that I don't care 
011 : I   know,   that this is false
010 : I ignore,   that this is false
001 : I   know,   that I don't know 
000 : I ignore,   that I don't know 

1111 : I   know,   that I   know,   that this is true
1110 : I ignore,   that I   know,   that this is true
1101 : I   know,   that I ignore,   that this is true
1100 : I ignore,   that I ignore,   that this is true
1011 : I   know,   that I   know,   that I don't care
1010 : I ignore,   that I   know,   that I don't care
1001 : I   know,   that I ignore,   that I don't care
1000 : I ignore,   that I ignore,   that I don't care
0111 : I   know,   that I   know,   that this is false
0110 : I ignore,   that I   know,   that this is false
0101 : I   know,   that I ignore,   that this is false
0100 : I ignore,   that I ignore,   that this is false
0011 : I   know,   that I   know,   that I don't know
0010 : I ignore,   that I   know,   that I don't know
0001 : I   know,   that I ignore,   that I don't know
0000 : I ignore,   that I ignore,   that I don't know

11111 : I   know,   that I   know,   that I   know,   that this is true
11110 : I ignore,   that I   know,   that I   know,   that this is true
11101 : I   know,   that I ignore,   that I   know,   that this is true
11100 : I ignore,   that I ignore,   that I   know,   that this is true
11011 : I   know,   that I   know,   that I ignore,   that this is true
11010 : I ignore,   that I   know,   that I ignore,   that this is true
11001 : I   know,   that I ignore,   that I ignore,   that this is true
11000 : I ignore,   that I ignore,   that I ignore,   that this is true
10111 : I   know,   that I   know,   that I   know,   that I don't care
10110 : I ignore,   that I   know,   that I   know,   that I don't care
10101 : I   know,   that I ignore,   that I   know,   that I don't care
10100 : I ignore,   that I ignore,   that I   know,   that I don't care
10011 : I   know,   that I   know,   that I ignore,   that I don't care
10010 : I ignore,   that I   know,   that I ignore,   that I don't care
10001 : I   know,   that I ignore,   that I ignore,   that I don't care
10000 : I ignore,   that I ignore,   that I ignore,   that I don't care
01111 : I   know,   that I   know,   that I   know,   that this is false
01110 : I ignore,   that I   know,   that I   know,   that this is false
01101 : I   know,   that I ignore,   that I   know,   that this is false
01100 : I ignore,   that I ignore,   that I   know,   that this is false
01011 : I   know,   that I   know,   that I ignore,   that this is false
01010 : I ignore,   that I   know,   that I ignore,   that this is false
01001 : I   know,   that I ignore,   that I ignore,   that this is false
01000 : I ignore,   that I ignore,   that I ignore,   that this is false
00111 : I   know,   that I   know,   that I   know,   that I don't know
00110 : I ignore,   that I   know,   that I   know,   that I don't know
00101 : I   know,   that I ignore,   that I   know,   that I don't know
00100 : I ignore,   that I ignore,   that I   know,   that I don't know
00011 : I   know,   that I   know,   that I ignore,   that I don't know
00010 : I ignore,   that I   know,   that I ignore,   that I don't know
00001 : I   know,   that I ignore,   that I ignore,   that I don't know
00000 : I ignore,   that I ignore,   that I ignore,   that I don't know

111111 : I   know,   that I   know,   that I   know,   that I   know,   that this is true
111110 : I ignore,   that I   know,   that I   know,   that I   know,   that this is true
111101 : I   know,   that I ignore,   that I   know,   that I   know,   that this is true
111100 : I ignore,   that I ignore,   that I   know,   that I   know,   that this is true
111011 : I   know,   that I   know,   that I ignore,   that I   know,   that this is true
111010 : I ignore,   that I   know,   that I ignore,   that I   know,   that this is true
111001 : I   know,   that I ignore,   that I ignore,   that I   know,   that this is true
111000 : I ignore,   that I ignore,   that I ignore,   that I   know,   that this is true
110111 : I   know,   that I   know,   that I   know,   that I ignore,   that this is true
110110 : I ignore,   that I   know,   that I   know,   that I ignore,   that this is true
110101 : I   know,   that I ignore,   that I   know,   that I ignore,   that this is true
110100 : I ignore,   that I ignore,   that I   know,   that I ignore,   that this is true
110011 : I   know,   that I   know,   that I ignore,   that I ignore,   that this is true
110010 : I ignore,   that I   know,   that I ignore,   that I ignore,   that this is true
110001 : I   know,   that I ignore,   that I ignore,   that I ignore,   that this is true
110000 : I ignore,   that I ignore,   that I ignore,   that I ignore,   that this is true
101111 : I   know,   that I   know,   that I   know,   that I   know,   that I don't care
101110 : I ignore,   that I   know,   that I   know,   that I   know,   that I don't care
101101 : I   know,   that I ignore,   that I   know,   that I   know,   that I don't care
101100 : I ignore,   that I ignore,   that I   know,   that I   know,   that I don't care
101011 : I   know,   that I   know,   that I ignore,   that I   know,   that I don't care
101010 : I ignore,   that I   know,   that I ignore,   that I   know,   that I don't care
101001 : I   know,   that I ignore,   that I ignore,   that I   know,   that I don't care
101000 : I ignore,   that I ignore,   that I ignore,   that I   know,   that I don't care
100111 : I   know,   that I   know,   that I   know,   that I ignore,   that I don't care
100110 : I ignore,   that I   know,   that I   know,   that I ignore,   that I don't care
100101 : I   know,   that I ignore,   that I   know,   that I ignore,   that I don't care
100100 : I ignore,   that I ignore,   that I   know,   that I ignore,   that I don't care
100011 : I   know,   that I   know,   that I ignore,   that I ignore,   that I don't care
100010 : I ignore,   that I   know,   that I ignore,   that I ignore,   that I don't care
100001 : I   know,   that I ignore,   that I ignore,   that I ignore,   that I don't care
100000 : I ignore,   that I ignore,   that I ignore,   that I ignore,   that I don't care
011111 : I   know,   that I   know,   that I   know,   that I   know,   that this is false
011110 : I ignore,   that I   know,   that I   know,   that I   know,   that this is false
011101 : I   know,   that I ignore,   that I   know,   that I   know,   that this is false
011100 : I ignore,   that I ignore,   that I   know,   that I   know,   that this is false
011011 : I   know,   that I   know,   that I ignore,   that I   know,   that this is false
011010 : I ignore,   that I   know,   that I ignore,   that I   know,   that this is false
011001 : I   know,   that I ignore,   that I ignore,   that I   know,   that this is false
011000 : I ignore,   that I ignore,   that I ignore,   that I   know,   that this is false
010111 : I   know,   that I   know,   that I   know,   that I ignore,   that this is false
010110 : I ignore,   that I   know,   that I   know,   that I ignore,   that this is false
010101 : I   know,   that I ignore,   that I   know,   that I ignore,   that this is false
010100 : I ignore,   that I ignore,   that I   know,   that I ignore,   that this is false
010011 : I   know,   that I   know,   that I ignore,   that I ignore,   that this is false
010010 : I ignore,   that I   know,   that I ignore,   that I ignore,   that this is false
010001 : I   know,   that I ignore,   that I ignore,   that I ignore,   that this is false
010000 : I ignore,   that I ignore,   that I ignore,   that I ignore,   that this is false
001111 : I   know,   that I   know,   that I   know,   that I   know,   that I don't know
001110 : I ignore,   that I   know,   that I   know,   that I   know,   that I don't know
001101 : I   know,   that I ignore,   that I   know,   that I   know,   that I don't know
001100 : I ignore,   that I ignore,   that I   know,   that I   know,   that I don't know
001011 : I   know,   that I   know,   that I ignore,   that I   know,   that I don't know
001010 : I ignore,   that I   know,   that I ignore,   that I   know,   that I don't know
001001 : I   know,   that I ignore,   that I ignore,   that I   know,   that I don't know
001000 : I ignore,   that I ignore,   that I ignore,   that I   know,   that I don't know
000111 : I   know,   that I   know,   that I   know,   that I ignore,   that I don't know
000110 : I ignore,   that I   know,   that I   know,   that I ignore,   that I don't know
000101 : I   know,   that I ignore,   that I   know,   that I ignore,   that I don't know
000100 : I ignore,   that I ignore,   that I   know,   that I ignore,   that I don't know
000011 : I   know,   that I   know,   that I ignore,   that I ignore,   that I don't know
000010 : I ignore,   that I   know,   that I ignore,   that I ignore,   that I don't know
000001 : I   know,   that I ignore,   that I ignore,   that I ignore,   that I don't know
000000 : I ignore,   that I ignore,   that I ignore,   that I ignore,   that I don't know
```
