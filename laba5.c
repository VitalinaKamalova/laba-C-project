#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    int n,i,j;
    char operation;
    printf("vvedite razmernost' matrizi n: ");
    scanf("%d", &n);

    double** matrix1 = (double**)malloc(n * sizeof(double*));
    double** matrix2 = (double**)malloc(n * sizeof(double*));

    printf("Vvedite elementi pervoi matrizi: ");
    for (i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Vvedite elementi vtoroi matrizi: ");
    for (i = 0; i < n; i++) {
        matrix2[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    printf("Vvedite operaziu (+, -, *): ");
    scanf(" %c", &operation);

    double** result = matrix_calculator(matrix1, matrix2, n, operation);

    printf("rezultat operazii: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.0f ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
