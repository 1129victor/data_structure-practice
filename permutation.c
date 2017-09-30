#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void perm(char *, int, int);

int main (void)
{	
	int n;
	char list[100];
	
	printf("Input the number of char:\n");
	scanf("%d", &n);
	fflush(stdin);
	for(int i = 0; i < n; i++){
		scanf("%c", &list[i]);
	}
	
	perm(list, 0, n - 1);	
	
	system("pause");
}

void perm(char *list, int i, int n)
{
	int j, temp;
	
	if(i == n){
		for(j = 0; j <= n; j++){
			printf("%c", list[j]);
		}
		printf("\n");
	}else{
		for(j = i; j <= n; j++){
			SWAP(list[i], list[j], temp);
			perm(list, i + 1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}
