#include <stdio.h>

#define LINE_LEN 100

void escape(char line[], char converted[]);

int main(int argc, char *argv[])
{
    char line[] = "asdf\tasdf\n";
    printf("%s\n", line);
    char line2[LINE_LEN];
    escape(line, line2);
    printf("%s\n", line2);
    return 0;
}


void escape(char line[], char converted[])
{
    int i, j;
    for (i = j = 0; line[i] != '\0' ; ++i) {
        switch (line[i]) {
            case '\t':
                converted[++j] = '/';
                converted[++j] = 't';
                break;
            case '\n':
                converted[++j] = '/';
                converted[++j] = 'n';
                break;
            default:
                converted[++j] = line[i];
                break;
        }
    }
    printf("%s\n", converted);
}
