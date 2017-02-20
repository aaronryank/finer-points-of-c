#include <stdio.h>

#define SOME_TEXT "Hello"
#define MORE_TEXT "World"

int main(void)
{
    char *commaspace = ", ";

// compile with -DPASS1
#ifdef PASS1
    printf(SOME_TEXT ", " MORE_TEXT "!\n");
#endif

// compile with -DPASS2
#ifdef PASS2
    printf("Hello" ", " "World" "!\n");
#endif

// compile with -DPASS3
#ifdef PASS3
    printf(SOME_TEXT commaspace MORE_TEXT "!\n");
#endif
}
