#include<stdio.h>
#include<stdlib.h>

#define COMPARE(x, y) (((x) < (y) ) ? -1: ((x) == (y))? 0:1)
#define MAX_SIZE 1001

void padd(int, int, int, int);

typedef struct{
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_SIZE];
int main (void)
{
	int startA = 0, finishA = 0;
	int startB = 0, finishB = 0;
	int count = 0;
		
	printf("輸入多項式A	(輸入完畢按CTRL+Z)\n");
	
	while(scanf("%f", &terms[count].coef) != EOF){		
		scanf("%d", &terms[count].expon);
		count++;
	}
	
	finishA = --count;
	startB = (finishA + 1);
	
	printf("輸入多項式B	(輸入完畢按CTRL+Z)\n");
	count = startB;
	
	while(scanf("%f", &terms[count].coef) != EOF){		
		scanf("%d", &terms[count].expon);
		count++;
	}
	
	finishB = --count;
		
	printf("輸出結果\n");
	printf("coef    expon\n");
	padd(startA, finishA, startB, finishB);
	
	return 0;
}

void padd(int startA, int finishA, int startB, int finishB)		//輸出結果 
{
	while((startA <= finishA) && (startB <= finishB))
	{
		switch(COMPARE(terms[startA].expon, terms[startB].expon))
		{
			case -1:					// terms[startB].expon較大 
				printf("%.2f	", terms[startB].coef);
				printf("%d\n", terms[startB].expon);
				startB++;
				break;
			case 0: 					//expon相同
				printf("%.2f	", terms[startA].coef + terms[startB].coef);
				printf("%d\n", terms[startA].expon);
				startA++;
				startB++;
				break;
			case 1:						// terms[startA].expon較大 
				printf("%.2f	", terms[startA].coef);
				printf("%d\n", terms[startA].expon);
				startA++;
				break; 
		}
	}
	
	for(; startA <= finishA; startA++)	//把A多項是沒印的印完 
	{
		printf("%.2f	", terms[startA].coef);
		printf("%d\n", terms[startA].expon);
	}
	
	for(; startB <= finishB; startB++)	//把B多項是沒印的印完 
	{
		printf("%.2f	", terms[startB].coef);
		printf("%d\n", terms[startB].expon);
	}
}
