#include <time.h>
#include <stdio.h>   
#include <stdarg.h>

int sum(int count, ...)  {
    va_list args;
    va_start(args, count);
    int total = 0, i;
    for ( i = 0; i < count; i++){
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int max(int count, ...){
    va_list args;
    va_start(args, count);
    int maximum = va_arg(args, int);
    int i;
    for ( i = 1; i < count; i++){
        int current = va_arg(args, int);
        if (current > maximum){
            maximum = current;
        }
    }
    va_end(args);
    return maximum;
}

int min(int count, ...){
    va_list args;
    va_start(args, count);
    int minimum = va_arg(args, int);
    int i;
    for ( i = 1; i < count; i++){
        int current = va_arg(args, int);
        if (current < minimum){
            minimum = current;
        }
    }
    va_end(args);
    return minimum;
}

float average(int count, ...){
    va_list args;
    va_start(args, count);
    int total = 0, i;
    for ( i = 0; i < count; i++){
        total += va_arg(args, int);
    }
    va_end(args);
    return(float)total / count;
}

int main(){
    printf("sum: %d\n", sum(10, 1,2,3,4,5,6,7,8,9,10));
    printf("max: %d\n", max(10, 1,2,3,4,5,6,7,8,9,10));
    printf("min: %d\n", min(10, 1,2,3,4,5,6,7,8,9,10));
    printf("averege: %.2f\n", average(10, 1,2,3,4,5,6,7,8,9,10));
    
    return 0;
}
