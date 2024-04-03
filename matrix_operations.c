#include <stdio.h>
#include "matrix_operations.h"

double **matrix_add(double **matrix1, double **matrix2, int size) {
	double **result = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        result[i] = (double *)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

double **matrix_min(double **matrix1, double **matrix2, int size) {
    double **result = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        result[i] = (double *)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

double **matrix_mult(double **matrix1, double **matrix2, int size) {
    double **result = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        result[i] = (double *)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size ; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

