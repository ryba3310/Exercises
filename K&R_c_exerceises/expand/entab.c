#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000
#define TABLEN 8

static char line[MAXLINE];
static int tabs[100] = {TABLEN};

int atoii(char *source);
int read_line(char *line);

int main(int argc, char *argv[])
{
    while(argc > 1){
        argc--;
        if(atoii(argv[argc]))
            tabs[argc - 1] = atoii(argv[argc]);
        else {
        printf("Usage: ./entab n, m, ...\n");
        return 1;
        }
    }
    for (int i = 0; tabs[i] != 0; ++i) {
        printf("%d\n", tabs[i]);
    }
    int cursor, spaces, tabstop;
    while(read_line(line) > 0){
        for (cursor = spaces = tabstop = 0; line[cursor]; cursor++) {
            if(isalpha(line[cursor]))
                putchar(line[cursor]);
            else if(line[cursor] == ' ')
                spaces++;
            else if(cursor % (tabs[tabstop] - 1) == 0){
                    if(spaces % tabs[tabstop] == 0)
                        putchar('\t');
                    else
                        while(spaces-- > 0)
                            putchar(' ');
                    tabstop++;
            }
        }
    }

    return 0;
}


int read_line(char *line){
    int i, c;

    while((*line++ = c = getchar()) != EOF && c != '\n')
        i++;
    if(c == '\n')
        *line = '\0';
    return i;
}

int atoii(char *source){
    int num = 0;
    while(*source){
        if(isdigit(*source)){
            num += (num * 10) + (*source - '0');
        } else{
            return 0;
        }
        source++;
    }
    return num;
}
