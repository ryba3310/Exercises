#include <stdio.h>

void strcatt(char *s, char *t);

int main(int argc, char *argv[])
{
    char s[100] = "asdf";
    char *t = "fdsa";
    strcatt(s, t);
    printf("%s\n", s);
    return 0;
}



void strcatt(char *s, char *t){
    while(*++s)
    while((*s++ = *t++));
    /* putchar('\n'); */
}
