#include <stdio.h>
#include <ctype.h>
#include "helpers.h"
#include <string.h>

#define LINELEN 1000
#define MAXLINES 1000

int read_line(char *source);
int read_lines(char *lines[]);
int atoii(char * soruce);

char *lines[MAXLINES];
char line[LINELEN];


int main(int argc, char *argv[])
{
    int tail = 10;
    if(argc == 2)
        tail = (atoii(argv[1]) > 0) ? atoii(argv[1]) : 10;
    else if(argc > 2){
        printf("Usage: ./tail <number>\n");
        return 1;
    }
    int num_lines = read_lines(lines);
    for (tail = (num_lines - tail > 0) ? num_lines - tail : 0; tail < num_lines; ++tail) {
        printf("line %d\t%s\n", tail, lines[tail]);
    }
    return 0;
}

int read_lines(char *lines[]){
    int line_len;
    int lines_read = 0;
    char *line_ptr;
    while((line_len = read_line(line)) > 0){
        if(lines_read >= MAXLINES || (line_ptr = allocc(line_len)) == NULL)
            return -1;
        else{
            line[line_len - 1] = '\0';
            strcpy(line_ptr, line);
            lines[lines_read++] = line_ptr;
        }
    }
    return lines_read;
}



int read_line(char *source){
    int i, c;
    for (i = 0; (*source = c = getchar()) != EOF && c != '\n'; source++, i++);
    if(c == '\n'){
        i++;
        source++;
    }
    *source = '\0';
    return i;
}


int atoii(char *source){
    int num = 0;
    while(*source){
        if(!isdigit(*source))
            return -1;
        num += (10 * num) + (*source - '0');
        source++;
    }
    return num;
}
