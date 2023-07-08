#include <stdio.h>
#include <math.h>
#include "calc.h"

#define BUFSIZE 100
#define MAXVAL  100
#define AZ  26

int sp = 0;
double val[MAXVAL];
double letter_vars[AZ];
char latest_var;

void push(double f){
    printf("pushed %g\n", f);
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack is full, can't push %g\n", f);
}


double pop(void){
    printf("poped %g\n", val[sp - 1]);
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: no value to pop\n");
        return 0.0;
    }
}

double top(){
    if(sp > 0)
        return val[sp - 1];
    else
        printf("There is no element on stack\n");
    return 0.0;
}

void expo(){
    if(sp > 0)
        val[sp-1] = exp(val[sp-1]);
}

void power(){
    if(sp > 1)
        push(pow(pop(), pop()));
}

void sine(){
    if(sp > 0)
        val[sp-1] = sin(val[sp-1]);
}

void swap(){
    if(sp > 1){
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
        printf("Swaped %g and %g\n", tmp, val[sp - 1]);
        top();
    } else
        printf("Not enough elemnts for swap\n");
}
void clear(){
    int i;
    for (i = 0; i < MAXVAL; ++i) {
        val[i] = 0;
    }
    sp = 0;
    printf("cleared stack\n");
    top();
}

int check_var(char var_name){
    int c;
    while((c = getch()) == ' ' || c == '\t');
    if(c == '=')
        return var_name;
    else if(letter_vars[var_name - 'A'] != 0.0) {
        printf("assigned\n");
        return ASSIGNED;
    }
    return 0;
}

void assign_var(double value){
    letter_vars[latest_var - 'A'] = value;
    printf("assign_value %g to %c\n", letter_vars[latest_var - 'A'], latest_var);
}


void push_var(){
    push(letter_vars[latest_var - 'A']);
    printf("push_var: %g of %c\n", letter_vars[latest_var - 'A'], latest_var);
}

int getop(char s[]){
    int i, c, var_name;
    i = var_name = 0;
    static char buffer[BUFSIZE];
    static int bufp;

    while((s[0] = c = getch()) == ' ' || c == '\t');
    printf("char read: %c\n", c);
    s[1] = '\0';
    /* if(c >= 'A' && c <= 'Z'){ */
    /*     latest_var = c; */
    /*     if((var_name = check_var(c)) == ASSIGNED){ */
    /*         printf("latest var %c", latest_var); */
    /*         return ASSIGNED; */
    /*     } else */
    /*         s[0] = c = getchar(); */
    /* } */
    if(c == '-'){
        if(!isdigit(c = getch())){
            buffer[bufp++] = c;
            c = s[0];
        }
        else{
            buffer[bufp++] = c;
        }
    }
    if(!isdigit(c) && c != '.')
        return c;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));
    if(c == '.')
        while(isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if(c != EOF)
        buffer[bufp++] = c;
    printf("%s\n", s);
    if(var_name)
        return VAR;
    return NUMBER;
}


char buff[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buff[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: buffer full\n");
    else
        buff[bufp++] = c;
}
