//������������Ϸ

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
	initboard(board, row, col);//��ʼ������
	displayboard(board, row, col);
	//�������
	while (1)
	{
		playermove(board, row, col);
		displayboard(board, row, col);
		//�ж�����Ƿ�Ӯ
		iswin(board,row,col);
		if (iswin(board, row, col) == '*')
		{
			printf("���Ӯ\n");
			break;
		}
		if (iswin(board, row, col) == 'p')
		{
			printf("ƽ��\n");
			break;
		}
		computermove(board, row, col);
		displayboard(board, row, col);
		//�жϵ����Ƿ�Ӯ
		iswin(board, row, col);
		if (iswin(board, row, col) == '#')
		{
			printf("����Ӯ\n");
			break;
		}
		if (iswin(board, row, col) == 'p')
		{
			printf("ƽ��\n");
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������->\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}