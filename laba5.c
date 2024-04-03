#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    int n;
    printf("vvedite razmernost' matrizi n: ");
    scanf("%d", &n);

    double **matrix1 = (double **)malloc(n * sizeof(double *));
    double **matrix2 = (double **)malloc(n * sizeof(double *));
    double **result;

printf("Vvedite elementi pervoi matrizi:\n");
for (int i = 0; i < n; i++) {
    matrix1[i] = (double *)malloc(n * sizeof(double));
    for (int j = 0; j < n; j++) {
        scanf("%lf", &matrix1[i][j]);
    	}
	}

printf("Vvedite elementi vtoroi matrizi:\n");
for (int i = 0; i < n; i++) {
    matrix2[i] = (double *)malloc(n * sizeof(double));
    for (int j = 0; j < n; j++) {
        scanf("%lf", &matrix2[i][j]);
        }
    }
    
 // - pamiat'
    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
