#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//汉诺塔问题  Hanoi
//设计一个函数，算出移动n层汉诺塔需要几次  Hanoi(n)

//    A      B      C           A      B      C   
//   (n)    (0)    (0)         (0)    (0)    (n)        
//把n层汉诺塔从A移动到C，可以简化为把前n-1层移动到B，再把最后一块移动到C，最后把前n-1层汉诺塔从B移动到C
//    A    B    C           A    B    C           A    B    C           A    B    C
//   (n)  (0)  (0)         (1) (n-1) (0)         (0) (n-1) (1)         (0)  (0)  (n)
//可以得出   Hanoi(n) = 1 + 2 * Hanoi(n-1)
//很明显有   Hanoi(1) = 1

////递归算法
//int Hanoi(int n)
//{
//	if (n != 1)
//		return 1 + 2 * Hanoi(n - 1);
//	return 1;
//}
//
//int main()
//{
//	int n = 0;
//	int num = 0;
//	printf("汉诺塔层数为:>");
//	scanf("%d", &n);
//	num = Hanoi(n);
//	printf("需要移动%d次\n",num);
//	return 0;
//}

//青蛙跳台阶问题 jump
//青蛙每次跳1个或者2个台阶，求跳到第n个台阶共有多少种跳法 jump(n)

//青蛙跳到第n个台阶，最后一步有两种跳法，跳1个或者跳两个
//所以总共的跳法数 jump(n) = jump(n-1) + jump(n-2)
//并且明显有  jump(1) = 1 , jump(2) = 2

//递归算法
int jump1(int n)
{
	if (1 == n)
		return 1;
	else if (2 == n)
		return 2;
	else
		return jump1(n - 1) + jump1(n - 2);
}
//n较大时响应速度非常慢

//循环算法
int jump2(int n)
{
	int a = 1;
	int b = 2;
	int ret = 3;
	int i = 0;
	if (1 == n)
		return a;
	if (2 == n)
		return b;
	for (i = 3; i <= n; i++)
	{
		ret = a + b;
		a = b;
		b = ret;
	}
	return ret;
}
//速度明显快于递归算法

int main()
{
	int n = 0;
	int num = 0;
	printf("台阶数为:>");
	scanf("%d", &n);
	num = jump2(n);
	printf("共有%d种跳法\n", num);
	num = jump1(n);
	printf("共有%d种跳法\n", num);
	return 0;
}
