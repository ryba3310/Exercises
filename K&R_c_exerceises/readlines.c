#include <stdio.h>

#define MAXLEN 1000
#define MAXLINES 100

int read_line(char *line);

int main(int argc, char *argv[])
{
    char lines[MAXLINES][MAXLEN];
    char line[MAXLEN];
    int i, j, len;
    for (i = 0; i < MAXLINES; ++i) {
        len = read_line(line);
        if(len <= 0)
            break;
        while((lines[i][j] = line[j]) != '\0')
                j++;
        j = 0;
    }
    while(i > j)
        printf("%s", lines[j++]);
    return 0;
}


int read_line(char *line){
    int c, i;
    i = 0;
    while((*line++ = c = getchar()) != EOF && c != '\n'){
        if(i > MAXLEN)
            break;
        i++;
    }
    return i;
}
