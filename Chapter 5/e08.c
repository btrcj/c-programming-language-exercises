#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int day, month, year = 1988, yearday = 367;
    month_day(year, yearday, &month, &day);
    if(month == -1 && day == -1)
        printf("Error, please check the input data\n");
    else
        printf("The %dth day of %d was %d/%d\n", yearday, year, day, month);
    
    month = 13, day = 1;
    int dayOfYear = day_of_year(year, month, day);
    if(dayOfYear == -1)
        printf("Error, please check the input data\n");
    else
        printf("%d/%d was the %dth day of %d\n", day, month, dayOfYear, year);
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
        return -1;

    for(i=1; i<month; i++)
        day += daytab[leap][i];

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(yearday < 1 || yearday > (leap ? 366 : 365)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for(i=1; yearday>daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}
