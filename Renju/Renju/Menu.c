#include "Menu.h"

void hello()
{
	printf("**************************************\n");
	printf("������ӭ������������Ϸ������\n");
	printf("**************************************\n");
}

void printMainMenu()
{
	printf("\t-------��Ϸ�˵�-------\n\n");
	printf("\t      ���˶�ս\n\n");
	printf("\t      �˻���ս\n\n");
	printf("\t       ���а�\n\n");
	printf("\t      �鿴����\n\n");
	printf("\t      ��������\n\n");
	printf("\t        �˳�\n\n");
	printf("\t---------------------- \n");
}

void end()
{
	printf("**************************************\n");
	printf("������ �ǣ���ϣ����!������\n");
	printf("**************************************\n");
}

void drawChessboard(int chessboard[MAX][MAX])
{
	system("cls"); // �����Ļ

	int i, j;
	printf("    ");
	// ��ӡ�����ϵ���ĸ���
	for (i = 0; i < MAX; i++) {
		printf("%c ", 'A' + i);
	}
	printf("\n");
	// ��ʼ��������
	printf("  �q");
	for (i = 0; i < MAX; i++) {
		printf("��");
	}
	printf("�r\n");
	for (i = 0; i < MAX; i++) {
		printf("%02d��", i);
		for (j = 0; j < MAX; j++) {
			// ����if-else����û��ж��������Ƿ�������ӻ�������ɫ�����
			if (chessboard[i][j] == WHITE) {
				printf("��");
			}
			else if (chessboard[i][j] == BLACK) {
				printf("��");
			}
			else {
				printf("��");
			}
		}
		printf("��\n");
	}
	printf("  �t");
	for (i = 0; i < MAX; i++) {
		printf("��");
	}
	printf("�s\n");
	// �����ǻ������̴���
	printf("\t\t\t��Esc���˳�\n");
}

void hintColor(int chessColor)
{
	// �趨���
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��λ���
	COORD pos = { 0, 18 };
	SetConsoleCursorPosition(handle, pos);
	// ���������ɫ
	if (chessColor == WHITE) {
		printf("  ������");
	}
	else {
		printf("  ������");
	}
}

void printWinInfo(int win)
{
	// �趨���
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��λ���
	COORD pos = { 0,18 };
	SetConsoleCursorPosition(handle, pos);
	if (win == WHITE) {
		printf("  ��������������������\n");
		printf("  ��   �����Ӯ��   �� \n");
		printf("  ��������������������");
	}
	else if (win == BLACK) {
		printf("  ��������������������\n");
		printf("  ��   �����Ӯ��   �� \n");
		printf("  ��������������������");
	}
	else {
		printf("  ��������������������\n");
		printf("  ��    ��ƽ�֡�    �� \n");
		printf("  ��������������������");
	}
}
