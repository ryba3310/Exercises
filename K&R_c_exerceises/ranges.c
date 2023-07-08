#include <stdio.h>
#include <limits.h>


int main(int argc, char *argv[])
{
    short i = 0;
    unsigned char c = 0;
    float f = 0.1;
    while(i > -1)
    {
        i = i + 1;
        c = i;
        f = f / f + f;
        printf("%d, %d, %c, float %f\n", i, c, c, f);
    }
    printf("%d, %d, %c, float %f\n", i, c, c, f);
    return 0;
}
