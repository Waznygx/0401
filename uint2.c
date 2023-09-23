  #define _CRT_SECURE_NO_WARNINGS
////从大到小输出三个数
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int mid = 0;//中间变量，在数值交换中使用
//	printf("please input 3 num:");
//	scanf("%d%d%d", &a, &b, &c);
//	if (a < b)//让a存放最大值，b中间数，c最小值
//	{
//		mid = a;
//		a = b;
//		b = mid;
//	}
//	if (a < c)
//	{
//		mid = a;
//		a = c;
//		c = mid;
//	}
//	if (b < c)
//	{
//		mid = b;
//		b = c;
//		c = mid;
//	}
//	printf("%d>%d>%d", a, b, c);
//	return 0;
//}
// 
////打印1-100以内3倍数的数字
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for ( i = 1; i < 100; i++)
//	{
//		if (i%3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//给定两个数，求这两个数的最大公约数（辗转相除法）
//#include<stdio.h>
//int main()
//{
//	int a = 75;
//	int b = 30;
//	int m = 0;//取模放在m里
	//if (m == 0)
	//{
	//	printf("%d", b);
	//}
	//else
	//{
	//	for (int i = 0; i < a; i++)//可能会有35、25之类不能在一次之内求出最大公约数的数字。因此要进行循环
	//	{
	//		m = a % b;//不能省，否则第二次循环用的还是第一次循环的模
	//		a = b;//再用a%b进行计算
	//		b = m;
	//		if (a % b == 0)
	//		{
	//			printf("%d", b);
	//			break;
	//		}
	//	}
	//}
//	while (m = a % b)//a%b!=0继续，反之跳出循环
//	{
//		//不能省，否则第二次循环用的还是第一次循环的模
//		a = b;//再用a%b进行计算
//		b = m;
//	}
//	printf("%d", b);
//	return 0;
//}

////打印1000-2000年之间的闰年(公历年份是4的倍数，且不是100的倍数的;能被400整除的)
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for ( i = 1000; i <= 2000; i++)
//	{
//		/*if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) 
//		{
//			printf("%d ", i);
//			count++;
//		}*/
//		if (i%4==0&&i%100)
//		{
//			printf("%d ", i);
//			count++;
//		}
//		else if (i%400==0)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}

////打印100-200之间的素数
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n = 0;
//	int i = 0;
//	int count = 0;
//	for ( n = 100; n <= 200; n++)
//	{
//		for ( i = 2; i < n; i++)//用6=2*3=3*2可知i的范围在2到（6-1），因为6可以被自己和1整除
//		{
//			if (n%i == 0)
//			{
//				break;
//			}
//		}
//		if (i == n)
//		{
//			printf("%d ", n);
//			count++;
//		}
//		//for ( i = 2; i <= sqrt(n); i++)//在非素数中的数字里，n=i*？，16=2*8=4*4，36=2*18=4*9=6*6，因此i和？之中必有一个数字满足“<=n平方根”这个条件
//		//{
//		//	if (n % i == 0)
//		//	{
//		//		break;
//		//	}
//		//}
//		//if (i > sqrt(n))
//		//{
//		//	printf("%d ", n); //输出n
//		//	count++;
//		//}
//	}
//	printf("\n%d\n", count);
//	return 0;
//}

////1-100间出现多少个数字9
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for ( i = i; i <= 100; i++)
//	{
//		if(i/10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//		if (i % 10 == 9)
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount=%d", count);
//	return 0;
//}

////求1/1-1/2+1/3-1/4+1/5-...+1/99-1/100
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	float sum = 0;//若为int型，即使184行强制转换结果也不对
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*(1.0 / i);
//		flag = -flag;//使sum正负交替计算
//	}
//	printf("%f",sum);
//	return 0;
//}

////求10个整数中的最大值
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 41,25,13,24,51,63,67,28,59,65 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int max = arr[0];//重要！！！最大值不能默认为0，否则若数组全是负数，输出最大值=0
//	for ( i = 0; i < length; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];	
//		}
//	}
//	printf("%d", max);//若放在for里面则会输出几个不同的最大值
//	return 0;
//}

////在屏幕上输出9*9乘法表
//#include<stdio.h>
//int main()
//{
//	int i = 0;//行
//	int j = 0;//列
//	int mul = 0;//乘积
//	for ( i = 1; i <= 9; i++)//共九行
//	{
//		//第1行有1列，第2行有2列，第n行有n列
//		// 1*1=1
//		// 1*2=2 2*2=4
//		// 1*3=3 2*3=6 3*3=9
//		for (j = 1; j <= i; j++)
//		{
//			mul = i * j;
//			//不能在这里加换行符，否则输出一个式子为一行
//			//%2d右对齐，-2d左对齐
//			printf("%d*%d=%-2d ", i, j, mul);
//		}
//		printf("\n");//使得每个i(1,2...9)独立为一行
//	}
//	return 0;
//}

//编写一个带密码在整型有序数组中查找具体某个数，找到要求打印下标，否则显示找不到
#include<stdio.h>
int main()
{
	int arr[] = { 11,22,3,15,46,82,9,12,24,23,43,34,36,57,59,89 };
	int i = 0;
	int n = 0;
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("please input a num you want to search:");
	scanf("%d", &n);
	for ( i = 0; i < length; i++)
	{
		if (n == arr[i])
		{
			printf("arr[%d]", i);
			break;
		}
	}
	if (i == length)
	{
		printf("not found");
	}
	return 0;
}

//int main()
//{
//	int arr[] = { 1,2,3,6,7,8,9,11,14,16,19,20,24,26,27,49 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int mid = 0;
//	int left = 0;
//	int right = length - 1;
//	printf("please input a num you want to search:");
//	scanf("%d", &i);
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > i)
//		{
//			right = mid - 1;
//		}
//		else if(arr[mid] < i)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("already found!arr[%d]", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("not found!");
//	}
//	return 0;
//}

