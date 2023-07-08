#include <stdio.h>

#define IS_LOWER(N) ((N) >= 'a' || (N) <= 'z')
#define IS_UPPER(N) ((N) >= 'A' || (N) <= 'Z')
#define ALPHA_COUNT 26


int main(int argc, char *argv[])
{
    int c;
    int letters_in[ALPHA_COUNT];
    for (int i = 0; i < ALPHA_COUNT; ++i) {
        letters_in[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if(IS_LOWER(c))
            letters_in[c - 'a']++;
        else if(IS_UPPER(c))
            letters_in[c - 'A']++;
    }

    for (int i = 0; i < ALPHA_COUNT; ++i) {
        printf(" %c", i + 'A');
        printf("\t%3d| ", letters_in[i]);
        for (int j = 0; j < letters_in[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    return 0;
}
