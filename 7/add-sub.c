#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
#define INT_MIN (1 << (sizeof(int)*CHAR_BIT-1))
#define INT_MAX (-(INT_MIN+1))
*/

int _add(int a,int b)
{
    int x = a ^ b;

    while (a & b)
    {
        b = ((a & b) << 1);
        a = x;
        x = a ^ b;
    }

    return x;
}

int _sub(int a, int b)
{
    return _add(a, _add(~b, 1));
}

int _mult(int a, int b)
{
    int i, res = a;

    for (i = 1; i < b; i = _add(i, 1))
        res = _add(res, a);

    return res;
}

int _div(int dividend, int divisor) {
    long long n = dividend, m = divisor;
    // determine sign of the quotient
    int sign = n < 0 ^ m < 0 ? _sub(0,1) : 1;
 
    if (n < 0) n = _sub(0, n);
    if (m < 0) m = _sub(0, m);

    // remove sign of operands
    //n = abs(n), m = abs(m);
 
    // q stores the quotient in computation
    long long q = 0;
 
    // test down from the highest bit
    // accumulate the tentative value for valid bits
    for (long long t = 0, i = 31; i >= 0; i = _sub(i, 1))
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;
 
    // assign back the sign
    if (sign < 0) q = _sub(0, q);
 
    // check for overflow and return
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
} 

int main(int argc, char *argv[])
{
    if (argc != 3)
        return 0;

    int i1 = atoi(argv[1]);
    int i2 = atoi(argv[2]);

    printf("%d + %d = %d\n", i1, i2, _add(i1, i2));
    printf("%d - %d = %d\n", i1, i2, _sub(i1, i2));
    printf("%d * %d = %d\n", i1, i2, _mult(i1, i2));
    printf("%d / %d = %d\n", i1, i2, _div(i1, i2));
}
