#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
int main(void)
{
	char passw[20];
	int num = 0, C_char = 0, c_char = 0;
	while (1)
	{
		num = 0, C_char = 0, c_char = 0;
		printf("Create your password: ");
		gets_s(passw, 19);
		for (int i = 0; i < strlen(passw); i++)
		{
			if (48 <= passw[i] & passw[i] <= 57)
			{
				num = 1;
			}
			else if (65 <= passw[i] & passw[i] <= 90)
			{
				C_char = 1;
			}
			else if (97 <= passw[i] & passw[i] <= 122)
			{
				c_char = 1;
			}
		}
		if (num + C_char + c_char != 3)
			printf("Recreate the password by mixing numbers, lowercase letters, and uppercase letters\n");
		else
			break;
	}
	printf("Appropriate password entered.");
	return 0;
}
