#include <stdio.h>
#include <ctype.h>

#define BUF 100


int getint(int *pn);
int getch(void);
void ungetch(char c);

int main(int argc, char *argv[])
{
    int i;
    int nums[100];
    for (i = 0; i < 100 && getint(&nums[i]) != EOF; ++i)
        printf("number: %d\n", nums[i]);
    return 0;
}


int getint(int *pn){
    int c, i, sign;

    /* while(isspace(c = getch())); */
    while((c = getch()) == ' ' || c == '\t' || c == '\n');
    if(!isdigit(c) && c != '-' && c != '+' && c != EOF){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-'){
        if(!isdigit(c = getch()) && sign < 0){
            ungetch('-');
        }
        else if(!isdigit(c)){
            ungetch('+');
        }
    }
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}

int buf[BUF];
int bufp;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c){
    if(bufp < BUF)
        buf[bufp++] = c;
    else
        printf("ungetch: buffer full\n");
}
