#include <stdio.h>
#define newline() putchar('\n');

/* ACTUAL LESS-KNOWN OPERATORS */

int main(void)
{
    int i = 10;
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

    return 0;
}

/* SILLY OPERATORS */

/* the 'runs to' operator */
void runs_to_operator()
{
    int i;

    while (i --> 0)
        printf("%d ", i);

    newline();
}


/* the 'slides to' operator */
void slides_to_operator()
{
    while (i --\
                \
                 \
                  \
                   \
                    > 0)
        printf("%d ", i);

    newline();
}

/* the 'double runs to' operator ('runs to' operator that decreases by 2 each time) */
void double_runs_to()
{
    while (i --> i + i <-- i)
        printf("%d ", i);

    newline();
}

#define ErrorHasOccured()
#define HandleError()

/* the 'I hate errors' operator (doesn't actually do anything, just an example */
void i_hate_errors()
{
    !ErrorHasOccured()??!??! HandleError();
}