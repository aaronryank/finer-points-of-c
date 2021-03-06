# THE FINER POINTS OF C :|: BIT OPERATIONS
### Corresponding C source: "bit-operations.c"

### BIT OPERATIONS

    >>  RIGHT SHIFT     : Shift all of the bits in an integer one place to the right.
    <<  LEFT SHIFT      : Shift all of the bits in an integer one place to the left.
    &   BITWISE AND     : Each bit-position will be 1 if both of the corresponding bit positions of the given integers are also 1.
    |   BITWISE OR      : Each bit-position will be 1 if one of the corresponding bit positions of the given integers is 1.
    ^   XOR             : Each bit-position will be 1 if the corresponding bit positions of the given integers are not equal.
    ~   BITWISE NEGATE  : Swaps each bit in an integer.

### PSEUDOCODE EXAMPLES

Bit shifting:

    x      = 0b1100     (0d12)
    x >> 5 = 0b         (0d2)      * equivalent to dividing by 2^5
    x << 5 = 0b         (0d384)    * equivalent to multiplying by 2^5

Bit operations:

    x     = 0b1100  (0d12)
    y     = 0b1010  (0d10)
    x & y = 0b1000  (0d8)
    x | y = 0b1110  (0d14)
    x ^ y = 0b0110  (0d6)
      ~ y = 1b1111111111111111111111111111111111111111111111111111111111110101 (-0d11)    *Assuming 64-bit system

[&lt; Previous](https://github.com/aaronryank/finer-points-of-c/tree/master/4) &bull; [Example](https://github.com/aaronryank/finer-points-of-c/blob/master/5/bit-operations.c) &bull; [Next >](https://github.com/aaronryank/finer-points-of-c/tree/master/6)
