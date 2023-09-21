#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int* pc=NULL;
	pc = (int*)malloc(1000*sizeof(int));
	for (int i = 0; i < 1000; i++)
	{
		pc[i] = rand();
	}
	int max = pc;
	for (int i = 1; i < 1000; i++)
	{
		if (max < pc[i])
			max = pc[i];
	}
	printf("max=%d", max);
}
