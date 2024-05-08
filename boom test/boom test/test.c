#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"


void menu()
{
	printf("**********************\n");
	printf("***** 1. play    *****\n");
	printf("***** 0. exit    *****\n");
	printf("**********************\n");
}

void game()
{
	//���ɨ����Ϸ
	//mine�����д�Ų��úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//����ȫ����ʼ��Ϊ'0'

	//show�����д���Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����ȫ����ʼ��Ϊ'*'

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//������
	//��9*9���������������10����
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//��ӡ����
	DisplayBoard(show, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);//1 0 x
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�������˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}
