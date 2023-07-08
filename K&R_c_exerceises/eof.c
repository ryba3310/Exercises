#include <stdio.h>


int main() {
    int c;
    while((c = getchar()) != 'b') {
        if(c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        if(c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
    }
}
