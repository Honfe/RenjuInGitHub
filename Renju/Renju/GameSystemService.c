#include "GameSystemService.h"

int userSelectMainMenu()
{
	// 设定句柄指向
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 隐藏光标
	hideCursor(handle);
	// 设定初始位置
	COORD pos = { 10, 5 };
	SetConsoleCursorPosition(handle, pos);
	// 设定用户选择指针范围
	LIMIT limit = { 5, 15, 0, 0 };

	int input = 0, select = 0;
	printf("→");
	while (!select) {
		input = _getch();
		// 排除ASCII码输入
		if (isascii(input) && input != ENTER) {
			continue;
		}
		// 如果用户选定项目
		else if (input == ENTER) {
			select = 1;
		}
		else {
			input = _getch();
			// 点击键盘方向键向上
			if (input == UP) {
				printf("\b\b  ");
				moveCursorPos(handle, &pos, UP, limit, 2);
				printf("→");
			}
			// 点击键盘方向键向下
			else if (input == DOWN) {
				printf("\b\b  ");
				moveCursorPos(handle, &pos, DOWN, limit, 2);
				printf("→");
			}
			// 忽略其他无关字符及其操作
			else {
				continue;
			}
		}
	}
	// 将光标重置到结束位置，方便退出时输出结束界面
	COORD temp;
	temp.X = 0;
	temp.Y = 18;
	SetConsoleCursorPosition(handle, temp);
	
	// 返回用户的选择
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
	curInfo.bVisible = FALSE; // 隐藏光标
	SetConsoleCursorInfo(handle, &curInfo);
}

void showCursor(HANDLE handle)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = TRUE; // 显示光标
	SetConsoleCursorInfo(handle, &curInfo);
}
