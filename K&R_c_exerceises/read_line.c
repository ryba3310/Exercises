#include <stdio.h>


int main(int argc, char *argv[])
{
    int c;
    char line[1000];
    for (int i = 0; i < 1000; ++i) {
        if((c = getchar()) > 0)
        {
            line[i] = c;
            if(c == EOF)
            {
                i++;
                line[i] = '\0';
                break;
            }
        }
    }
    printf("%s\n", line);
    return 0;
}
