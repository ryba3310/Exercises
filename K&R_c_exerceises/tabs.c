#include <stdio.h>

#define TAB_SPACE 8

int main(int argc, char *argv[])
{
    int c, cursor;
    cursor = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            for (int i = 0; i < TAB_SPACE - cursor; ++i) {
                putchar('#');
            }
            cursor = 0;
        }
        else
        {
            putchar(c);
            cursor++;
        }
        if(cursor == 4)
            cursor = 0;
    }
    return 0;
}
