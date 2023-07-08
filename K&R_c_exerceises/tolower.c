#include <stdio.h>


void to_lower();
char text[] = "QWERasdfQWER";

int main(int argc, char *argv[])
{
    to_lower();
    printf("%s", text);
    return 0;
}


void to_lower()
{
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
         text[i] = (text[i] >= 'A' && text[i] <= 'Z') ? text[i] - 'A' + 'a' : text[i];
    }
}
