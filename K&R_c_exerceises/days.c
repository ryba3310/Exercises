#include <stdio.h>


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *month, int *day);
char *months[2] = {NULL, NULL};

int main(int argc, char *argv[])
{
    char year[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    months[0] = year;
    months[1] = leap;
    printf("%d\n", day_of_year(2004, 2, 5));
    int month, day;
    month_day(2004, 34, &month, &day);
    printf("%d, %d\n", month, day);
    return 0;
}


int day_of_year(int year, int month, int day){
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 1 : 0;
    for (i = 1; i < month; ++i) {
        day += *(months[leap]+i);
    }
    return (day > 0 && day <= 365) ? day : -1;
}


void month_day(int year, int yearday, int *month, int *day){
    yearday = (yearday > 365) ? 365 : yearday;
    yearday = (yearday < 1) ? 1 : yearday;
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > *(months[leap]+i); ++i) {
        yearday -= months[leap][i];
    }
    *month = i;
    *day = yearday;
}
