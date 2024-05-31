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

// Функция для вывода календаря за месяц
void printMonthCalendar(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekday = getDayOfWeek(year, month, 1);
    int daysInCurrentMonth = daysInMonth[month - 1];
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        daysInCurrentMonth = 29;
    }
    printf("     %d.%02d\n", year, month);
    printf("Su Mo Tu We Th Fr Sa\n");
	int i;
    for ( i = 0; i < weekday; i++) {
        printf("   ");
    }
	
    for ( i = 1; i <= daysInCurrentMonth; i++) {
        printf("%2d ", i);
        if ((i + weekday) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Функция для вывода календаря за год
void printYearCalendar(int year) {
	int month;
    for ( month = 1; month <= 12; month++) {
        printMonthCalendar(year, month);
        printf("\n");
    }
}
