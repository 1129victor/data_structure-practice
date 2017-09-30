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
		
	printf("��J�h����A	(��J������CTRL+Z)\n");
	
	while(scanf("%f", &terms[count].coef) != EOF){		
		scanf("%d", &terms[count].expon);
		count++;
	}
	
	finishA = --count;
	startB = (finishA + 1);
	
	printf("��J�h����B	(��J������CTRL+Z)\n");
	count = startB;
	
	while(scanf("%f", &terms[count].coef) != EOF){		
		scanf("%d", &terms[count].expon);
		count++;
	}
	
	finishB = --count;
		
	printf("��X���G\n");
	printf("coef    expon\n");
	padd(startA, finishA, startB, finishB);
	
	return 0;
}

void padd(int startA, int finishA, int startB, int finishB)		//��X���G 
{
	while((startA <= finishA) && (startB <= finishB))
	{
		switch(COMPARE(terms[startA].expon, terms[startB].expon))
		{
			case -1:					// terms[startB].expon���j 
				printf("%.2f	", terms[startB].coef);
				printf("%d\n", terms[startB].expon);
				startB++;
				break;
			case 0: 					//expon�ۦP
				printf("%.2f	", terms[startA].coef + terms[startB].coef);
				printf("%d\n", terms[startA].expon);
				startA++;
				startB++;
				break;
			case 1:						// terms[startA].expon���j 
				printf("%.2f	", terms[startA].coef);
				printf("%d\n", terms[startA].expon);
				startA++;
				break; 
		}
	}
	
	for(; startA <= finishA; startA++)	//��A�h���O�S�L���L�� 
	{
		printf("%.2f	", terms[startA].coef);
		printf("%d\n", terms[startA].expon);
	}
	
	for(; startB <= finishB; startB++)	//��B�h���O�S�L���L�� 
	{
		printf("%.2f	", terms[startB].coef);
		printf("%d\n", terms[startB].expon);
	}
}
