#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 101

typedef struct {
	int col;
	int row;
	int value; 
}term;
term a[MAX_TERMS], b[MAX_TERMS];

void transpose(term *a, term *b);

int main (void)
{	
	printf("Input A's row\n");
	scanf("%d", &a[0].row);
	
	printf("Input A's col\n");
	scanf("%d", &a[0].col);
	
	printf("How many elements in A array\n");
	scanf("%d", &a[0].value);
	
	printf("輸入矩陣\n"); 
	for(int i = 1; i <= a[0].value; i++){
		scanf("%d", &a[i].row);
		scanf("%d", &a[i].col);
		scanf("%d", &a[i].value);
	}
	
	transpose(a, b);
	
	printf("轉置結果\n");
	for(int j = 1; j <= b[0].value; j++){
		printf("%d ", b[j].row);
		printf("%d ", b[j].col);
		printf("%d\n", b[j].value);
	}
	
	return 0;
} 

void transpose(term *a, term *b)
{
	int n, i, j, currentb;
	
	n = a[0].value;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = n;
	
	if(n > 0){
		currentb = 1;
		for(i = 0; i < a[0].col; i++){
			for(j = 1; j <= n; j++){
				if(a[j].col == i){
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;
				}
			}
		}
	}
}
