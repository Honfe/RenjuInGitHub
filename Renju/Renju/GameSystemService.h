#pragma once

#include <Windows.h>
#include <conio.h>

// 方向键宏定义
#define UP 0x48
#define DOWN 0x50
#define RIGHT 0x4d
#define LEFT 0x4b
// 回车键宏定义
#define ENTER VK_RETURN
// 退出键宏定义
#define ESC VK_ESCAPE


typedef struct {
	int up;
	int down;
	int left;
	int right;
}LIMIT;

/**
* 【函数名】userSelectMainMenu
* 【函数功能】控制用户选择主菜单以及选中项目
* 【参数】无
* 【返回值】int值，用户选择
*/
int userSelectMainMenu();

/**
* 【函数名】moveCursorPos
* 【函数功能】移动光标位置
* 【参数】handle 指向句柄
*				*pos 光标位置
*				direct 移动方向
*              upLimit 上限
*              downLimit 下限
*				step 移动步数
* 【返回值】无
*/
void moveCursorPos(HANDLE handle, COORD *pos, int direct, LIMIT limit, int step);

/**
* 【函数名】hideCursor
* 【函数功能】隐藏光标
* 【参数】handle 句柄
* 【返回值】无
*/
void hideCursor(HANDLE handle);

/**
* 【函数名】showCursor
* 【函数功能】显示光标
* 【参数】handle 句柄
* 【返回值】无
*/
void showCursor(HANDLE handle);