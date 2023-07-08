#include <stdio.h>


#define LINE_LENGTH 20


int main(int argc, char *argv[])
{
    int c, cursor;
    cursor = 0;

    while((c = getchar()) != EOF)
    {
        putchar(c);
        if(c == '\t')
            cursor += 3;
        cursor++;
        if(cursor > LINE_LENGTH)
        {
            putchar('\n');
            cursor = 0;
        }
    }
    return 0;
}
