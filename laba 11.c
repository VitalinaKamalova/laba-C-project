#include <time.h>
#include <stdio.h>   
#include <stdarg.h>

int sum(int num_args, ...)  {
    va_list args;
    va_start(args, num_args);
    int total = 0;
    for (int i = 0; i < num_args; i++){
        total += va_arg(args, int);
    }
    va_end(args);
    return total;
}

int max(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    
    int maximum = va_arg(args, int);
    for (int i = 1; i < num_args; i++)
    {
        int current = va_arg(args, int);
        if (current > maximum)
        {
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
