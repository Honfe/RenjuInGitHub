#include "GameService.h"

void PeopleToPeople(int chessboard[MAX][MAX])
{
	// ���˶�սģʽ�°�������
	int chessColor = WHITE;
	COORD pos;
	drawChessboard(chessboard);
	while (1) {
		hintColor(chessColor);
		pos = selectPos(chessboard);
		// �û�ѡ���˳���ѯ��ȷ���˳�����
		if (pos.X == -1 && quit()) {
			break; // ��������ѭ����������ǰ��Ϸ
		}
		else {
			playPiece(chessboard, pos, chessColor);
		}
		drawChessboard(chessboard);
		int win = whoWin(chessboard);
		// �жϴ˴������ܷ�ó���Ӯ��ƽ��
		if (win) {
			printWinInfo(win);
			system("pause"); // ��ס�����û��鿴���
			break; // ������Ϸ
		}
		else {
			// ��һ�����ӻ�ɫ
			if (chessColor == WHITE) chessColor = BLACK;
			else chessColor = WHITE;
		}
	}
}

void playPiece(int chessboard[MAX][MAX], COORD pos, int chessColor)
{
	chessboard[pos.Y][pos.X] = chessColor;
}

COORD selectPos(int chessboard[MAX][MAX])
{
	// �趨���ָ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ���ع��
	hideCursor(handle);
	// �趨��ʼλ��
	COORD pos = { 4, 2 };
	SetConsoleCursorPosition(handle, pos);
	// �趨�û�ѡ��ָ�뷶Χ
	LIMIT limit = { 2, 16, 4, 32 };

	int input = 0, select = 0;
	printf("��");
	while (!select) {
		input = _getch();
		// ����û�ѡ��λ��
		if (input == ENTER) {
			if (chessboard[pos.Y - limit.up][(pos.X - limit.left) / 2] == NON) {
				select = 1;
			}
		}
		// ����û�ѡ���˳�
		else if (input == ESC) {
			pos.X = -1;
			pos.Y = -1;
			return pos;
		}
		// �ų�����ASCII������
		else if (isascii(input)) {
			continue;
		}
		else {
			input = _getch();
			// ������̷��������
			if (input == UP) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 1);
				printf("��");
			}
			// ������̷��������
			else if (input == DOWN) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 1);
				printf("��");
			}
			// ������̷��������
			else if (input == RIGHT) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 2);
				printf("��");
			}
			// ������̷��������
			else if (input == LEFT) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 2);
				printf("��");
			}
			// ���������޹��ַ��������
			else {
				continue;
			}
		}
	}
	// ��pos��ֵ����Ϊ��Ӧ���������ϵ��±�ֵ
	pos.Y = pos.Y - limit.up;
	pos.X = (pos.X - limit.left) / 2;
	// ����ѡ����λ��
	return pos;
}

void coverTarget(int chessboard[MAX][MAX], int x, int y)
{
	if (chessboard[y][x] == NON) {
		printf("\b\b��");
	}
	else if (chessboard[y][x] == WHITE) {
		printf("\b\b��");
	}
	// ����
	else {
		printf("\b\b��");
	}
}

int quit()
{
	// �趨���ָ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��ʾ���
	showCursor(handle);
	// ����궨λ����������
	COORD pos = { 0 , 18 };
	SetConsoleCursorPosition(handle, pos);

	printf("��ʱ�˳�����������֣�Ҳ����¼���ս��\n");
	printf("��ȷ�����Ҫ�˳���?��y/n����");
	
	char q;
	// �û�����ѡ��
	q = getchar();
	while (q != 'y' && q != 'n') {
		printf("������y����n��");
		q = getchar();
	}
	// ��ȡ��������������
	while (getchar() != '\n') continue;
	if (q == 'y') {
		return 1;
	}
	else {
		return 0;
	}
}

void initialChessboard(int chessboard[MAX][MAX])
{
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			chessboard[i][j] = 0;
		}
	}
}

int whoWin(int chessboard[MAX][MAX])
{
	int i, j, flag = 0, count = 0;
	// �ж������Ƿ������������
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX - 5; j++) {
			if ((chessboard[i][j] != 0) && 
				(chessboard[i][j] == chessboard[i][j + 1]) &&
				(chessboard[i][j] == chessboard[i][j + 2]) &&
				(chessboard[i][j] == chessboard[i][j + 3]) &&
				(chessboard[i][j] == chessboard[i][j + 4])) {
				return chessboard[i][j];
			}
		}
	}
	// �ж������Ƿ������������
	for (j = 0; j < MAX; j++) {
		for (i = 0; i < MAX - 5; i++) {
			if ((chessboard[i][j] != 0) &&
				(chessboard[i][j] == chessboard[i + 1][j]) &&
				(chessboard[i][j] == chessboard[i + 2][j]) &&
				(chessboard[i][j] == chessboard[i + 3][j]) &&
				(chessboard[i][j] == chessboard[i + 4][j])) {
				return chessboard[i][j];
			}
		}
	}
	// �ж���б�ܷ������Ƿ���������
	for (i = 4; i < MAX; i++) {
		for (j = 0; j < MAX - 5; j++) {
			if ((chessboard[i][j] != 0) &&
				(chessboard[i][j] == chessboard[i - 1][j + 1]) &&
				(chessboard[i][j] == chessboard[i - 2][j + 2]) &&
				(chessboard[i][j] == chessboard[i - 3][j + 3]) &&
				(chessboard[i][j] == chessboard[i - 4][j + 4])) {
				return chessboard[i][j];
			}
		}
	}
	// �жϷ�б�ܷ������Ƿ���������
	for (i = 0; i < MAX - 5; i++) {
		for (j = 0; j < MAX - 5; j++) {
			if ((chessboard[i][j] != 0) &&
				(chessboard[i][j] == chessboard[i + 1][j + 1]) &&
				(chessboard[i][j] == chessboard[i + 2][j + 2]) &&
				(chessboard[i][j] == chessboard[i + 3][j + 3]) &&
				(chessboard[i][j] == chessboard[i + 4][j + 4])) {
				return chessboard[i][j];
			}
		}
	}
	// ͳ�������ϵ����Ӹ���
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (chessboard[i][j]) {
				++count;
			}
		}
	}
	// �ж��������Ƿ���������
	if (count >= MAX * MAX) return 2;
	else return 0;
}
