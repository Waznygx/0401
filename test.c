#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[10] = { 5,7,8,9,10,11,13,15,16,26};
	int num = 0;
	printf("please input the num you want to find:");
	scanf("%d", &num);
	int length = sizeof(arr) / sizeof(arr[0]);
	int mid = 0;
	int left = 0;
	int right = length - 1;
	//while (left <= right)
	//{
	//	mid = (left + right) / 2;
	//	if (arr[mid] < num)
	//	{
	//		left = mid + 1;
	//	}
	//	else if (arr[mid] > num)
	//	{
	//		right = mid - 1;
	//	}
	//	else
	//	{ 
	//		printf("already found!arr[%d]", mid); 
	//		break;
	//	}
	//}
	for (left = 0,right = length - 1; left <= right;)
	{
		mid = (left + right) / 2;
			if (arr[mid] < num)
			{
				left = mid + 1;
			}
			else if (arr[mid] > num)
			{
				right = mid - 1;
			}
			else
			{ 
				printf("already found!arr[%d]", mid); 
				break;
			}
	}
	if (left > right)
	{
		printf("not found!");
	}
	return 0;
}



//#include<string.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "today is sunday!";
//	char arr2[] = "****************";
//	int left = 0;
//	int right = 0;
//	/*while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(700);
//		left++;
//		right--;
//	}*/
//	for (left = 0, right = strlen(arr2) - 1; left <= right; left++, right--)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(700);
//	}
//}