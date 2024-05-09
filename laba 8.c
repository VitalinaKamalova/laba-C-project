#include <stdio.h>
#include <string.h>

struct humen{
  char name[30],surname[30], sex[30];
  int year, height;
};

int main(){
  int n=0;
  int i,j;
  char s[1000];
  
  FILE *file;
  file = fopen("FILE.txt", "r");
  while(fgets(s,100,file)!=NULL){
      n++;
  }
  fclose(file);
  
  struct humen p[n], psorted[n], t;
  file = fopen("FILE.txt", "r");
  for (i=0; i<n; i++){
    fscanf(file, "%s %s %d %s %d", p[i].name, p[i].surname, &p[i].year, p[i].sex, &p[i].height);
  }
  fclose(file);
  
  for ( i = 0; i < n; i++){
  	psorted[i] = p[i];
  }

  int choice[3], num; 
  printf("Enter the number of criteria for sorting (1 to 3): "); 
  scanf("%d", &num); 
  if(num < 1 || num > 3) { 
  	printf("Invalid input. Exiting..."); 
  	return 1; 
  }

  for(i = 0; i < num; i++) { 
  printf("Enter criterion %d (1 for year, 2 for name, 3 for surname, 4 for sex, 5 for height): ", i+1); 
  scanf("%d", &choice[i]); 
  }
  
  for (i = 0; i < n - 1; i++) { 
  	for (j = 0; j < n - i - 1; j++) { 
	  int k; 
	  for(k = 0; k < num; k++) { 
	  	if (choice[k] == 1 && psorted[j].year > psorted[j + 1].year) { 
		  t = psorted[j]; psorted[j] = psorted[j + 1]; psorted[j + 1] = t; 
		} 
		else if (choice[k] == 2 && strcmp(psorted[j].name, psorted[j + 1].name) > 0) { 
		  t = psorted[j]; psorted[j] = psorted[j + 1]; psorted[j + 1] = t; 
		} 
		else if (choice[k] == 3 && strcmp(psorted[j].surname, psorted[j + 1].surname) > 0) { 
		  t = psorted[j]; psorted[j] = psorted[j + 1]; psorted[j + 1] = t; 
		} 
		else if (choice[k] == 4 && strcmp(psorted[j].sex, psorted[j + 1].sex) > 0) { 
		  t = psorted[j]; psorted[j] = psorted[j + 1]; psorted[j + 1] = t; 
		} 
		else if (choice[k] == 5 && psorted[j].height > psorted[j + 1].height) { 
		  t = psorted[j]; psorted[j] = psorted[j + 1]; psorted[j + 1] = t; 
		} 
	  }
    } 
  }

  file = fopen("Sorted_FILE.txt", "w"); 
  if(file == NULL) { 
  	printf("Error opening file.\n"); 
	return 1; 
  }

  printf("\nSorted list of people: \n"); 
  for (i = 0; i < n; i++) { 
  	printf("%s %s %d %s %d \n", psorted[i].name, psorted[i].surname, psorted[i].year, psorted[i].sex, psorted[i].height); 
	fprintf(file, "%s %s %d %s %d ", psorted[i].name, psorted[i].surname, psorted[i].year, psorted[i].sex, psorted[i].height); 
	}
  
  fclose(file);
  
  return 0;  
}
