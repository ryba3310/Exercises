#include <stdio.h>


int main(int argc, char *argv[])
{
    int c;
    while((c = getchar()) != 'b')
    {
        if(c == ' ')
            putchar('\n');
        else
            putchar(c);
    }
    return 0;
}
