#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void task1(){
    FILE *fp;
    fp = fopen("input.txt", "w");
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) fprintf(fp, "%d\n", rand()%100);
    fclose(fp);
}


void task2(){
    FILE *fp;
    fp = fopen("input.txt", "r");
    int n = 0;
    char s[10];
    while(fgets(s, 10, fp) != NULL) n++;
    fclose(fp);
    fp = fopen("input.txt", "r");
    int arr[n];
    for (int i = 0; i<n; i++){
        fgets(s, 10, fp);
        arr[i] = atoi(s);
    }
    fclose(fp);
    fp = fopen("output.txt", "w");
    for (int i = 0; i<n; i++){
        if((arr[i]%5==0)||(arr[i]%7==0)){
            if(arr[i]%5==0) fprintf(fp, "%s", "FIVE");
            if(arr[i]%7==0) fprintf(fp, "%s", "SEVEN");
            fprintf(fp, "\n");
        }else{
            fprintf(fp, "%d\n", arr[i]);
        }
    }
    fclose(fp);
}


void task3(){
    FILE *fp;
    fp = fopen("input.txt", "r");
    int n = 0;
    char s[10];
    while(fgets(s, 10, fp) != NULL) n++;
    fclose(fp);
    fp = fopen("input.txt", "r");
    int N = (int)sqrt(n*1.0);
    int arr[N][N]; 
    for(int i = 0; i< N; i++){
        for(int j = 0; j<N; j++){
            fgets(s, 10, fp);
            arr[i][j] = atoi(s);
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i< N; i++){
        int c1 = 0, c2 = 0;
        for(int j = 0; j<N; j++){
            c1 += arr[i][j];
            c2 += arr[j][i];
        }
        printf("%d   %d\n", c1, c2);
    }
}


int main(){
    clock_t begin = clock();
    task1();
    task2();
    task3();
    clock_t end = clock();
    printf("time: %f", ((double)(end - begin)) / CLOCKS_PER_SEC);
    return 0;
}

