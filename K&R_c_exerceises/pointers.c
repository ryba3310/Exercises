#include <stdio.h>
#include <ctype.h>

#define LINE_SIZE 100
#define NUMBER 1

int getop(char *op);
int get_line(char *line);
int atoip(char *source);
char *itoap(int num);
void reversee(char *source);
int strindexp(char *source, char *target);
char line[LINE_SIZE];

int main(int argc, char *argv[])
{
    while(get_line(line)){
        printf("%d\n", getop(line));
        printf("%s\n", line);
    }
    return 0;
}

int getop(char *op){
    static int c;
    while((*op = c = getchar()) == ' ' || c == '\t');
    *++op = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    if(isdigit(c))
        while(isdigit(*op++ = c = getchar()));
    if(c == '.')
        while(isdigit(*op++ = c = getchar()));
    *op = '\0';
    return NUMBER;
}


int strindexp(char *source, char *target){
    int i, ind;
    i = ind = 0;
    char *begin = target;
    while(*source){
        if(*source++ == *target++){
            i++;
            ind = i;
                while(*source++ == *target++)
                    i++;
        }
        i++;
        target = begin;
    }
    return (ind > 0) ? ind : -1;
}

int atoip(char *source){
    int i, num, sign;
    num = 0;
    sign = (*source == '-') ? -1 : 1;
    if(sign == -1)
        source++;
    reversee(source);
    for (i = 1; isdigit(*source) ; source++, i *= 10) {
        num += i * ((*source) - '0');
    }
    return num * sign;
}

char *itoap(int num){
    int i;
    static char char_num[20];
    for (i = 0; num > 0; ++i) {
        char_num[i] = (num % 10) + '0';
        num /= 10;
    }
    char_num[i] = '\0';
    reversee(char_num);
    return char_num;
}


int get_line(char *line){
    int c, i;
    i = 0;
    while((*(line + i++) = c = getchar()) != '\n' && c != EOF && i < LINE_SIZE);
    *(line + i) = '\0';
    return i;
}

void reversee(char *source){
    char *start = source;
    while(isalnum(*++source));
    char tmp;
    while(start <= --source){
        tmp = *source;
        *source = *start;
        *start++ = tmp;
    }
}

