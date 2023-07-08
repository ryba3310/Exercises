#include <stdio.h>

#define TAB_SPACE 3

int main(int argc, char *argv[])
{
    int c, blanks, cursor;
    cursor = blanks = 0;
    int arr[TAB_SPACE];
    while((c = getchar()) != EOF)
    {
        arr[cursor] = c;
        cursor++;
        if(c == ' ')
            blanks++;
        if(cursor == TAB_SPACE && blanks == TAB_SPACE)
        {
            putchar('\t');
            cursor = blanks = 0;
        }
        else if(cursor == TAB_SPACE)
        {
            for (int i = 0; i < TAB_SPACE; ++i) {
                putchar(arr[i]);
                arr[i] = 0;
            }
            cursor = blanks = 0;
        }
    }
    putchar('\n');
    return 0;
}
