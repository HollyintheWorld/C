
#define _CRT_SECURE_NO_WARNINGS
#define MAX 3
#include <stdio.h>

typedef struct {
	int row;
	int col;
	int val;
} term;

void input2(term a[]); //Input 2D array of sparse matrix
void inputh(int x[][MAX]); //Input sparse matrix
void printh(int x[][MAX]); //print sparse matrix
void ChHTo2(int x[][MAX], term a[]); //sparse matrix to 2D array
void print2(term a[]); //print the two-dimensional array of sparse matrices
void Ch2ToH(term a[], int x[][MAX]); //sparse matrix += 2-dimensional array of sparse matrices. Sparse matrix must be initialized to 0. uses clearh
void clearh(int x[][MAX]); //empties the sparse matrix
void smAdd(term a[], term b[]); //add two two-dimensional arrays of sparse matrices and print

int main()
{
	term t_a[MAX* MAX] = { 0 }, t_b[MAX* MAX] = { 0 };
	int h_aid[MAX][MAX] = { 0 };
	
	inputh(h_aid); //input Matrix A 
	ChHTo2(h_aid, t_a);
	clearh(h_aid);

	inputh(h_aid); //input Matrix B
	ChHTo2(h_aid, t_b);
	clearh(h_aid);

	input2(t_a);
	input2(t_b);

	Ch2ToH(t_a, h_aid); //print Matrix A, B
	printh(h_aid);
	clearh(h_aid);
	Ch2ToH(t_b, h_aid);
	printh(h_aid);

	return 0;
}

void input2(term a[])
{
	printf("input the info of the sparse matrix (Number of rows, columns, and values)\n");
	scanf("%d %d %d", &a[0].row, &a[0].col, &a[0].val);
	printf("input the info of the sparse matrix (Number of rows, columns, and values\n");
	for (int i = 1; i < a[0].val + 1; i++)
	{
		scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
	}
}

void inputh(int x[][MAX]) 
{
	printf("input the matrix: \n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			scanf("%d", &x[i][j]);
	}
}

void printh(int x[][MAX]) 
{
	printf("Prtinting the matrix\n");
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void ChHTo2(int x[][MAX], term a[]) 
{
	int cnt = 0;
	int n = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (x[i][j] != 0)
			{

				if (a[i + 1].row == i)
				{
					n += 1;
					a[n].row = i;
					a[n].col = j;
					a[n].val = x[i][j];
					cnt++;
				}
				else
				{
					n += 1;
					a[n].row = i;
					a[n].col = j;
					a[n].val = x[i][j];
					cnt++;
				}
			}
		}
	}
	a[0].row = MAX;
	a[0].col = MAX;
	a[0].val = cnt;
}

void print2(term a[]) 
{
	printf("\n");
	for (int i = 1; i < a[0].val+1; i++)
	{
		printf("%d %d %d\n", a[i].row, a[i].col, a[i].val);

	}
	printf("\n");
}

void Ch2ToH(term a[], int x[][MAX]) 
{
	for (int i = 1; i <= a[0].val; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++)
			{
				if ((a[i].row == j) && (a[i].col == k))
					x[j][k] += a[i].val;
			}
		}
	}
}

void clearh(int x[][MAX]) 
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			x[i][j] = 0;
	}
}

void smAdd(term a[], term b[]) 
{
	int res[MAX][MAX] = { 0 };
	Ch2ToH(a, res);
	Ch2ToH(b, res);
	printh(res);
}
