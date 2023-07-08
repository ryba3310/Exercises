#include <stdio.h>


void reverse(char s[]);
void itoa(int n, char s[]);
unsigned long strlenn(char s[]);


int main(int argc, char *argv[])
{
    char toa[30];
    int num = -100;
    itoa(num, toa);
    printf("%s\n", toa);

    return 0;
}

void reverse(char s[])
{
    printf("%s\n", s);
    int i, j;
    char c;
    j = strlenn(s) - 1;
    for (i = 0; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

unsigned long strlenn(char s[])
{
    unsigned long i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}

void itoa(int n, char s[])
{
    printf("%d,\n", n);
    int i, sign;
    if((sign = n) < 0){
        n = ~n;
    }
    unsigned int u = n;
    u++;
    printf("%d,\n", u);
    i = 0;
    do{
        s[i++] = u % 10 + '0';
    } while((u /= 10) > 0);
    if(sign < 0)
        s[i++] = '-';
    reverse(s);
    s[i] ='\0';
}
