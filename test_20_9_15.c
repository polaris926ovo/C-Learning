#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//用函数的递归实现字符串逆序
//void reverse(char* arr)
//{
//	char* a = arr;
//	char left = *arr;
//	int count = 0;
//	for (; *(a + 1) != '\0'; a++, count++);
//	if (count != 0)
//	{
//		*arr = *(arr + count);
//		*(arr + count) = '\0';
//		reverse(arr + 1);
//	}
//	*(arr + count) = left;
//	
//}
//
//
//void print(char* arr)
//{
//	printf("%c ", *arr);
//	if (*(arr + 1) != '\0')
//		print(arr + 1);
//}
//
//
//int main()
//{
//	char arr[] = "abcdefg";
//	print(arr);
//	printf("\n");
//	reverse(arr);
//	print(arr);
//	return 0;
//}




//写函数DigitSum()，输入一个非负数，返回组成它的数字之和
int DigitSum(unsigned int x)
{
	int sum = 0;
	if (x / 10 != 0)
	{
		sum += x % 10;
		return sum + DigitSum(x / 10);
	}
	return x;
}


int main()
{
	unsigned int x = 0;
	int sum = 0;
	scanf("%d", &x);
	sum = DigitSum(x);
	printf("%d\n", sum);
	return 0;
}
