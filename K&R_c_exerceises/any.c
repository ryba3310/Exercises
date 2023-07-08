#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    char s1[] = "string";
    char s2[] = "lkpi";

    printf("%d\n", any(s1, s2));
   return 0;
}



int any(char s1[], char s2[])
{
    int i, j;
    int c = 0;
    while(s2[c] != '\0')
    {
        for (i = j = 0; s1[i] != '\0'; ++i) {
            if(s1[i] == s2[c])
                return i;
        }
        c++;
    }
    return -1;
}
