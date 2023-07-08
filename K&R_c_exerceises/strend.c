#include <stdio.h>


int strend(char *s, char *t);

int main(int argc, char *argv[])
{
    char *s = "asdf";
    char *t = "fd";
    printf("%d\n", strend(s, t));
    return 0;
}



int strend(char *s, char *t){
    char *ss = s;
    char *tt = t;
    short flag = 1;
    while(*++ss);
    while(*++tt);
    while(*--ss != *s)
        if(tt >= t)
            if(*--tt != *ss)
                flag = 0;
    return flag;
    /* while(*--p) */
    /*     printf("%c,", *p); */
    /* putchar('\n'); */
    /* while(*--t) */
    /*     printf("%c,", *t); */
    /* putchar('\n'); */
    /* while(*--p){ */
    /*     if(*(--t) != *p) */
    /*         return 2; */
    /*     printf("%c, %c \n", *p, *t); */
    /* } */
    return 1;
}
