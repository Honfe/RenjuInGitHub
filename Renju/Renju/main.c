#include <stdio.h>
#include "GameService.h"
#include "GameSystemService.h"
#include "Menu.h"

// 记录棋盘信息，无子用0表示，黑子用-1表示，白子用1表示
int chessboard[MAX][MAX] = { 0 };

/**
* 【函数名】main
* 【函数功能】主函数，既入口函数
* 【函数参数】无
* 【返回值】int类型，说明程序的执行状态
*/
int main()
{
	int select;
	do {
		system("cls");
		hello();
		printMainMenu();
		select = userSelectMainMenu();
		switch (select) {
		case 1:
			system("cls"); // 清空屏幕 
			initialChessboard(chessboard);
			PeopleToPeople(chessboard);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		} 
	} while (select != 0); // 遇0退出游戏
	end();

	return 0;
}

