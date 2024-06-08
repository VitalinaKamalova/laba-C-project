int found = 0;
while (!found) {
    int arr1[n][n];
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            arr1[i][j] = rand()%100;

    int identical_rows[n], identical_cols[n];
    for (int i = 0; i<n; i++){
        identical_rows[i] = 1;
        identical_cols[i] = 1;
        for (int j = 1; j<n; j++){
            if (arr1[i][j]!= arr1[i][0]) identical_rows[i] = 0;
            if (arr1[j][i]!= arr1[0][i]) identical_cols[i] = 0;
        }
    }

    found = 1;
    for (int i = 0; i<n; i++){
        if (identical_rows[i] || identical_cols[i]) found = 0;
    }

    if (found) {
        printf("Матрица с идентичными значними строк и столбцов:\n");
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++)
                printf("%d ", arr1[i][j]);
            printf("\n");
        }
    }
}
