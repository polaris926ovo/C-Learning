#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define COUNT 10

#define ROWS ROW+2
#define COLS COL+2

void Initialize(char board[ROWS][COLS], int rows, int cols, char flag);
void SetBoom(char board[ROWS][COLS], int row, int col);
void Display(char board[ROWS][COLS], int row, int col);
void PlayerMove(char boom[ROWS][COLS], char player[ROWS][COLS], int row, int col);
void click(char boom[ROWS][COLS], char player[ROWS][COLS], int row, int col, int x, int y);
char NUM(char boom[ROWS][COLS], int x, int y);
int IsWin(char boom[ROWS][COLS], char player[ROWS][COLS], int row, int col);

#endif // !__GAME_H__

#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘，所有位置放入指定字符
void Initialize(char board[ROWS][COLS], int rows, int cols, char flag)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = flag;
		}
	}
}


//随机设置炸弹
void SetBoom(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


//显示棋盘
void Display(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("\n");
	for (j = 0; j <= col; j++)
	{
		printf(" %d ", j);
		printf(" ");
	}
	printf("\n\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d  ",i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j != col)
				printf("|");
		}
		printf("\n");
		if (i != row)
		{
			printf("    ");
			for (j = 1; j <= col; j++)
			{
				printf("---");
				if (j != col)
					printf("|");
			}
			printf("\n");
		}
	}
	printf("\n");
}


//玩家进行扫雷
void PlayerMove(char boom[ROWS][COLS], char player[ROWS][COLS], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		system("CLS");           //清屏
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (boom[x][y] == '1')
			{
				int i, j;
				for (i = 1; i <= row; i++)
				{
					for (j = 1; j <= col; j++)
					{
						if (boom[i][j] == '1')
							player[i][j] = 'X';
					}
				}
				Display(player, ROW, COL);
				printf("很遗憾,你被炸死了！\n");
				break;
			}
			else if (player[x][y] != '*')
			{
				printf("此处已被扫过，请重新输入\n");
			}
			else
			{
				click(boom, player, ROW, COL, x, y);//点击所选坐标
				if (IsWin(boom, player, ROW, COL) == 1)//判断是否获胜
				{
					int i, j;
					for (i = 1; i <= row; i++)
					{
						for (j = 1; j <= col; j++)
						{
							if (boom[i][j] == '1')
								player[i][j] = 'X';
						}
					}
					Display(player, ROW, COL);    //显示获胜后的棋盘
					printf("恭喜你，获胜了！\n");
					break;
				}
				Display(player, ROW, COL);    //显示点击后的棋盘
			}
		}
		else
		{
			Display(player, ROW, COL);
			printf("坐标非法，请重新输入\n");
		}
	}
}


//点击所选坐标
void click(char boom[ROWS][COLS], char player[ROWS][COLS], int row, int col, int x, int y)
{
	//判断一下点击位置是否在期盼中和是否被点击过，不在棋盘不点，被点击过也不再重复点击
	if (x > 0 && x < row + 1 && y>0 && y < col + 1 && player[x][y]=='*')
	{
		if (NUM(boom, x, y) != '0')          //如果点击位置周围8格有雷，则在点击位置显示雷的个数
		{
			player[x][y] = NUM(boom, x, y);
		}
		else                                //如果没有雷，点击位置替换为空格,并且点击周围8格
		{
			int i, j;
			player[x][y] = ' ';
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					click(boom, player, ROW, COL, i, j);
				    //Display(player, ROW, COL);
				}
			}
		}
	}
}


//计算点击位置周围8格雷的数量
char NUM(char boom[ROWS][COLS], int x, int y)
{
	char num = '0';
	int i, j;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			num = num + boom[i][j] - '0';
		}
	}
	return num;
}

//判断是否获胜
int IsWin(char boom[ROWS][COLS], char player[ROWS][COLS], int row, int col)
{
	int i, j;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (player[i][j]=='*')
				count++;
		}
	}
	if (count == COUNT)
		return 1;
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//菜单
void menu()
{
	printf("######################################\n");
	printf("######          1.play          ######\n");
	printf("######          0.exit          ######\n");
	printf("######################################\n");
}



void game()
{
	//创建炸弹棋盘
	char BoomBoard[ROWS][COLS];
	//创建玩家棋盘
	char PlayerBoard[ROWS][COLS];
	//初始化炸弹棋盘
	Initialize(BoomBoard, ROWS, COLS, '0');
  //初始化玩家棋盘
	Initialize(PlayerBoard, ROWS, COLS, '*');
	//设置炸弹
	SetBoom(BoomBoard, ROW, COL);
	//显示棋盘
	//Display(BoomBoard, ROW, COL);
	system("CLS");  //清屏
	Display(PlayerBoard, ROW, COL);
	//玩家扫雷
	PlayerMove(BoomBoard,PlayerBoard,ROW,COL);
}


void test()
{
	int input;
	do
	{
		menu();
		printf("\n请选择(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n开始游戏\n");
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
}



int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}
