#include <stdio.h>

char s[30];

int strlenn(char s[]);
void reverse(char s[]);
void itoa(int n, char s[], int width);

int main(int argc, char *argv[])
{
    int num = -2147483648;
    itoa(num, s, 6);
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
    for (i = 0; i < j; ++i, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


void itoa(int n, char s[], int width){
    int i, sign;
    i = 0;
    unsigned int u = n;
    if((sign= n) < 0){
        n = ~n;
        u = n;
        u++;
    }
    do{
        s[i++] = u % 10 + '0';
    } while((u /= 10) > 0);
    if(sign < 0){
        s[i++] = '-';
    }
    for (i = i; i < width; ++i)
        s[i] = ' ';
    reverse(s);
    s[i] = '\0';
}
