#include <sdtdio.h>


int isdigit(char c);
int isletter(char c);
void expand(char shorthand[], char line[]);

int main(int argc, char *argv[])
{
    char shorthand[] = "a-z";
    char line[100];
    expand(shorthand, line);
    printf("%s", line);
    return 0;
}


void expand(char re[], char line[])
{
    int i, j;
    for (i = 0; shorthand[i] != '\0'; ++i) {
        if(isletter)
    }
}

int isdigit(char c){
    return c >= '0' && c <= '9' ? 1 : 0;
}

int isletter(char c){
    return c >= 'a' && c <= 'z' ? 1 : 0;
}
