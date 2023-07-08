#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

enum words{
    CONTROL_LINE,
    UNDER_SCORE,
    COMMENT,
    STRING_CONST
    OTHER
};


struct key{
    char *word;
    int count;
} keytab[] = {
    "control lines" 0,
    "under_score_s", 0,
    "comment" 0,
    "string const", 0,
    "other_keyword", 0
};

static char buf[100];
static int bufp;

int getch(){
    if(bufp > 0)
        return buf[--bufp];
    return getchar();
}

void ungetch(int c){
    if(bufp < 100)
        buf[bufp++] = c;
    else
        printf("ungetch: buf full\n");
}

int getword(char *word, limit){
    int c;
    char *w = word;
    while(isspace(c = getch()));
    if(c != EOF)
        *w++ = c;
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for (; --limit > 0; w++) {
        if(!isalpha(*w = getch())){
        ungetch(*w);
        break;
        }
    }
    *w = '\0';
    return word[0];
}


int main(int argc, char *argv[])
{
    int n;
    char word[MAXLINE];
    while(getword(word, MAXLINE) != EOF)
        if(!isalpha(word[0]))
            if((n =))
    return 0;
}
