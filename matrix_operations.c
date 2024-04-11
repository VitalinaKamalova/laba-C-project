#include <stdlib.h>

double** allocation_memory(int n){
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }
    return result;
}
double** matrix_calculator(double** matrix1, double** matrix2, int n, char operation) {
    int i,j,k;
	double** result = allocation_memory( n);
    
    if (operation == '+') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }
    
    if (operation == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                 result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }
    
    if (operation == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = 0;
                for (k = 0; k<n; k++){
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }

    return result;
}



