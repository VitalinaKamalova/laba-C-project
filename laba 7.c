#include <stdio.h>
#include <string.h>

struct humen{
  char name[30],surname[30];
  int year;
};

int main(){
  int n = 4;
  struct humen p[n];
  struct humen psorted[n];
  int i,j;
  
  for( i=0; i < n; i++){
    printf("Enter the %d person's name, surname and date of birth: ", i+1);
    scanf("%s %s %d", p[i].name, p[i].surname, &p[i].year);
  }
  /*
  FILE *file;
  file = fopen("people.txt", "r");
  for (i=0; i<n; i++){
    fscanf(file, "%s %s %d", p[n].name, p[n].surname, $p[n].year);
  }
  fclose(file);*/
  
  printf("\nSorted list of people: \n");
  for ( i=0; i<n; i++){
    printf("%s %s %d \n", p[i].name, p[i].surname, p[i].year);
  }
  
  return 0;  
}
