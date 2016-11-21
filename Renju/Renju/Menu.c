#include "Menu.h"

void hello()
{
	printf("**************************************\n");
	printf("●○●○●欢迎进入五子棋游戏○●○●○\n");
	printf("**************************************\n");
}

void printMainMenu()
{
	printf("\t-------游戏菜单-------\n\n");
	printf("\t      人人对战\n\n");
	printf("\t      人机对战\n\n");
	printf("\t       排行榜\n\n");
	printf("\t      查看规则\n\n");
	printf("\t      关于我们\n\n");
	printf("\t        退出\n\n");
	printf("\t---------------------- \n");
}

void end()
{
	printf("**************************************\n");
	printf("●○●○● ＧａｍｅＯｖｅｒ!○●○●○\n");
	printf("**************************************\n");
}

void drawChessboard(int chessboard[MAX][MAX])
{
	system("cls"); // 清空屏幕

	int i, j;
	printf("    ");
	// 打印棋盘上的字母编号
	for (i = 0; i < MAX; i++) {
		printf("%c ", 'A' + i);
	}
	printf("\n");
	// 开始绘制棋盘
	printf("  ╭");
	for (i = 0; i < MAX; i++) {
		printf("┳");
	}
	printf("╮\n");
	for (i = 0; i < MAX; i++) {
		printf("%02d┣", i);
		for (j = 0; j < MAX; j++) {
			// 以下if-else组合用户判断棋盘上是否存在棋子或棋子颜色并输出
			if (chessboard[i][j] == WHITE) {
				printf("●");
			}
			else if (chessboard[i][j] == BLACK) {
				printf("○");
			}
			else {
				printf("╋");
			}
		}
		printf("┫\n");
	}
	printf("  ╰");
	for (i = 0; i < MAX; i++) {
		printf("┻");
	}
	printf("╯\n");
	// 以上是绘制棋盘代码
	printf("\t\t\t按Esc键退出\n");
}

void hintColor(int chessColor)
{
	// 设定句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 定位光标
	COORD pos = { 0, 18 };
	SetConsoleCursorPosition(handle, pos);
	// 检查棋子颜色
	if (chessColor == WHITE) {
		printf("  白子下");
	}
	else {
		printf("  黑子下");
	}
}

void printWinInfo(int win)
{
	// 设定句柄
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// 定位光标
	COORD pos = { 0,18 };
	SetConsoleCursorPosition(handle, pos);
	if (win == WHITE) {
		printf("  ┏━━━━━━━━┓\n");
		printf("  ┃   ●白子赢●   ┃ \n");
		printf("  ┗━━━━━━━━┛");
	}
	else if (win == BLACK) {
		printf("  ┏━━━━━━━━┓\n");
		printf("  ┃   ○黑子赢○   ┃ \n");
		printf("  ┗━━━━━━━━┛");
	}
	else {
		printf("  ┏━━━━━━━━┓\n");
		printf("  ┃    ○平局●    ┃ \n");
		printf("  ┗━━━━━━━━┛");
	}
}
