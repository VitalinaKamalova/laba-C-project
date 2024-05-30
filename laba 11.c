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

int min(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    
    int minimum = va_arg(args, int);
    for (int i = 1; i < num_args; i++)
    {
        int current = va_arg(args, int);
        if (current < minimum)
        {
            minimum = current;
        }
    }
    
    va_end(args);
    
    return minimum;
}
