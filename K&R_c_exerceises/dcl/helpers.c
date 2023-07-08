#include "helpers.h"

static char buf[100];
static int bufp;

int getch(){
    if(bufp <= 0)
        return getchar();
    else
        return buf[--bufp];
}

void ungetch(int c){
    if(bufp > 99){
        printf("no spae in getch() buf\n");
        return;
    }
    buf[bufp++] = c;
}

void dcl(){
    int ns;

    for(ns = 0; gettoken() == '*'; )
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out, " pointer to");
    }
}

// dirdcl: parse  a direct devlarator
void dirdcl(){
    int type;

    if(tokentype == '('){
        dcl();
        if(tokentype != ')'){
            printf("error: missing )\n");
        }
    } else if(tokentype == NAME) {
            strcpy(name, token);
    } else {
        printf("error: expected name or (dcl)\m");
    }
    while((type=gettoekn()) == PARENS || type == BRACKETS){
        if(type == PARENS){
            strcat(out, " function returning");
        } else {
        strcat(out, " array");
        strcat(out, token);
        strcat(out, " of");
        }
    }
}

int gettoken(void){
    int c, getch(void);
    void ungetch(int);

    char *p = token;

    while((c = getch()) == ' ' || c == '\t');

    if(c == '('){
        if((c = getch()) == ')'){
            strcat(token, "()");
            return tokentype = PARENs;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if(c == '['){
        for (*p++ = c; (*p++ = getch()) != ']'; );
        *p = '\0';
        return tokentype = BRACKETS;
    } else if(isalpha(c)) {
        for(*p++ = c; isalnum(c =getch()); ){
            *p++ = c;
        }
        ungetch(c);
        return tokentype = NAME;
    }
    return tokentype = c;
}






