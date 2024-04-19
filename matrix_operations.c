#include <stdlib.h>

double** allocation_memory(int n){
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }
    return result;
}
double** matrix_calculator(double** m1, double** m2, int n, char op) {
    int i,j,k;
	double** result = allocation_memory( n);
    
    if (op == '+') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = m1[i][j] + m2[i][j];
            }
        }
    }
    
    if (op == '-') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                 result[i][j] = m1[i][j] - m2[i][j];
            }
        }
    }
    
    if (op == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = 0;
                for (k = 0; k<n; k++){
                    result[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
    }

    return result;
}



