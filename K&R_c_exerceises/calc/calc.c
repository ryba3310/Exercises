#include <stdio.h>
#include "calc.h"

#define MAXOP   100


int main(int argc, char *argv[])
{
    int i, type;
    double op2;
    char s[MAXOP];


    while((type = getop(s)) != EOF){
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case VAR:
                 assign_var(atof(s));
                 break;
            case ASSIGNED:
                push_var();
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 == 0.0)
                    printf("error: zero divisor\n");
                else
                    push(pop() / op2);
                break;
            case '%':
                op2 = pop();
                if(op2 == 0.0)
                    printf("error: zero divisor\n");
                else
                    push((int)pop() % (int)op2);
                break;
            case 'e':
                expo();
                break;
            case 'p':
                power();
                break;
            case 's':
                sine();
                break;
            case 't':
                printf("Top elemnt of the stack: %g\n", top());
                break;
            case 'd':
                swap();
                break;
            case 'c':
                clear();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown comand %s\n", s);
                break;
        }
    }
    return 0;
}





