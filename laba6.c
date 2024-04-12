#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *list_input, *list_output;
    char line[100];
    char surname[30], name[30], secondname[30];
    int year;

    list_input = fopen("list_input.txt", "rt");
    if (list_input == NULL) {
        printf("oshibka otkrutia faila\n");
        return 1;
    }

    list_output = fopen("list_output.txt", "w");
    if (list_output == NULL) {
        printf("oshibka otkrutia faila\n");
        return 1;
    }

    while (fgets(line, sizeof(line), list_input)) {
        sscanf(line, "%s %s %s %d", surname, name, secondname, &year);
        if (year > 1980) {
            fprintf(list_output, "%s %s %s %d\n", surname, name, secondname, year);
        }
    }

    fclose(list_input);
    fclose(list_output);

    printf("programma vupolnena uspeshno\n");
    return 0;
}
