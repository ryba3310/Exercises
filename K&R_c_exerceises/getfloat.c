#include <stdio.h>
#include <ctype.h>

#define BUF 100

int bufp;
int buf[BUF];

int getch(void);
void ungetch(char c);
int getfloat(double *pnum);


int main(int argc, char *argv[])
{
    int i;
    double arr[100];
    for (i = 0; i < 100 && getfloat(&arr[i]) != EOF; ++i)
        printf("number: %f\n", arr[i]);
    return 0;
}


int getfloat(double *pnum){
    int sign, c;
    double fraction;
    while(isspace(c = getch()));
    if(!isdigit(c) && c != '+' && c != '-' && c != '.' && c != EOF){
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '-')
        c = getch();
    for (*pnum = 0.0; isdigit(c) && c != '.'; c = getch()) {
        *pnum = 10.0 * *pnum + ((double)c - (double)'0');
    }
    if(c == '.')
        c = getch();
    for (fraction = 10.0; isdigit(c); c = getch()){
        *pnum += ((double)c - (double) '0') / fraction;
        fraction *= 10;
    }
    *pnum *= (double) sign;
    if(c != EOF)
        ungetch(c);
    return c;
}


int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(char c){
    if(bufp < BUF)
        buf[bufp++] = c;
    else
        printf("ungetch: buff full\n");
}
