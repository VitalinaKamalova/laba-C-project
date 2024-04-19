#include <stdio.h>
#include <string.h>

struct humen{
	char name[30],surname[30];
	int year;
};

int main(){
	int n = 4;
	struct humen f[n], s[n], y;
	char name[30], surname[30];
	int year;
	
	for(int i =0; i<n; i++){
		print("Enter the %d person's name: ", i+1);
		scanf("%s", name)
		print("Enter the %d person's surname: ", i+1);
		scanf("%s", surname)
		print("Enter the %d person's year of birth: ", i+1);
		scanf("%d", year)
		
	}
}
