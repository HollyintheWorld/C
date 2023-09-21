#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int* pi;
	pi = (int*)malloc(5 * sizeof(int));
	if (pi == NULL)
	{
		printf("Dynamic memory allocation error");
		exit(0);
	}
	for (int i = 0; i < 5; i++)
		pi[i] = i + 1;
	free(pi);
	return 0;
}
