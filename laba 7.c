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
	
	for( i =0; i<n; i++){
		print("Enter the %d person's name, surname and date of birth: ", i+1);
		scanf("%s %s %d", p[n].name, p[n].surname, &p[n].year);
		strcpy(f[i].)
	}
	/*
	FILE *file;
	file = fopen("people.txt", "r");
	for (i=0; i<n; i++){
		fscanf(file, "%s %s %d", p[n].name, p[n].surname, $p[n].year);
	}
	fclose(file);*/
	
	
}
