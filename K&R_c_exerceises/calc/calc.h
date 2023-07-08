#include <ctype.h>
#include <stdlib.h>

#define NUMBER  '0'
#define VAR '$'
#define ASSIGNED 2


void assign_var(double value);

void push_var();

void swap();

double top();

void clear();

void expo();

void power();

void sine();

int getch(void);

void ungetch(int c);

int getop(char s[]);

void push(double f);

double pop(void);

