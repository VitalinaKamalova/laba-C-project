#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// функция для определения дня недели
int getDayOfWeek(int year, int month, int day) {
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    mktime(&date);
    return date.tm_wday;
}


