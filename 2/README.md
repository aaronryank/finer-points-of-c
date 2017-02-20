# THE FINER POINTS OF C :|: STRUCT POINTERS
### Corresponding C source: "struct_pointers.c"

Members of pointers to structs are usually accessed as follows:

    foo->bar;

But, just like arrays in #1, this isn't what's actually happening. "->" is a shortcut to:

    (*foo).bar;

When explicitly casting a struct, you can do the same thing:

    ((struct foo *) ptr)->member;

Is equivalent to:

    (*(struct foo *) ptr).member;

See the corresponding source file "struct_pointers.c" for an example.

[&lt; Previous](https://github.com/aaronryank/finer-points-of-c/tree/master/1) &bull; [Example](https://github.com/aaronryank/finer-points-of-c/blob/master/2/struct_pointers.c) &bull; [Next >](https://github.com/aaronryank/finer-points-of-c/tree/master/3)
