#include <stdio.h>


int main(int argc, char *argv[])
{
    char c;
    int w_length;
    int words[10];

    w_length = 0;

    for (int i = 0; i < 10; ++i) {
        words[i] = 0;
    }

    while((c = getchar()) != EOF)
    {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            w_length++;
        }
        if(c == '\n' || c == ' '){
            words[w_length - 1]++;
            w_length = 0;
        }
    }
    putchar('\n');
    puts("\nWords count by length");
    printf("____");
    for (int i = 1; i < 11; ++i) {
        printf("____%d___", i);
    }
    putchar('\n');
    int x = 1;
    for (int i = 0; i < 10; ++i) {
        printf("%3d |", x);
        for (int j = 0; j < 10; j++) {
            putchar('\t');
            if(words[j] > 0){
                putchar('#');
                words[j]--;
                i = 0;
            }
            else {
            putchar(' ');
            }
        }
        putchar('\n');
        x++;
    }
    return 0;
}
