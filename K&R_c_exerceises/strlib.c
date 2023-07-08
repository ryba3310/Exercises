#include <stdio.h>

void strncpyy(char *s, char *t, int n);
void strncatt(char *dest, char *source, int n);
int strncmpp(char *dest, char *source, int n);

int main(int argc, char *argv[])
{
    char s[100] = "asdf";
    char *t = "sdf";
    printf("%d\n", strncmpp(s, t, 2));
    strncpyy(s, t, 3);
    printf("%s\n", s);
    strncatt(s, t, 5);
    printf("%s\n", s);
    return 0;
}


void strncpyy(char *s, char *t, int n){
    char *start;
    for (start = t + n; t <  start && *t != '\0'; t++) {
        printf("%p addr %p\n", t+n, t);
        *s++ = *t;
    }
    *s = '\0';
}



void strncatt(char *dest, char *source, int n){
    while(*++dest);
    for (; source < source + n && *source != '\0'; n--){
        *dest++ = *source++;
    }
    *dest = '\0';
}


int strncmpp(char *dest, char *source, int n){
    short flag;
    for (flag = 0; n > 0 && *dest != '\0' && *source != '\0' ; n--) {
        if(*dest++ != *source++)
            flag = (*dest++ > *source++) ? 1 : -1;
    }
    return flag;
}
