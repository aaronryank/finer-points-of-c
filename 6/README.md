# THE FINER POINTS OF C :|: AUTOMATIC STRING CONCATENATION
### Corresponding C source: "string-cat.c"

There's a small cheat you can do to "automatically concatenate" strings in C.

Note that this only works for literal strings (and `#define`'d ones), not variables.

To test each example, compile with:

    cc string-cat.c -DPASSx

Replacing x with 1, 2, or 3.

[&lt; Previous](https://github.com/aaronryank/finer-points-of-c/tree/master/5) &bull; [Example](https://github.com/aaronryank/finer-points-of-c/blob/master/6/string-cat.c) &bull; [Next >](https://github.com/aaronryank/finer-points-of-c/tree/master/7)
