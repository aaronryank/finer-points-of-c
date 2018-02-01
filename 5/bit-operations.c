#include <stdio.h>

int main(void)
{

 /* REFERENCE SHEET
    Copyright (C) 2008-2016 Ryan Klingler

    << RSHIFT
    >> LSHIFT
    &  BITWISE AND
    |  BITWISE OR
    ^  XOR
    ~  BITWISE NEGATE

    x     = 0b1100  = 0d12
    y     = 0b1010  = 0d10
    x & y = 0b1000  = 0d8
    x | y = 0b1110  = 0d14
    x ^ y = 0b0110  = 0d6
      ~ y = 0b0101  = 0d5   */

    int x = 12, y = 10;
    printf("12 >> 5 = %d\n", 64 >> 5);
    printf("64 << 5 = %d\n\n", 12 << 5);
    printf("---------\nx %d y %d\n---------\n\n", x, y);
    printf("x & y %d\n", x & y);
    printf("x | y %d\n", x | y);
    printf("x ^ y %d\n", x ^ y);
    printf("  ~ y %d\n",   ~ y);
}
