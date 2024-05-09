#include <stdio.h>
#include <string.h>

struct humen{
  char name[30],surname[30], sex[30];
  int year, hight;
};

int main(){
  int n = 4;
  struct humen p[n], psorted[n], t;
  int i,j;
  
  for( i=0; i < n; i++){
    printf("Enter the %d person's name, surname, date of birth, sex and hihght: ", i+1);
    scanf("%s %s %d %s %d", p[i].name, p[i].surname, &p[i].year, p[i].sex, &p[i].hight);
  }
  /*
  FILE *file;
  file = fopen("people.txt", "r");
  for (i=0; i<n; i++){
    fscanf(file, "%s %s %d", p[n].name, p[n].surname, &p[n].year);
  }
  fclose(file);*/
  for ( i = 0; i < n; i++){
  	psorted[i] = p[i];
  }

  for ( i = 0; i < n-1; i++){
    for ( j = 0; j < n-i-1; j++) {
		if (psorted[j].year > psorted[j+1].year ) {
            t = psorted[j];
            psorted[j] = psorted[j+1];
            psorted[j+1] = t;
        }
    }
  }
  
  printf("\nSorted list of people: \n");
  for ( i=0; i<n; i++){
    printf("%s %s %d \n", psorted[i].name, psorted[i].surname, psorted[i].year);
  }
  
  return 0;  
}
