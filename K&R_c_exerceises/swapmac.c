#include <stdio.h>

#define SWAP(t, x, y)    \
           \
        t temp = x;      \
        x = y;   \
        y = temp;


int main(int argc, char *argv[])
{
    char x = 'x';
    char y = 'y';
    SWAP(char, x, y);
    printf("%c, %c\n", x, y);
    return 0;
}
