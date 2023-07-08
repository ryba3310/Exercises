#include <stdio.h>


int main(int argc, char *argv[])
{
    unsigned int x = 0;
    int count 1;
    while(x &=(x-1))
        count++;
    printf("%d\n", count);
    return 0;
}
