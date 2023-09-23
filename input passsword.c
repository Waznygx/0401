#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char p[20] = { 0 };
	int i = 0;
	for ( i = 0; i < 3; i++)
	{
		printf("please input password:");
		scanf("%s", &p);
		if (strcmp(p, "123") == 0)
		{
			printf("successfully login\n");
			break;
		}
		else
		{
			printf("error\n");
		}
	}
	if (i == 3)
	{
		printf("quit program!\n");
	}
	return 0;
}