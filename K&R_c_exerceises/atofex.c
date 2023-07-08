#include <stdio.h>
#include <ctype.h>

#define MAX 1000

char s[MAX];
int strlenn(char s[]);
int read_line(char s[], int max);
double atof(char s[]);

int main(int argc, char *argv[])
{
    char num[20] = "1.23e2";
    printf("%f\n", atof(num));
    return 0;
}

double atof(char s[]){
    int i, sign;
    double val, power;
    i = 0;
    for (i = 0; s[i] == ' '; ++i);
    double base = 10.0;

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '-' || s[i] == '+')
        i++;
    for (val = 0.0; isdigit(s[i]) || s[i] == 'e' || s[i] == 'E'; ++i) {
        if(s[i] == 'e' || s[i] == 'E'){
            i++;
            base = 1.0;
            if(s[i] == '-'){
                i++;
                for (int j = s[i] - '0'; j > 0; base *= 0.1, s[i]--, j--);
            }
            else
                for (int j = s[i] - '0'; j > 0; base *= 10.0, s[i]--, j--);
        }
        val = base * val + (s[i] - '0');
    }
    if(s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]) || s[i] == 'e' || s[i] == 'E'; i++) {
        if(s[i] == 'e' || s[i] == 'E'){
            i++;
            if(s[i] == '-'){
                i++;
                for (int j = s[i] - '0'; j > 0; base *= 0.1, s[i]--, j--);
            }
            else
                for (int j = s[i] - '0'; j > 0; base *= 10.0, s[i]--, j--);
        }
        val = base * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

int strlenn(char s[]){
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}

int read_line(char s[], int max){
    int i, c;
    i = 0;
    while(i < (max - 1) && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i++] = '\n';
    s[i++] = '\0';
    return i;
}

