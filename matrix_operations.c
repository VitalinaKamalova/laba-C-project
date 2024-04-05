#include <stdlib.h>

double** matrix_operation(double** matrix1, double** matrix2, int n, char operation) {
    int i,j;
	double** result = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (operation == '+') {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            } else if (operation == '-') {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            } else if (operation == '*') {
                result[i][j] = matrix1[i][j] * matrix2[i][j];
            }
        }
    }

    return result;
}



