#include <stdio.h>

#define MAX 1000

char line[MAX];


int strlenn(char s[]);
int strindex(char source[], char pattern[]);
int get_line(char line[], int lim);


int main(int argc, char *argv[])
{
    char pattern[] = "";
    int found;
    while(get_line(line, MAX) > 0)
        found = strindex(line, pattern);
        printf("%d\n", found);
    return 0;
}


int get_line(char line[], int lim){
    int c, i;
    i = 0;

    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if(c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

int strlenn(char s[]){
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}

int strindex(char source[], char pattern[]){
    int i, j, k;
    for (i = strlenn(source) - 1; i >= 0; --i) {
        for (j = i, k = 0; pattern[k] != '\0' && source[i] == pattern[k]; j++, k++);
        if(k > 0 && pattern[k] != '\0')
            return i;
    }
    return -1;
}
