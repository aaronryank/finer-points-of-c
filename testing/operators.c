#include <stdio.h>

int main(void)
{
    int i = 10;

/* ACTUAL UNKNOWN-ISH OPERATORS */ printf("Real:\n");

    int j = 12;

    j <<= 2;
    printf("%d\n", j);

    j >>= 2;
    printf("%d\n", j);

    j  = 12;
    j &= 10;
    printf("%d\n", j);

    j  = 12;
    j |= 10;
    printf("%d\n", j);

    j  = 12;
    j ^= 10;
    printf("%d\n", j);


/* SILLY NONREALISTIC OPERATORS */ printf("Silly:\n");

    /* the 'runs to' operator */
    while (i --> 0)
        printf("%d ", i);

    putchar('\n'); i = 10;

    /* the 'slides to' operator */
    while (i -->\
                  \
                    \
                      \
                        \
                          \
                            0)
        printf("%d ", i);

    putchar('\n'); i = 10;

    /* the 'double runs to' operator ('runs to' operator, but decreases by 2 each time) */
    while (i --> i + i <-- i)
        printf("%d ", i);

    putchar('\n');
    return 0;
}
