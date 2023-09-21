#define _CRT_SECURE_NO_WARNINGS
//use this command to prevent potential security risks such as buffer overflows or file-related issues
// that could caused by using 'fopen' and 'fgets'
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	char file[100];
	char buffer[1000];
	int line_cnt = 1;
	char* p='0';
	fp = fopen("sample.txt", "r");
	if (fp == NULL) exit(1);
	while (p != NULL)
	{
		p = fgets(buffer, 1000, fp);
		printf("%d %s", line_cnt, p);
		line_cnt++;
	} 
	fclose(fp);
	return 0;
}
