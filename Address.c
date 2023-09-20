
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct address
{
	char name[30];
	int number;
	char addr[10];
	int birth;
	int check;
};


void ShowList(struct address A[]);
void AddList(struct address A[]);
void SearchList(struct address A[]);
void DelList(struct address A[]);

int main() {
	struct address myadd[2] = { "" };
	for (int i = 0; i < 2; i++)
		myadd[i].check = 0;
	int inputNum;

	while (1)
	{
		printf("1. view list 2. add 3. search 4. delete 5. exit\n: ");
		scanf_s("%d", &inputNum);
		switch (inputNum) {
		case 1:
			ShowList(myadd);
			break;
		case 2:
			AddList(myadd);
			break;
		case 3:
			SearchList(myadd);
			break;
		case 4:
			DelList(myadd);
			break;
		case 5:
			printf("Exit the address.\n");
			return 0;
		}
	}
	return 0;
}

void ShowList(struct address A[])
{
	printf("\nAddress 1: name: %s \tnumber: %d \taddress: %s \tbday: %d\n", A[0].name, A[0].number, A[0].addr, A[0].birth);
	printf("Address 2: name: %s \tnumber: %d \taddress: %s \t bday: %d\n\n", A[1].name, A[1].number, A[1].addr, A[1].birth);
}

void AddList(struct address A[])
{
	int check = 0;
	for (int i = 0; i < 2; i++)
	{
		if (A[i].check == 0)
		{
			check = 1;
			printf("Input name, phone number, address, birthday.\n");
			scanf("%s %d %s %d", &A[i].name, &A[i].number, &A[i].addr, &A[i].birth);
			A[i].check = 1;
			printf("The contact is added to address number %d.\n\n", i + 1);
			break;
		}
	}
	if (check == 0)
		printf("There's no space in the address.\n\n");
}

void SearchList(struct address A[])
{
	char temp_name[10];
	int check_exit = 0;
	printf("Please enter the name: \n");
	scanf("%s", &temp_name);
	printf("Searching for %s.\n", temp_name);
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(A[i].name, temp_name) == 0)
		{
			check_exit = 1;
			//A[i].check++;
			printf("Address N.%d: name: %s\tnumber: %d\taddress: %s\tbday: %d\n\n", i + 1, A[i].name, A[i].number, A[i].addr, A[i].birth);
			break;
		}
	}
	if (check_exit == 0)
	{
		printf("There is no %s in the address\n\n", temp_name);
	}
}

void DelList(struct address A[])
{
	char temp_name[10];
	int check_exit = 0;
	printf("Please enter the name: \n");
	scanf("%s", temp_name);
	printf("Searching for %s.\n", temp_name);
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(A[i].name, temp_name) == 0)
		{
			check_exit = 1;
			strcpy(A[i].name, "");
			strcpy(A[i].addr, "");
			A[i].number = 0;
			A[i].birth = 0;
			A[i].check = 0;

			if (i != 1)
			{
				for (int j = i; j < 1; j++)
				{
					strcpy(A[i].name, A[i + 1].name);
					strcpy(A[i].addr, A[i + 1].addr);
					A[i].number = A[i + 1].number;
					A[i].birth = A[i + 1].birth;
					A[i].check = A[i + 1].check;

					strcpy(A[i + 1].name, "");
					strcpy(A[i + 1].addr, "");
					A[i + 1].number = 0;
					A[i + 1].birth = 0;
					A[i + 1].check = 0;
				}
			}
			break;
		}
	}
	if (check_exit == 0)
	{
		printf("There is no %s in the address\n\n", temp_name);
	}
	else
		printf("Deleted the address(es)\n\n");

}
