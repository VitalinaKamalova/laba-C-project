#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

double** creation_matrix( int n){
    double** matrix1 = (double**)malloc(n * sizeof(double*));
    printf("Vvedite elementi matrizi: \n");
    for (int i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }
    return matrix1;
}

void print_matrix(int n,double** matrix1, double** matrix2){
    char operation;
    printf("Vvedite operaziu (+, -, *): ");
    scanf(" %c", &operation);
    double** result = matrix_calculator(matrix1, matrix2, n, operation);
    printf("rezultat operazii: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n,i,j;
    
    printf("vvedite razmernost' matrizi n: ");
    scanf("%d", &n);

    double** matrix1 = creation_matrix( n);
    double** matrix2 = creation_matrix( n);

    print_matrix(n,matrix1,matrix2);

    for (i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    return 0;
}
