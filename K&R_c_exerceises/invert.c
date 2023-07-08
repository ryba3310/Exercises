#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(int argc, char *argv[])
{
    int x = 11;
    printf("%d\n", invert(x, 3, 3));
    return 0;
}



unsigned invert(unsigned x, int p, int n)
{
    return ~(~0u << p) & x;
}
