#include <stdio.h>


unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char *argv[])
{
    unsigned int x, y;
    x = 5;
    y = 11;
    printf("%d\n", setbits(x, 3, 3, y));
    return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x | ((~(~0 << n) & y) << (p - 1));
}
