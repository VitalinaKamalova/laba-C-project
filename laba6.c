#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *list_input, *list_output;
    char line[100];
    char surname[30], name[30], secondname[30];
    int year;

    // Открываем файл для чтения
    list_input = fopen("list_input.txt", "r");
    if (list_input == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    // Открываем файл для записи
    list_output = fopen("list_output.txt", "w");
    if (list_output == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    // Считываем строки из файла
    while (fgets(line, sizeof(line), list_input)) {
        sscanf(line, "%s %s %s %d", surname, name, secondname, &year);
        if (year > 1980) {
            fprintf(list_output, "%s %s %s %d\n", surname, name, secondname, year);
        }
    }

    // Закрываем файлы
    fclose(list_input);
    fclose(list_output);

    printf("Программа успешно завершила выполнение\n");
    return 0;
}
