#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main() { 
char input[100]; 
char *token; 
double result = 0; 
double num; 
char op = '+';

 
printf("Enter mathematical expression: ");
fgets(input, sizeof(input), stdin);

token = strtok(input, " ");

while (token != NULL) {
    if (sscanf(token, "%lf", &num) == 1) {
        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        }
    } else {
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-')) {
            op = token[0];
        }
    }
    token = strtok(NULL, " ");
}

printf("Result: %.1f\n", result);

return 0;
}
