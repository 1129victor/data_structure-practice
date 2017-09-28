#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x, y) ((x) < (y) ? -1 : ((x) == (y)) ? 0 : 1)

void sort(int[], int);
int binsearch(int [], int, int, int);

int main(void)
{
	int i, n, searchnum;
	int list[MAX_SIZE];
	
	printf("Enter the number of numbers to generate:\n");
	scanf("%d", &n);
	
	if(n < 1 || n > MAX_SIZE){
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	
	for(i = 0; i < n; i++){
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}
	
	sort(list, n);
	
	printf("\n Sorted array:\n");
	
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	printf("Input number to search\n");
	scanf("%d", &searchnum);
	
	printf("%d\n", binsearch(list, searchnum, 0, n));
	
	system("pause");
} 

void sort(int list[], int n)
{
	int i, j, min, temp;
	
	for(i = 0; i < n - 1; i++){
		min = i;
    	for(j = i + 1; j < n; j++){
    		if(list[j] < list[min]){
    			min = j;
    		}
		}
		SWAP(list[i], list[min], temp);
	}
}

int binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	if(left <= right){
		middle = (left + right) / 2;
		switch(COMPARE(list[middle], searchnum)){
			case -1 : return binsearch(list, searchnum, middle + 1, right);
					break;
			case 0 : return middle;
					break;
			case 1 : return binsearch(list, searchnum, left, middle - 1);
					break;
			 
		}
	}
	return -1;
}

