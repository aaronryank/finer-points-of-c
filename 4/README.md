# THE FINER POINTS OF C :|: BASIC TYPES
### Corresponding C source: "basics.c"

There's one basic type in C, sort of like how there's a basic `Object` in Java. It's a pointer to void:

    void *basic;

You can assign anything to a void *.

You may need to explicitly cast it to the type it was assigned to, e.g.

    ((struct foo *) basic)->foo_member

Simple enough? `void *` could be anything. A function, `struct`, `int`, etc.

See "basics.c" for an example. Oh, and I'm proud of that big line I had to explain to myself. Just FYI.

[&lt; Previous](https://github.com/aaronryank/finer-points-of-c/tree/master/3) &bull; [Example](https://github.com/aaronryank/finer-points-of-c/blob/master/4/basics.c) &bull; [Next >](https://github.com/aaronryank/finer-points-of-c/tree/master/5)
