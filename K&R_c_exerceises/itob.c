#include <stdio.h>

char s[30];

int strlenn(char s[]);
void reverse(char s[]);
void itob(int n, int b, char s[]);

int main(int argc, char *argv[])
{
    int num = -256;
    itob(num, 16, s);
    printf("%s\n", s);
    return 0;
}

int strlenn(char s[]){
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}

void reverse(char s[]){
    int i, j, c;
    j = strlenn(s) - 1;
    for (i = 0; i < j; ++i) {
        c = s[i];
        s[i] = s[j];
        s[j--] = c;
    }
}


void itob(int n, int b, char s[])
{
    int i, sign;
    i = 0;
    if((sign = n) < 0)
        n = ~n;
    do{
        if((s[i] = n % b + '0') > '9')
            s[i] = s[i] - '0' + 'A' - 10;
        i++;
    } while((n /= b) > 0);
    if(sign < 0){
        s[i]++;
        s[i++] = '-';
    }
    s[i++] = 'x';
    s[i++] = (b % 10) + '0';
    if(b > 10)
        s[i++] = 1 + '0';
    reverse(s);
    s[i] = '\0';
}
