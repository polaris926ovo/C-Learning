#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//冒泡排序法 bubble_sort(arr)
//从第一个元素开始两两比较，如若大于就交换位置
//一趟冒泡排序后最大的元素就确定再最后的位置了
//然后再进行下一趟的冒泡排序
//如果有n个元素则一共需要n-1趟

void bubble_sort(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int flag = 1;                //设置一个标志，为1说明数组已经有序
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;            //如果进入if，说明进行了交换，不能保证这趟冒泡排序后数组一定有序，将标志置0
			}                        //如果没进入if,则说明这趟冒牌排序未进行交换，数组有序，标志仍未1
		}
		if (1 == flag)               //如果数组有序，则跳出循环，减少不必要的动作
		{
			break;
		}
	}
	printf("进行了%d趟冒泡排序\n", i+1);
}

int main()
{
	int arr[] = { 5,4,1,2,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr, sz);            //调用函数时，传送的arr实际为数组首元素的地址
	                                 //只有 sizeof(arr) 和 &arr 表示整个数组
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
