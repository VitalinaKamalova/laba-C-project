#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

double** creation_matrix( int n){
    double** m = (double**)malloc(n * sizeof(double*));
    printf("Vvedite elementi matrizi: \n");
    for (int i = 0; i < n; i++) {
        m[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &m[i][j]);
        }
    }
    return m;
}

void print_matrix(int n,double** m1, double** m2){
    char op;
    printf("Vvedite operaziu (+, -, *): ");
    scanf(" %c", &op);
    double** result = matrix_calculator(m1, m2, n, op);
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

    double** m1 = creation_matrix( n);
    double** m2 = creation_matrix( n);

    print_matrix(n,m1,m2);

    for (i = 0; i < n; i++) {
        free(m1[i]);
        free(m2[i]);
    }
    free(m1);
    free(m2);

    return 0;
}
