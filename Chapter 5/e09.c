#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int day, month, year = 1988, yearday = 60;
    month_day(year, yearday, &month, &day);
    printf("The %dth day of %d was %d/%d\n", yearday, year, day, month);

    month = 3, day = 1;
    int dayOfYear = day_of_year(year, month, day);
    printf("%d/%d was the %dth day of %d\n", day, month, dayOfYear, year);
}

static int normal[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int *daytab[] = {normal, leap};

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(i=1; i<month; i++)
        day += *(daytab[leap] + i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(i=1; yearday>*(daytab[leap] + i); i++)
        yearday -= *(daytab[leap] + i);
    *pmonth = i;
    *pday = yearday;
}
