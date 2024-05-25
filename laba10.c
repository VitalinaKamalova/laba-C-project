#include <stdio.h>

#define MAX(n, arr) ({int max = (arr)[0]; for (int i = 1; i < n; i++) if (max < (arr)[i]) max = (arr)[i]; max;})
#define AVEREGE(n, arr) ({double sum = 0.0; for (int i = 0; i < n; i++) sum += (arr)[i]; sum / n;})

int main() {
    int n;
    
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    
    int numbers[n];
    int i;
    printf("Enter numbers separeted by spaces: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    int maxNumber = MAX(n, numbers);
    printf("the maximum number is: %d\n", maxNumber);
    
    double averege = AVEREGE(n, numbers);
    printf("THe averege is: %.2f\n", averege);
    
    return 0;
}


