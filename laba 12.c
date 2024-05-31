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

int main() {
    char input[20];
    printf("Enter the date in the format 'year.mm.dd', 'year.mm', 'year' or 'now': ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; 

    if (strcmp(input, "now") == 0) {
        time_t currentTime;
        struct tm* localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);
        printf("Today is %d.%02d.%02d, day of the week %d\n",
               localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday,
               getDayOfWeek(localTime->tm_year + 1900, localTime->tm_mon + 1, localTime->tm_mday));
    } else {
        int year, month, day;
        if (sscanf(input, "%d.%d.%d", &year, &month, &day) == 3) {
            printf("Day of the week %d.%02d.%02d - %d\n",
                   year, month, day, getDayOfWeek(year, month, day));
        } else if (sscanf(input, "%d.%d", &year, &month) == 2) {
            printMonthCalendar(year, month);
        } else if (sscanf(input, "%d", &year) == 1) {
            printYearCalendar(year);
        } else {
            printf("Invalid date format.\n");
        }
    }

    return 0;
}
