#include <stdio.h>


int main(int argc, char *argv[])
{
    int num = 200;
    char s[100];

    itoa(num, s);
    printf("%s\n", s, 4);
    return 0;
}

void itoa(int num, char s[], int len){
    int i, sign;
    i = len - 1;
    if(num < 0){
        s[0] = '-';
        num = -num;
    }
    if(num / 10 > 0)
        itoa(num / 10, s, i - 1);
    s[i++] = num % 10 + '0';
    s[i] = '\0';
}
