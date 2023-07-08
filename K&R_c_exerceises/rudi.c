#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_LINE 1000

int read_line();
char check_rudiment();
void check_closure(char closure);

short in_rudiment = OUT;
int line[MAX_LINE];
char rudiments[] = {'[', '{', '<', '(', '\"', '\''};
    // Error value is starting place of unfinished rudiment
int i, closures, line_length, lines, rudiment_place, closure_place;

int main(int argc, char *argv[])
{
    char rudiment;
    lines = 0;

    while((line_length = read_line()) > 0)
    {
        lines++;
        closures = closure_place = 0;
        rudiment_place = line_length;
        while((rudiment = check_rudiment()) > 0)
        {
            if(in_rudiment)
            {
                if(rudiment == '\'' && line[i + 2] == '\'')
                {
                    in_rudiment = OUT;
                    closures--;
                }
                else if(rudiment == '\"')
                {
                    check_closure('\"');
                }
                else if(rudiment == '(')
                {
                    check_closure(')');
                }
                else
                {
                    for (i = 0; i < 3; ++i)
                    {
                        if(rudiment == rudiments[i])
                        {
                            check_closure(rudiment+2);
                        }
                    }
                }
            }
        }
        printf("MISSING %d CLOSURES at line %d\n", closures, lines);
    }
    return 0;
}

void check_closure(char closure)
{
    printf("checking for closure %c for rudiment at line %d at %d\n", closure, lines, rudiment_place);
    for (i = closure_place; i < rudiment_place; ++i)
    {
        if(line[i] == closure && line[i -1] != '\\')
        {
            closures--;
            closure_place = i + 1;
            printf("FOUND closure %c at line %d, at %d\n", closure, lines, closure_place);
            in_rudiment = OUT;
        }
    }
    return;
}

char check_rudiment()
{
    for (i = rudiment_place - 1; i > closure_place; --i) {
        for(int j = 0; j < 6; j++)
        {
            if(line[i] == rudiments[j])
            {
                closures++;
                rudiment_place = i;
                in_rudiment = IN;
                printf("FOUND RUDIMENT %c at line %d at %d\n", line[i], lines, rudiment_place);
                return rudiments[j];
            }
        }
    }
    return 0;
}

int read_line()
{
    int c, i;
    for (i = 0; i < MAX_LINE && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if(c == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return i;
}
