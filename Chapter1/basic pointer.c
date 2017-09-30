#include<stdio.h>
#include<stdlib.h>

void print1(int *, int[]);

int main (void)
{
	int *ptr;
	int rows[5] = {5, 4, 3, 2, 1};
	
	ptr = rows;
	
	print1(ptr, rows);
	
	return 0;
}

void print1(int *ptr, int rows[])
{
	int i;
	printf("Address Contents\n");
	
	for(i = 0; i < 5; i++){
		printf("%8u%5d\n", ptr+ i, *(ptr + i));
	}
	
	printf("\n");
}
