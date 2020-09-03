#ifndef __GAME_H__
#define __GAME_H__

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitializeBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char iswin(char board[ROW][COL], int row, int col);

#endif // !__GAME_H__


#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘
//将棋盘中所有位置置为' '
void InitializeBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{ 
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x, y;
		printf("请玩家输入坐标:>");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y>0 && y <= col && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else if (x > 0 && x <= row && y>0 && y <= col && board[x - 1][y - 1] != ' ')
			printf("该处已有棋子，请重新输入\n");
		else
			printf("坐标非法，请重新输入\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑落子\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char iswin(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
		}
	}
	return 'Q';
}



#define _CRT_SECURE_NO_WARNINGS 1

//设计一个三子棋游戏，包括菜单，显示棋盘，按坐标落子，显示赢家

#include "game.h"

void menu()
{
	printf("###################################################\n");
	printf("######         1.play        0.exit         #######\n");
	printf("###################################################\n");
}

void game()
{
	int first = 1;  //先行标志，为1则玩家先走
	//创建棋盘
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitializeBoard(board, ROW, COL);
	//判断谁先走
	first = rand() % 2;
	switch (first)
	{
	case 0:
		printf("电脑先行\n");
		goto COM;
	case 1:
		printf("玩家先行\n");
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		break;
	}
	while (1)
	{
		//玩家移动
		PlayerMove(board, ROW, COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断输赢
		if (iswin(board, ROW, COL) != 'C')
			break;
		//电脑移动
COM:	ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		if (iswin(board, ROW, COL) != 'C')
			break;
	}
	if (iswin(board, ROW, COL) == '*')
		printf("玩家获胜！\n");
	else if (iswin(board, ROW, COL) == '#')
		printf("电脑获胜！\n");
	else
		printf("平局！\n");
}


void test()
{
	while (1)
	{
		int ret = 0;
		menu();
		printf("请选择(1/0):>");
		scanf("%d", &ret);
		if (1 == ret)
			game();
		else if (0 == ret)
		{
			printf("退出游戏\n");
			break;
		}
		else
			printf("输入错误，请重新输入\n");
	}
}

int main()
{
	srand(time(NULL));
	test();
	return 0;
}

