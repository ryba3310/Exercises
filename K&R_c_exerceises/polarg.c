#include <stdio.h>
#include <ctype.h>

#define MAXVALS 100

static double stack[MAXVALS];
static int stack_ind = 0;
double atoii(char *source);

void push(double num);
double pop();

int main(int argc, char *argv[])
{
    if(argc < 2)
        printf("Invalid arguments\n");
    printf("%g\n", atoii("23.24"));
    double pop2;
    while(--argc > 0 && *argv++){
        printf("%s\n", *argv);
        if(isdigit(**argv)){
            push(atoii(*argv));
            continue;
        }
        switch (**argv){
            case '+':
                push(pop() + pop());
                break;
            case '-':
                pop2 = pop();
                push(pop() - pop2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                pop2 = pop();
                push(pop() / pop2);
                break;
            default:
                printf("Unknown command\n");
                break;
        }
    }
    return 0;
}

void push(double num){
    printf("pushing %g\n", num);
    if(stack_ind < MAXVALS)
        stack[stack_ind++] = num;
    else
        printf("Push: error\n");
}

double pop(void){
    if(stack_ind > 0)
        return stack[--stack_ind];
    else
        printf("Pop: stack empty\n");
    return -1;
}

double atoii(char *source){
    double i;
    for (i = 0.0; isdigit(*source); source++) {
        i = (10.0 * i) + (*source - '0');
    }
    if(*source == '.'){
        double j = 1.0;
        while(isdigit(*++source)){
            i += (j / 10) * (*source - '0');
            j /= 10;
        }
    }
    return i;
}
