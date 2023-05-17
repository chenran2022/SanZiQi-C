#include"game.h"
void initboard(char board[row][col], int r, int c)
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
//void displayboard(char board[row][col], int r, int c)
//{
//	int i;
//	for (i = 0; i < row; i++)
//	{
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		} 
//	}
//
//}
void displayboard(char board[row][col], int r, int c)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (j = 0; j < col && i < row-1; j++)
		{
			printf("---");
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}

void playermove(char board[row][col], int r, int c)
{
	int i, j;
	printf("�����\n");

	while (1)
	{
		printf("��������������->");
		scanf("%d%d", &i, &j);
		if (i > 0 && j > 0 && i<=row && j<=col)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�ռ�ã�����������->\n");

			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}
}
void computermove(char board[row][col], int r, int c)
{
	int i, j;
	printf("������: \n");
	while (1)
	{
		i = rand() % r;
		j = rand() % c;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}
int isping(char board[row][col], int r, int c)
{
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (board[i][j] == ' ')
				return 1;
		}
	}
	return 0;
}
char iswin(char board[row][col], int r, int c)
{
	//w���Ӯ ��*��������Ӯ��#����ƽ�֡�p����������c'
	int i, j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			{
				return board[i][2];
			}
		}
	}
	for (j = 0; j < c; j++)
	{
		for (i = 0; i < r; i++)
		{
			if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
			{
				return board[1][j];
			}
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//int ret=isping(board,row,col);
	if (isping(board, row, col) == 0)
		return 'p';
	else
		return 'c';
}
