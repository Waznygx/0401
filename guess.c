#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("\t\t\t\t********************************\n");
//	printf("\t\t\t\t************ 1.play ************\n");
//	printf("\t\t\t\t************ 0.exit ************\n");
//	printf("\t\t\t\t********************************\n");
//}
//void game()
//{
//	int n = rand()%100 + 1;//1-100的随机数
//	int i = 0;
//	while (1)
//	{
//		printf("please input a num your guess:");
//		scanf("%d", &i); 
//		if (i < n)
//		{
//			printf("The guessed number is less than the actual number\n");
//		}
//		else if (i > n)
//		{
//			printf("The guessed number is greater than the actual number\n");
//		}
//		else
//		{
//			printf("Guessed right!\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("\nplease input your option:");
//		scanf("%d", &i);
//		switch (i)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			break;
//		default:
//			printf("option error!try again\n\n");
//			break;
//		}
//	} while (i);
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("*****************************************\n");
	printf("**************  1.play   ****************\n");
	printf("**************  0.exit   ****************\n");
	printf("*****************************************\n");
}
void game()
{
	int i = 0;
	int n = rand() % 100 + 1;
	while (1)
	{
		printf("please input a num:");
		scanf("%d", &i);
		if (i > n)
		{
			printf("猜大了\n");
		}
		else if (i < n)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}
int main()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("please option:");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("error");
			break;
		}
	} while (i);
	return 0;
}