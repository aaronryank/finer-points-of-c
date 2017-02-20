# THE FINER POINTS OF C :|: ARRAY INDEXES
### Corresponding C source: "indexes.c"

Many people like to write `array[index]` to save the trouble of using pointers.
It's certainly easier, but did you know that `array[index]` is equivalent to `*(array + index)`?
You may have wondered why something of this sort works:

    int foo(char *bar)
    {
        bar[0] = "f";
        bar[1] = "o";
        bar[2] = "o";
    }

What's really happening here is:

    int foo(char *bar)
    {
        *(bar+0) = "f";   // *(bar) if optimized by compiler
        *(bar+1) = "o";
        *(bar+2) = "o";
    }

Well, it's because you're not really using an index. An index is just a fancy/shortened way to operate on pointers.

The naming convention of `array[index]` isn't technically correct, as writing `index[array]` has the same functionality.

(think about it - `*(array+index)` is equivalent to `*(index+array)`).

Look at the example in "indexes.c" to get a grasp on exactly how pointers and arrays work.
