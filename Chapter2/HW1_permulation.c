#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_SIZE 100 
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void perm(char *, int, int);

int main (void)
{
	char openfile[MAX_SIZE];
	char list[MAX_SIZE];
	int n;
	FILE *cfptr;
	
	printf("Input file name:\n");
	while(scanf("%s", openfile) != EOF){
		
		if((cfptr = fopen(openfile, "r")) == NULL){
			puts("File could not be opened");
		}else{
			fscanf(cfptr, "%s", list);
			
			n = strlen(list);
			
			perm(list, 0, n - 1);
		}
		
		fclose(cfptr);
		printf("\n");
		printf("Input file name:\n");
	}	
	
	return 0;
} 

void perm(char *list, int i, int n)
{
	int j, temp;
	
	if(i == n){
		for(j = 0; j <= n; j++){
			printf("%c", list[j]);
		}
		printf(" ");
	}else{
		
		for(j = i; j <= n; j++){
			if((i == j) || (list[i] != list[j])){ 
				SWAP(list[i], list[j], temp);	
				perm(list, i + 1, n);
				SWAP(list[i], list[j], temp);
			} 
		}
	}
}
