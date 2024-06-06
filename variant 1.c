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
