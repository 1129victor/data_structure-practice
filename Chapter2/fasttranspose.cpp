#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101

typedef struct{
	int col;
	int row;
	int value;
	}terms;
	
void fastTranspose(terms a[], terms b[]);

int main (void)
{
	terms a[MAX_SIZE], b[MAX_SIZE];
	
	printf("Input sparse matrix A's row:\n");
	scanf("%d", &a[0].row);
	
	printf("Input sparse matrix A's column:\n");
	scanf("%d", &a[0].col);
	
	printf("Input sparse matrix A's unzero elements:\n");
	scanf("%d", &a[0].value);
	
	printf("Input sparse matrix(row col value)\n");
	int i = 0;
	for(i = 1; i <= a[0].value; i++){
		scanf("%d", &a[i].row);
		scanf("%d", &a[i].col);
		scanf("%d", &a[i].value);
	}
	
	fastTranspose(a, b);
	
	printf("Result:\n");
	for(i = 1; i <= b[0].value; i++){
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}
	
	return 0;
} 

void fastTranspose(terms a[], terms b[])
{
	int i = 0, j = 0;
	int rowterms[MAX_SIZE], startingpos[MAX_SIZE];
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0]. value;
	int numcols = a[0].col;
	
	if(b[0].value > 0){
		for(i = 0; i < numcols; i++){
			rowterms[i] = 0;
		}
		for(i = 1; i <= a[0].value; i++){
			rowterms[a[i].col]++;
		}
		startingpos[0] = 1;
		for(i = 1; i < numcols; i++){
			startingpos[i] = startingpos[i - 1] + rowterms[i - 1];
		}
		for(i = 1; i <= a[0].value; i++){
			j = startingpos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
	
	
}
