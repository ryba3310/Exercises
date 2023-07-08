#include <stdio.h>


void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    char s1[] = "string";
    char s2[] = "gri";

    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int c, i, j;
    c = 0;
    while(s2[c] != '\0')
    {
        for (i = j = 0; s1[i] != '\0' ; ++i)
            if(s1[i] != s2[c])
                s1[j++] = s1[i];
        s1[j] = '\0';
        c++;
    }
}
