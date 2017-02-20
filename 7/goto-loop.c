#include <stdio.h>

int main(void)
{
    int i = 1;

/* looky, a loop with no for/while! */
loop:
    if (i == 0)
        goto done;
    if (getchar() == 'q')
        i = 0;
    goto loop;
done:

    printf("done\n");
}
