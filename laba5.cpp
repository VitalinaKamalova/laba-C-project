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

printf("??????? ???????? ?????? ???????:\n");
for (int i = 0; i < n; i++) {
    matrix1[i] = (double *)malloc(n * sizeof(double));
    for (int j = 0; j < n; j++) {
        scanf("%lf", &matrix1[i][j]);
    	}
	}

printf("??????? ???????? ?????? ???????:\n");
for (int i = 0; i < n; i++) {
    matrix2[i] = (double *)malloc(n * sizeof(double));
    for (int j = 0; j < n; j++) {
        scanf("%lf", &matrix2[i][j]);
        }
    }
}
