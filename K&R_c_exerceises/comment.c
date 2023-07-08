#include <stdio.h>

#define MAX_LINE 1000
#define OUT 0
#define IN 1

char line[MAX_LINE];

int read_line();


int main(int argc, char *argv[])
{
    int line_len;
    int in_comment = OUT;
    int in_string = OUT;

    // some comment
    //
    //
    // 
    /* adfgadgdaf adfgdafg */
    while((line_len = read_line()) > 0)
    {
        for (int i = 0; i < line_len; ++i)
        {
            if(in_comment == OUT)
            {
                if(line[i] == '/' && line[i + 1] == '*')
                {
                    in_comment = IN;
                    line[i] = 0;
                    continue;
                }
                if(line[i] == '\'' && line[i + 2] == '\'')
                    i += 2;
                if(line[i] == '"')
                {
                    in_string = IN;
                    continue;
                }
                if(line[i] == '"' && in_string == IN)
                {
                    in_string = OUT;
                }
                if(line[i] == '/' && line[i + 1] == '/' && in_string == OUT)
                {
                    line[i] = '\n';
                    line[i + 1] = '\0';
                    break;
                }
            } // dsafgadfg
            else if(line[i] == '*' && line[i +1] == '/')
            {
                in_comment = OUT;
            }
            else
                line[i] = 0;
        }
        printf("%s", line);
    }
    /*dagdagdaf
     * dafgdgf
     *
     * adfgdafg
     * */
    return 0;
}


int read_line()
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAX_LINE && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n')
        {
            line[i] = c;
            i++;
        }
    line[i] = '\0';
    return i;
}


