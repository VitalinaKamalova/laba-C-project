#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void task1(){
    FILE *fp;
    fp = fopen("input.txt", "w");
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i<n*n*2; i++) fprintf(fp, "%d\n", rand()%100);
    fclose(fp);
}

void task2(){
    FILE *fp;
    fp = fopen("input.txt", "r");
    int n = 0;
    char s[10];
    while(fgets(s, 10, fp) != NULL) n++;
    fclose(fp);
    n = (int)(sqrt(n/2));
    fp = fopen("input.txt", "r");
    int arr1[n][n], arr2[n][n];
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++){
            fgets(s, 10, fp);
            arr1[i][j] = atoi(s);
        }
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++){
            fgets(s, 10, fp);
            arr2[i][j] = atoi(s);
        }
    fclose(fp);
    
    int min = arr1[0][0];
    int min_ind = 0;
    int odd_count= 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if(arr1[i][j] < min){
                min = arr1[i][j];
                min_ind = i*n + j;
            }
        if (arr1[i][j]%2 != 0) odd_count++;
        }
    }
    printf(" min element is %d with index %d\n", min, min_ind);
    printf("odd numbers: %d\n", odd_count);
    
    int identical_rows[n], identical_cols[n];
    for (int i = 0; i<n; i++){
        identical_rows[i] = 1;
        identical_cols[i] = 1;
        for (int j = 1; j<n; j++){
            if (arr1[i][j]!= arr1[i][0]) identical_rows[i] = 0;
            if (arr1[j][i]!= arr1[0][i]) identical_cols[i] = 0;
        }
    }

    printf("Матрица с идентичными значними строк и столбцов:\n");
    
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (identical_rows[i] || identical_cols[j]) printf("%d ", arr1[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
    
    fp = fopen("output.txt", "w");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++)
            fprintf(fp, "%d ", arr1[i][j]+arr2[i][j]);
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            int t = 0;
            for (int k = 0; k<n; k++)
                t+=arr1[i][k]*arr2[k][j];
            fprintf(fp, "%d ", t);
        }
        fprintf(fp, "\n");
    }
    
}

int main(){
    clock_t begin = clock();
    task1();
    task2();
    clock_t end = clock();
    printf("time: %f", ((double)(end - begin)) / CLOCKS_PER_SEC);
    return 0;
}
