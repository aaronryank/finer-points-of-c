/* Copyright (C) 2008-2016 Ryan Klingler.
   An example illustrating how C indexes work. */

#include <stdio.h>

int main(void)
{
    if ( "what"[0] == *("what" + 0) )
        printf("Pass 1\n");

    if ( "what"[0] == *(0 + "what") )
        printf("Pass 2\n");

    if ( 0["what"] == *("what" + 0) )
        printf("Pass 3\n");

    if ( 0["what"] == *(0 + "what") )
        printf("Pass 4\n");

    if ( 0["what"] == 'w' )
        printf("Pass 5\n");

    if ( "what"[0] == 0["what"] )
        printf("Pass 6\n");

    if ( *("what" + 1) == *(1 + "what") )
        printf("Pass 7\n");

    return 0;
}
