#include <stdio.h>

#define MAX 1000

char line[MAX];
int line_len;

int read_line();
int htoi(char hex_string[]);

int main(int argc, char *argv[])
{
    int c;
    while(read_line() > 0)
    {
        printf("%d\n", htoi(line));
    }
    return 0;
}

int htoi(char hex_string[])
{
    int i, decimal;
    decimal = 0;
    for (i = 0; i < line_len - 1; ++i) {
        if(line[i] == '0' && (line[i+1] == 'x' || line[i+1] == 'X'))
        {
            i = i + 1;
            continue;
        }
        if(line[i] >= 'a' && line[i] <= 'f')
            line[i] = line[i] - 'a' + 'A';
        if(line[i] >= '0' && line[i] <= '9')
            decimal = decimal * 16 + line[i] - '0';
        if(line[i] >= 'A' && line[i] <= 'F')
            decimal = decimal * 16 + line[i] - 'A';
    }
    return decimal;
}

int read_line()
{
    int i, c;
    for (i = 0; i < MAX && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if(c == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    line_len = i;
    return i;
}
