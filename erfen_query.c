#include<stdio.h>
int main()
{
	int i = 20;//要查询的数字
	int arr[20] = { 20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,45,46,47,47,39 };//定义数组
	int length = sizeof(arr) / sizeof(arr[0]);//计算数组长度（“总数组大小/每个元素的大小=数组元素个数”）
	int mid = 0;//数组下标中位数
	int left = 0;//数组下标最小值
	int right = length - 1;//数组下标最大值：arr[3]={5,6,7},则arr[0]=5,arr[1]=6
	while (left <= right)//下标min与max没有混乱时条件成立
	{
		mid = (left + right) / 2;//定义下标中位数
		if (arr[mid] < i)
		{
			left = mid + 1;
		}
		else if (arr[mid] > i)
		{
			right = mid - 1;
		}
		else
		{
			printf("already found,arr[%d]", mid);
			break;//不加break会死循环输出上述语句
		}
	}
	if (left > right)//没有if语句的话，即使找到数字跳出while，会输出“already found”和“not found”
	{
		printf("not found!");
	}
	return 0;
}