#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
////1.计算n的阶乘
//int main()
//{
//	int i = 0;//自加数
//	int n = 0;//输入值
//	int jc = 1;//阶乘最小值
//	printf("please input a num:");
//	scanf("%d", &n); 
//	for (i = 1; i <= n; i++)//例如：3！= 1*(1+1)*(1+1+1)=9，即n!=1*(1+1)*..*n
//	{
//		jc = jc * i;
//	}
//	printf("jc = %d\n", jc);
//	return 0;
//}

//2.计算1！+2！+3！+...+10!
//int main()
//{
//	int i = 0;//自加数
//	int n = 0;//1-10
//	int jc = 1;//阶乘
//	int sum = 0;//阶乘和
//	for (n = 1; n <= 4; n++)//赋初值=1，进入第二个for执行阶乘，再回到第一个for求和
//	{
//		jc = 1;//使每次从第二个for返回第一个for再往下执行时阶乘不会受影响
//		for ( i = 1; i <= n; i++)//执行求阶乘
//		{
//			jc = jc * i;
//		}
//		sum += jc;//若放在第二个for，会导致每一次自加的阶乘计算到求和里
//	}
//	printf("jc=%d,sum=%d", jc, sum);
//	return 0;
//}
int main()
{
	int n = 0;//1-10
	int jc = 1;//阶乘
	int sum = 0;//阶乘和
	for (n = 1; n <= 4; n++)
	{
		jc = jc * n;//4!=3!*4,即n!=(n-1)!*n
		
	}
	sum += jc;
	printf("sum=%d", sum);
	return 0;
}