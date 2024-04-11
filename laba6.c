FILE *file_in = fopen("list.txt", "r");
if (file_in == NULL) {
    printf("Error opening file.\n");
    return 1;
}

