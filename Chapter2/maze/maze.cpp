#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h> 

#define MAX_SIZE 101

typedef struct{
	short int vert;
	short int horiz;
}offset;
offset move[8];

typedef struct{
	short int row;
	short int col;
	short int dir;
}element;
element stack[MAX_SIZE];
//malloc(stack, sizeof(stack));
//int capacity = 1;
int top = -1;

int maze[MAX_SIZE][MAX_SIZE], mark[MAX_SIZE][MAX_SIZE];
int EXIT_ROW, EXIT_COL;

void path (void);
void push(element);
void stackfull(void);
element pop(void);
void stackEmpty(void); 

int main(void)
{	
	move[0].vert = -1;
	move[0].horiz = 0;
	move[1].vert = -1;
	move[1].horiz = 1;
	move[2].vert = 0;
	move[2].horiz = 1;
	move[3].vert = 1;
	move[3].horiz = 1;
	move[4].vert = 1;
	move[4].horiz = 0;
	move[5].vert = 1;
	move[5].horiz = -1;
	move[6].vert = 0;
	move[6].horiz = -1;
	move[7].vert = -1;
	move[7].horiz =  -1;
	
	FILE *file;
	
	char fpt[MAX_SIZE];
	char origin[MAX_SIZE];
	char *result;
	int i = 0, j = 0, k = 0;
	
	printf("Input the file name\n");
	scanf("%s", &fpt);
	if((file = fopen(fpt, "r")) == NULL){
		puts("File could not be found");
		exit(1);
	}else{
		fscanf(file, "%d %d", &EXIT_ROW, &EXIT_COL);/*開始讀檔*/
	
		for (i = 1;i <= EXIT_ROW; i++) {
			for (j = 1; j <= EXIT_COL; j++)
				fscanf(file, "%d", &maze[i][j]);
		}
		
		for(i = 0; i <= EXIT_COL + 1; i++){
			maze[0][i] = 1;
		}
		
		for(i = 1; i <= EXIT_COL + 1; i++){
			maze[EXIT_ROW + 1][i] = 1;
		}
		
		for(i = 0; i <= EXIT_ROW + 1; i++){
			maze[i][0] = 1;
		}
		
		for(i = 1; i <= EXIT_ROW + 1; i++){
			maze[i][EXIT_COL + 1] = 1;
		}
		
		
		path();
	}
	
	return 0;
}

void path(void)
{
	int i, j, row, col, nextrow, nextcol, dir, found = 0;
	element position;
	mark[1][1] = 1;
	top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
	
	while(top > -1 && !found){
		position = pop();
		row = position.row; col = position.col; dir = position.dir;
		while(dir < 8 && !found){
			nextrow = row + move[dir].vert;
			nextcol = col + move[dir].horiz;
			if(nextrow == EXIT_ROW && nextcol == EXIT_COL){
				found = 1;
			}else if(!maze[nextrow][nextcol] && !mark[nextrow][nextcol]){
				mark[nextrow][nextcol] = 1;
				position.row = row; position.col = col; 
				position.dir = ++dir;
				push(position);
				row = nextrow; col = nextcol; dir = 0;
			}else{
				++dir;
			}
		}
		
		
	}
	if(found){
		printf("The path is:\n");

		for(i = 0; i <= top; i++){
			maze[stack[i].row][stack[i].col] = 2;
		}
		maze[row][col] = 2;
		maze[EXIT_ROW][EXIT_COL] = 2;
			
		for(i = 1; i <= EXIT_ROW; i++){
			for(j = 1; j <= EXIT_COL; j++){
				if(maze[i][j] == 2){
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
					printf("0 ");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
				}else{
					printf("%d ", maze[i][j]);
				}	
			}
			printf("\n");
		}
	}else{
		printf("The maze does not have a path\n");
	}
}

void push(element item)
{
	if(top >= MAX_SIZE - 1){
		
		stackfull();
		
	}
	stack[++top] = item;
}

void stackfull()
{
	/*
	realloc(stack, 2 * capacity * sizeof(*stack));
	capacity * 2;
	*/
	fprintf(stderr, "堆疊已滿\n");
	exit(1);
	
}

element pop()
{
	if(top == -1){
		stackEmpty();
	}
	return stack[top--];
}

void stackEmpty()
{
	fprintf(stderr,"Error: stack empty\n");
    exit(1);
}
