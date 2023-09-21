#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int input;
	int* pc;
	printf("How many items are there? ");
	scanf("%d", &input);
	pc = (int*)malloc(input * sizeof(int));
	for (int i = 0; i < input; i++)
	{
		printf("Enter an entry (integer): ");
		scanf("%d", &pc[i]);
	}
	printf("The value(s) entered is(are)\n");
	for (int i = 0; i < input; i++)
	{
		printf("%d ", pc[i]);
	}
}
