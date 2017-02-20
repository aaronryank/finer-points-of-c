#include <stdio.h>
#include <stdlib.h>

struct foo {
    int i;
    char c;
};

struct foo *fooptr_init(int i, char c)
{
    struct foo *foo = malloc(sizeof(struct foo *));

    /* usually accessed like this */
    foo->i = i;

    /* can also be accessed like this */
    (*foo).c = c;

    return foo;
}

int main(void)
{
    struct foo *fooptr;
    fooptr = fooptr_init(1, 'a');

    printf("%d=%d, %c=%c\n", fooptr->i, (*fooptr).i, fooptr->c, (*fooptr).c);

    return 0;
}
