#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//打印n*n乘法口诀表
void print(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%2d*%2d=%3d ", i, j, i * j);
		}
		printf("\n");
	}
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	print(n);
	return 0;
}
