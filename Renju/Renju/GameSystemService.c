#include "GameSystemService.h"

int userSelectMainMenu()
{
	// �趨���ָ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ���ع��
	hideCursor(handle);
	// �趨��ʼλ��
	COORD pos = { 10, 5 };
	SetConsoleCursorPosition(handle, pos);
	// �趨�û�ѡ��ָ�뷶Χ
	LIMIT limit = { 5, 15, 0, 0 };

	int input = 0, select = 0;
	printf("��");
	while (!select) {
		input = _getch();
		// �ų�ASCII������
		if (isascii(input) && input != ENTER) {
			continue;
		}
		// ����û�ѡ����Ŀ
		else if (input == ENTER) {
			select = 1;
		}
		else {
			input = _getch();
			// ������̷��������
			if (input == UP) {
				printf("\b\b  ");
				moveCursorPos(handle, &pos, UP, limit, 2);
				printf("��");
			}
			// ������̷��������
			else if (input == DOWN) {
				printf("\b\b  ");
				moveCursorPos(handle, &pos, DOWN, limit, 2);
				printf("��");
			}
			// ���������޹��ַ��������
			else {
				continue;
			}
		}
	}
	// ��������õ�����λ�ã������˳�ʱ�����������
	COORD temp;
	temp.X = 0;
	temp.Y = 18;
	SetConsoleCursorPosition(handle, temp);
	
	// �����û���ѡ��
	if (pos.Y == 5) return 1;
	else if (pos.Y == 7) return 2;
	else if (pos.Y == 9) return 3;
	else if (pos.Y == 11) return 4;
	else if (pos.Y == 13) return 5;
	else return 0;
}

void moveCursorPos(HANDLE handle, COORD *pos, int direct, LIMIT limit, int step)
{
	if (direct == UP) {
		pos->Y -= step;
		if (pos->Y < limit.up) pos->Y = limit.down;
	}
	else if (direct == DOWN) {
		pos->Y += step;
		if (pos->Y > limit.down) pos->Y = limit.up;
	}
	else if (direct == RIGHT) {
		pos->X += step;
		if (pos->X > limit.right) pos->X = limit.left;
	}
	else {
		pos->X -= step;
		if (pos->X < limit.left) pos->X = limit.right;
	}
	SetConsoleCursorPosition(handle, *pos);
}

void hideCursor(HANDLE handle)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE; // ���ع��
	SetConsoleCursorInfo(handle, &curInfo);
}

void showCursor(HANDLE handle)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = TRUE; // ��ʾ���
	SetConsoleCursorInfo(handle, &curInfo);
}
