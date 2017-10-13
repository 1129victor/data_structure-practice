#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 100
#define COMPARE(x, y) (x > y) ?1 : (x < y) ? -1 : 0

void padd(int, int, int, int, int *, int *);
void attach(float, int);

typedef struct {
	float coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

int main (void)
{
	int startA = 0, finishA = 0, startB = 0, finishB = 0;
	int var = 0, var2 = 0;
	int *startD = &var, *finishD = &var2;
	
	printf("Input first polynomial	(press CTRL+Z when input done)\n");
	
	while(scanf("%f", &terms[avail].coef) != EOF){		
		scanf("%d", &terms[avail].expon);
		avail++;
	}
	
	avail--;
	finishA = avail;
	startB = finishA + 1;
	
	printf("Input second polynomial	(press CTRL+Z when input done)\n");
	avail = startB;
	
	while(scanf("%f", &terms[avail].coef) != EOF){		
		scanf("%d", &terms[avail].expon);
		avail++;
	}
	
	finishB = avail - 1;

	padd(startA, finishA, startB, finishB, startD, finishD);
	printf("result:\n");
	
	for(int i = *startD; *startD <= *finishD; (*startD)++){
		printf("%.2f ", terms[*startD].coef);
		printf("%d\n", terms[*startD].expon);
	}

	return 0;
}

void padd (int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
	float coefficient;
	*startD = avail;
	while((startA <= finishA) && (startB <= finishB))
	{
		switch(COMPARE(terms[startA].expon, terms[startB].expon))
		{
			case -1:					// terms[startB].expon較大 
				attach(terms[startB].coef, terms[startB].expon);
				startB++;
				break;
			case 0: 					//expon相同
				coefficient = terms[startA].coef + terms[startB].coef;
				if(coefficient){
					attach(coefficient, terms[startA].expon);
				}
				startA++;
				startB++;
				break;
			case 1:						// terms[startA].expon較大 
				attach(terms[startA].coef, terms[startA].expon);
				startA++;
				break; 
		}
	}
	
	for(; startA <= finishA; startA++)	//把A多項是沒印的印完 
	{
		attach(terms[startA].coef, terms[startA].expon);
	}
	
	for(; startB <= finishB; startB++)	//把B多項是沒印的印完 
	{
		attach(terms[startB].coef, terms[startB].expon);
	}
	*finishD = avail - 1;
}

void attach(float coefficient, int exponent)
{
	if(avail >= MAX_TERMS){
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}
