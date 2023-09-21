
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numbers(int num[6]);

int main(void) {
	int num[6];
	int tmp = 0;
	int cnt = 0;
	numbers(num);
	for (int k = 0; k < 6; k++)
	{
		printf("%d ", num[k]);
	}

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i <= 4; i++)
		{

			if (num[i] > num[i + 1])
			{
				tmp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = tmp;
			}
		}
	}
	for (int k = 0; k < 6; k++)
	{
		printf("%d ", num[k]);
	}
}


int numbers(int num[6]) {

	int cnt = 0;
	int nums[6];
	int tmp = 0;

	while (1)
	{

		srand((int)time(NULL));
		for (int l = 0; l < 6; l++)
		{
			nums[l] = (rand() % 45) + 1;
		}
		for (int q = 0; q < 6; q++)
		{
			for (int w = q + 1; w < 6; w++)
			{
				if (nums[q] != nums[w])
				{
					cnt++;
				}
			}
		}
		if (cnt == 15)
		{
			for (int k = 0; k < 6; k++)
			{
				num[k] = nums[k];
			}
			break;
		}
	}
}
