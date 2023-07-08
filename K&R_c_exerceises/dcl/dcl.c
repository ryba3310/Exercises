#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"


int main(int argc, char *argv[])
{
    while(gettoken() != EOF){   // 1st token on line
        strcpy(datatype, token);    // is the datatype
        out[0] = '\0';
        dcl();
        if(tokentype != '\n'){
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}


// undcl with example input: x () * [] * () char

/* int main(int argc, char *argv[]) */
/* { */
/*     int type; */
/*     char temp[MAXTOKEN]; */

/*     while(gettoken() != EOF){ */
/*         strcpy(out, token); */
/*         while((type = gettoken()) != '\n'){ */
/*             if(type == PARENS || type == BRACKETS){ */
/*                 strcat(out, toekn); */
/*             } else if(type == '*'){ */
/*                 sprintf(temp, "(*%s)", out); */
/*                 strcpy(out, temp); */
/*             } else if(type == NAME){ */
/*                 sprintf(temp, "%s %s", token, out); */
/*                 strcpy(out, temp); */
/*             } else { */
/*                 printf("invalid input at %s\n", token); */
/*             } */
/*         } */
/*         printf("%s\n", out); */
/*     } */
/*     return 0; */
/* } */


