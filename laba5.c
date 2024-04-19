#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *list_input, *list_output;
    char surname[30], name[30], secondname[30];
    char letter;
    int year;
    
    printf("Vvedite buckvu: ");
    scanf("%c", &letter);
    printf(" vu vveli: %c", letter);
    
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

    while (fscanf(list_input, "%s %s %s %d", surname, name, secondname, &year) != EOF) {
        if (strchr(surname, letter) != NULL) {
            printf( surname, letter);
            fprintf(list_output, "%s %s %s %d\n", surname, name, secondname, year);
        }
    }

    fclose(list_input);
    fclose(list_output);

    printf("programma vupolnena uspeshno\n");
    return 0;
}
