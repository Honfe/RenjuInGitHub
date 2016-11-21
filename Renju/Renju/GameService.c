#include "GameService.h"

void PeopleToPeople(int chessboard[MAX][MAX])
{
	// 人人对战模式下白子先下
	int chessColor = WHITE;
	COORD pos;
	drawChessboard(chessboard);
	while (1) {
		hintColor(chessColor);
		pos = selectPos(chessboard);
		// 用户选择退出并询问确认退出操作
		if (pos.X == -1 && quit()) {
			break; // 跳出下棋循环，结束当前游戏
		}
		else {
			playPiece(chessboard, pos, chessColor);
		}
		drawChessboard(chessboard);
		int win = whoWin(chessboard);
		// 判断此次下子能否得出输赢或平局
		if (win) {
			printWinInfo(win);
			system("pause"); // 卡住方便用户查看结果
			break; // 结束游戏
		}
		else {
			// 下一轮下子换色
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
	// 设定句柄指向
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 隐藏光标
	hideCursor(handle);
	// 设定初始位置
	COORD pos = { 4, 2 };
	SetConsoleCursorPosition(handle, pos);
	// 设定用户选择指针范围
	LIMIT limit = { 2, 16, 4, 32 };

	int input = 0, select = 0;
	printf("◎");
	while (!select) {
		input = _getch();
		// 如果用户选定位置
		if (input == ENTER) {
			if (chessboard[pos.Y - limit.up][(pos.X - limit.left) / 2] == NON) {
				select = 1;
			}
		}
		// 如果用户选择退出
		else if (input == ESC) {
			pos.X = -1;
			pos.Y = -1;
			return pos;
		}
		// 排除其他ASCII码输入
		else if (isascii(input)) {
			continue;
		}
		else {
			input = _getch();
			// 点击键盘方向键向上
			if (input == UP) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 1);
				printf("◎");
			}
			// 点击键盘方向键向下
			else if (input == DOWN) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 1);
				printf("◎");
			}
			// 点击键盘方向键向右
			else if (input == RIGHT) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 2);
				printf("◎");
			}
			// 点击键盘方向键向左
			else if (input == LEFT) {
				coverTarget(chessboard, (pos.X - limit.left) / 2, pos.Y - limit.up);
				moveCursorPos(handle, &pos, input, limit, 2);
				printf("◎");
			}
			// 忽略其他无关字符及其操作
			else {
				continue;
			}
		}
	}
	// 将pos的值设置为对应数组棋盘上的下标值
	pos.Y = pos.Y - limit.up;
	pos.X = (pos.X - limit.left) / 2;
	// 返回选定的位置
	return pos;
}

void coverTarget(int chessboard[MAX][MAX], int x, int y)
{
	if (chessboard[y][x] == NON) {
		printf("\b\b╋");
	}
	else if (chessboard[y][x] == WHITE) {
		printf("\b\b●");
	}
	// 黑子
	else {
		printf("\b\b○");
	}
}

int quit()
{
	// 设定句柄指向
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 显示光标
	showCursor(handle);
	// 将光标定位到棋盘以下
	COORD pos = { 0 , 18 };
	SetConsoleCursorPosition(handle, pos);

	printf("此时退出将不保存棋局，也不记录你的战果\n");
	printf("你确定真的要退出吗?（y/n）：");
	
	char q;
	// 用户输入选择
	q = getchar();
	while (q != 'y' && q != 'n') {
		printf("请输入y或者n：");
		q = getchar();
	}
	// 读取缓冲区残余内容
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
	// 判断行上是否存在五子相连
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
	// 判断列上是否存在五子相连
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
	// 判断正斜杠方向上是否五子相连
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
	// 判断反斜杠方向上是否五子相连
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
	// 统计棋盘上的棋子个数
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (chessboard[i][j]) {
				++count;
			}
		}
	}
	// 判断棋盘上是否下满棋子
	if (count >= MAX * MAX) return 2;
	else return 0;
}
