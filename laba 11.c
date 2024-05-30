#include <time.h>
#include <stdio.h>   
#include <stdarg.h>

int sum(int num_args, ...)  
{
    va_list args;
    va_start(args, num_args);
    
    int total = 0;
    for (int i = 0; i < num_args; i++)
    {
        total += va_arg(args, int);
    }
    
    va_end(args);
    
    return total;
}


