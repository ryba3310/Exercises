#include <stdio.h>
#include <string.h>
#include "soul.h"
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES    1000
#define MAXLINE     1000


static int n_flag, r_flag, f_flag, field_flag, field;


int read_line(char *line){
    int i, c;
    for (i = 0; (*line = c = getchar()) != EOF && c != '\n'; ++i, line++);
    if(c == '\n'){
        i++;
        *line++ = c;
    }
    *line = '\0';
    return i;
}

int readlines(char *lines[]){
    char linee[MAXLINE];
    int line_len;
    int lines_read = 0;
    char *ptr;
    while((line_len = read_line(linee)) > 0){
        if(lines_read > MAXLINES || (ptr = make_soul(line_len)) == NULL)
            printf("%p ,eerr\n", ptr);
        else{
            linee[line_len - 1] = '\0';
            strcpy(ptr, linee);
            lines[lines_read++] = ptr;
        }
    }
            return lines_read;
}

int numcmp(const char *s1, const char *s2){
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    return 0;
}

void str_tolower(char *s1){
    while(*s1){
        *s1 = tolower(*s1);
        s1++;
    }
}

int strcmp_my(const char *s1, const char *s2){
    char tmp1[strlen(s1) + 1];
    char tmp2[strlen(s2) + 1];
    strcpy(tmp1, s1);
    strcpy(tmp2, s2);
    if(f_flag){
        str_tolower(tmp1);
        str_tolower(tmp2);
    }
    if(field > 0){
        tmp1[field] = '\0';
        tmp2[field] = '\0';
    }
    return strcmp(tmp1, tmp2);
}

void swap(void *arr[], int item, int item2){
    void *tmp = arr[item];
    arr[item] = arr[item2];
    arr[item2] = tmp;
}

void qsortt(void *things[], int begin, int end, int (*func)(void *source, void *target)){
    int i, last;
    if(begin >= end)
        return;
    swap(things, begin, (begin + end) / 2);
    last = begin;
    for (i = begin + 1; i <= end; ++i) {
        if(r_flag){ // for sorting in reverse order eg. descending
            if((*func)(things[i], things[begin]) > 0)
                swap(things, ++last, i);
        } else{
            if((*func)(things[i], things[begin]) < 0)
                swap(things, ++last, i);
        }
    }
    swap(things, begin, last);
    qsortt(things, begin, last - 1, func);
    qsortt(things, last + 1, end, func);
}

void printf_lines(int amount, char **line){
    for (int i = 0; i < amount; i++) {
        printf("%s\t%p\n", *(line+i), *(line+i));
    }
}



int main(int argc, char *argv[])
{
    char *ls[MAXLINES];
    while(--argc > 0){
            if(strcmp(*(argv+argc), "-n") == 0)
                n_flag = 1;
            if(strcmp(*(argv+argc), "-r") == 0)
                r_flag = 1;
            if(strcmp(*(argv+argc), "-f") == 0)
                f_flag = 1;
            if(strcmp(*(argc+argv), "-l") == 0){
                field_flag = 1;
                printf("argc : %s\n", *(argc+argv + 1));
                field = atoi(*(argc+argv + 1));
            }
        }
    printf("n: %d, r: %d f: %d field_flag: %d field: %d\n", n_flag, r_flag, f_flag, field_flag, field);

    int lines_read = readlines(ls);
    if(lines_read >= 0){
        qsortt((void **)ls, 0, lines_read - 1, (int (*)(void *, void *))(n_flag ? numcmp : strcmp_my));
        printf_lines(lines_read, ls);
    } else {
        printf("Input too big\n");
        return 1;
    }

    return 0;
}
