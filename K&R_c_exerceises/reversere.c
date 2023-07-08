#include <stdio.h>
#include <string.h>

void reverse(char s[], int start, int len);

int main(int argc, char *argv[])
{
    char s[] = "asdf";
    reverse(s, 0, strlen(s));
    printf("%s\n", s);
    return 0;
}


void reverse(char s[], int start, int len){
    if(start >= len)
        return;
    char temp = s[start];
    s[start] = s[len - 1];
    s[len - 1] = temp;
    reverse(s, start + 1, len - 1);
}
