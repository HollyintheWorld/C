
#include <stdio.h>  
#include <stdlib.h> 
#define MAZE_SIZE 10
#define MAX_SIZE 100 


typedef struct mouse
{
	int x;
	int y;
}mouse;

typedef struct stack
{
	mouse data[MAX_SIZE];
	int top;
}stack;

char maze[MAZE_SIZE][MAZE_SIZE] =
{
{'1','1','1','1','1','1','1','1','1','1'},
{'0','0','0','0','1','0','0','0','0','1'},
{'1','0','0','0','1','0','0','1','0','1'},
{'1','0','1','1','1','0','0','1','0','1'},
{'1','0','0','0','1','0','0','1','0','1'},
{'1','0','1','0','1','0','0','1','0','1'},
{'1','0','1','0','1','0','0','1','0','1'},
{'1','0','1','0','1','0','0','1','0','1'},
{'1','0','1','0','0','0','0','1','0','0'},
{'1','1','1','1','1','1','1','1','1','1'}
};

void set(stack* p) {
	p->top = -1;
}

int CheckFull(stack* p) {
	return (p->top == MAX_SIZE - 1);
}

int CheckEmpty(stack* p) {
	return (p->top == -1);
}

void push(stack* p, mouse data) {
	if (CheckFull(p))
	{
		printf("no more space in stack\n");
		return;
	}
	else
	{
		p->top++;
		p->data[p->top].x = data.x;
		p->data[p->top].y = data.y;
	}
}

mouse peak(stack* p) {
	if (CheckEmpty(p))
	{
		printf("empty stack\n");
		exit(1);
	}
	return p->data[(p->top)];
}

mouse pop(stack* p) {
	if (CheckEmpty(p))
	{
		printf("empty stack\n");
		exit(1);
	}
	return p->data[(p->top)--];
}

void FindWay(stack* s, int x, int y) {
	if (x < 0 || y < 0 || x > MAZE_SIZE || y > MAZE_SIZE)
		return;
	if ((maze[x][y] != '1') && (maze[x][y] != '#')) {
		mouse tmp;
		tmp.x = x;
		tmp.y = y;
		push(s, tmp);
	}
}
void PrintMaze(char maze[MAZE_SIZE][MAZE_SIZE])
{
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++)
		{
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

int main() {
	stack s;
	mouse m;
	mouse p[100];//path(mark as 'x' if the path is used twice
	int i, j;
	int cnt = 0;
	set(&s);

	m.x = 1; //start point
	m.y = 0;

	printf("미로 \n");
	PrintMaze(maze);
	while ((m.y != 9) && (m.x + m.y != 17))//if it's not the destination
	{
		FindWay(&s, m.x, m.y - 1);//left
		FindWay(&s, m.x - 1, m.y);//up
		FindWay(&s, m.x + 1, m.y);//down
		FindWay(&s, m.x, m.y + 1);//right
		
		if (CheckEmpty(&s)!=0) {
			printf("There's no way.\n");
			maze[m.x][m.y] = '#';
			return 0;
		}
		else
		{
			maze[m.x][m.y] = '#';
			m = pop(&s); // change current location
			maze[m.x][m.y] = '#';
			
		}
	}
	printf("\n\npath:\n");
	PrintMaze(maze);
	return 0;
}
*/
