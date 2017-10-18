#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_SIZE 101
#define COMPARE(x, y) (x < y) ? -1 : (x > y) ? 1 : 0

typedef struct{
		int col;
		int row;
		int value;
	}term;

void mmult(term *a, term *b, term *d);
void fastTranspose(term *a, term *b);
void storesum(term *d, int *, int, int, int *);

int main (void)
{
	term a[MAX_SIZE], b[MAX_SIZE], d[MAX_SIZE];
	FILE *fpt;
	char file[MAX_SIZE];
	char origin[MAX_SIZE];
	char list[MAX_SIZE];
	int countarray = 1, countrow = 0, countcol = 0, countvalue = 0, listcount = 0;
	char *result;
	int close = 0, first = 0;

	printf("Input file name:\n");
	scanf("%s", file);
	
		
	if((fpt = fopen(file, "r")) == NULL){
		puts("File could not be opened");
	}else{
		while(fgets(origin, sizeof(origin), fpt))
		{
			result = strtok (origin," ");
			while (result != NULL){
		  		printf ("%s", result);
		  		if((close == 0) && (*result != 10) && (*result != 124)){
		  			if(*result != 48){
		  				a[countarray].row = countrow;
		  				a[countarray].col = countcol;
		  				a[countarray].value = *result - 48;
						countarray++;
					}
		  			
		  			countcol++;
				}else if((*result == 10)){
					countrow++;
					if(first == 0){
						a[0].col = countcol;
						first++;
					}
					countcol = 0;
				}else if((*result == 124)){
					a[0].row = countrow;
					a[0].value = countarray - 1;
					close = 1;
					countrow = 0;
					countcol = 0;
					countarray = 1;
				}else if((close == 1) && (*result != 10)){
					if(*result != 48){
						b[countarray].row = countrow - 1;
		  				b[countarray].col = countcol;
		  				b[countarray].value = *result - 48;
						countarray++;
					}
		  			countcol++;
				}
    			result = strtok (NULL, " ");
	    	}	
	    	b[0].row = countrow;
			b[0].col = countcol;
			b[0].value = countarray - 1;
		}
		
		int i = 0;
		/*
		for(i = 0; i <= a[0].value; i++){
			printf("%d ", a[i].row);
			printf("%d ", a[i].col);
			printf("%d\n", a[i].value);
		}
		for(i = 0; i <= b[0].value; i++){
			printf("%d ", b[i].row);
			printf("%d ", b[i].col);
			printf("%d\n", b[i].value);
		}
		*/
		mmult(a, b, d);
		
		printf("output mmult result\n");
		for(i = 1; i <= d[0].value; i++){
			printf("%d ", d[i].row);
			printf("%d ", d[i].col);
			printf("%d\n", d[i].value);
		}
		/*
		printf("%d ", d[0].row);
		printf("%d ", d[0].col);
		printf("%d\n", d[0].value);*/
		fclose(fpt);
	}
	
	return 0;
}

void mmult(term *a, term *b, term *d)
{
	int i, j, column, totalB = b[0].value, totalD = 0;
	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;
	int colsB = b[0].col;
	int rowbegins = 1, row = a[1].row, sum = 0;
	term newB[MAX_SIZE];
	
	if(colsA != b[0].row){
		fprintf(stderr, "Incompatible matrices\n");
		exit(EXIT_FAILURE);
	}
	
	fastTranspose(b, newB);
	/*
	int z = 0;
	for(z = 0; z <= b[0].value; z++){
			printf("%d ", b[z].row);
			printf("%d ", b[z].col);
			printf("%d\n", b[z].value);
	}
	printf("\n");
	for(z = 0; z <= newB[0].value; z++){
			printf("%d ", newB[z].row);
			printf("%d ", newB[z].col);
			printf("%d\n", newB[z].value);
	}	
	*/
	a[totalA + 1].row = rowsA;
	newB[totalB + 1].row = colsB;
	newB[totalB + 1].col = 0;
	
	for(i = 1; i <= totalA;){
		column = newB[1].row;
		for(j = 1; j <= totalB + 1;){
			if(a[i].row != row){
				storesum(d, &totalD, row, column, &sum);
				i = rowbegins;
				for(; newB[j].row == column; j++);
				column = newB[j].row;
			}else if(newB[j].row != column){
				storesum(d, &totalD, row, column, &sum);
				i = rowbegins;
				column = newB[j].row;
			}else{
				switch(COMPARE(a[i].col, newB[j].col)){
					case -1 :
						i++;
						break;
					case 0 :
						sum += (a[i++].value * newB[j++].value);
						break;
					case 1:
						j++;
						break;
				}
			}
		}
		for(; a[i].row == row; i++);
		rowbegins = i; row = a[i].row;
	}
	
	d[0].row = rowsA;
	d[0].col = colsB;
	d[0].value = totalD;
}

void fastTranspose(term *a, term *b)
{
	int rowTerms[MAX_SIZE], startingPos[MAX_SIZE];
	int i, j, numCols = a[0].col, numTerms = a[0].value;
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;
	
	if(numTerms > 0){
		for(i = 0; i < numCols; i++){
			rowTerms[i] = 0;
		}
		for(i = 1; i <= numTerms; i++){
			rowTerms[a[i].col]++;
		}
		startingPos[0] = 1;
		for(i = 1; i < numCols; i++){
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		}
		for(i = 1; i <= numTerms; i++){
			j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
		
	}
}

void storesum(term *d, int *totald, int row, int column, int *sum) 
{
    if (*sum){
        if (*totald < MAX_SIZE) {
            d[++*totald].row = row;
            d[*totald].col = column;
            d[*totald].value = *sum;
            *sum = 0;
        } else {
            fprintf(stderr, "Numbers of terms in productexceed %d\n", MAX_SIZE);
            exit(1);
        }
    }
}
