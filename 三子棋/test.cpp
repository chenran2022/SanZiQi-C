//测试三子棋游戏

#include "game.h"


void menu()
{
	printf("******************************\n");
	printf("*****  1.play   0.exit  ******\n");
	printf("******************************\n");

}
void game()
{
	char board[row][col] = {};
	initboard(board, row, col);//初始化棋盘
	displayboard(board, row, col);
	//玩家下棋
	while (1)
	{
		playermove(board, row, col);
		displayboard(board, row, col);
		//判断玩家是否赢
		iswin(board,row,col);
		if (iswin(board, row, col) == '*')
		{
			printf("玩家赢\n");
			break;
		}
		if (iswin(board, row, col) == 'p')
		{
			printf("平局\n");
			break;
		}
		computermove(board, row, col);
		displayboard(board, row, col);
		//判断电脑是否赢
		iswin(board, row, col);
		if (iswin(board, row, col) == '#')
		{
			printf("电脑赢\n");
			break;
		}
		if (iswin(board, row, col) == 'p')
		{
			printf("平局\n");
			break;
		}

	}

}
void test()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入->\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}