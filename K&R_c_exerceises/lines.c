#include <stdio.h>

#define MAX_LEN 1000

int read_line(char line[], int max_len);
void reverse(char line[], int line_len);

int main(int argc, char *argv[])
{
    char line[MAX_LEN];
    int line_length;
    while((line_length = read_line(line, MAX_LEN)) > 0)
    {
            printf("%s\n%d\n", line, line_length);
            reverse(line, line_length);
            putchar('\n');
    }
    return 0;
}

void reverse(char line[], int line_len)
{
    for (int i = 0; i <= line_len; ++i) {
        putchar(line[line_len - i]);
    }
}


int read_line(char line[], int max_len)
{
    int c, i;

    for (i = 0; i < max_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if(c == ' ' || c == '\t')
            i--;
        else if(c == '\n'){
            line[i] = c;
            i++;
        }
        else
            line[i] = c;
    }
    line[i] = '\0';
    return i;
}
