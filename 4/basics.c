/* Copyright (C) 2008-2016 Ryan Klingler.
   Example of basic types in C. */

#include <stdio.h>
#include <stdlib.h>

struct foo {
    int i;
    char c;
};

struct foo *new_foo(int i, char c)
{
    struct foo *foo = malloc(sizeof(struct foo *));

    foo->i = i;
    foo->c = c;

    return foo;
}

int foo_sys(char *msg, int arg)
{
    return printf("I am al%cve! %s\n", arg, msg);
}

int main(void)
{
    void *basic_int;
    void *basic_char;
    void *basic_string;
    void *basic_struct;
    void *basic_function;

    basic_int      = 3;
    basic_char     = 'a';
    basic_string   = "Beware...";
    basic_struct   = new_foo(1, 'i');
    basic_function = foo_sys;

    /* example 1 - accessing simple (int, char) basic types */
    printf("basic_int = %d basic_char = %c\n", basic_int, basic_char);

    /* example 2 - explicitly casting basic types */
    basic_int  = (*(struct foo *) basic_struct).i;
    basic_char = (*(struct foo *) basic_struct).c;
    printf("basic_int = %d basic_char = %c\n", basic_int, basic_char);

    /* example 3 - explicitly casting basic function pointers */
    basic_int = ((int (*)(char *, int)) basic_function)(basic_string, basic_char);

    printf("basic_int = %d\n", basic_int, basic_char);

    free(basic_struct);
    return 0;
}
/*
    basic_int =                                                                     | Assign value to a basic integer
                ((int (*)(char *, int)) basic_function)                             | Explicitly cast basic_function to a function, accepting a 'char *' and 'int', returning an 'int'
                                                       (basic_string, basic_char);  | Pass basic_string "Beware..." and basic char 'i' to explicitly cast basic_function */
