#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include "GameService.h"
#include "GameSystemService.h"
#include "RankService.h"

#define MAX 15

/**
* 【函数名】hello
* 【函数功能】输出欢迎界面
* 【函数参数】无
* 【返回值】无
*/
void hello();

/**
* 【函数名】printMainMenu
* 【函数功能】输出主菜单
* 【函数参数】无
* 【返回值】无
*/
void printMainMenu();

/**
* 【函数名】end
* 【函数功能】输出游戏结束界面
* 【函数参数】无
* 【返回值】无
*/
void end();

/**
* 【函数名】drawChessboard
* 【函数功能】绘制棋盘
* 【函数参数】无
* 【返回值】无
*/
void drawChessboard(int chessboard[MAX][MAX]);

/**
* 【函数名】hintColor
* 【函数功能】提示下棋颜色
* 【函数参数】chessColor 棋子颜色
* 【返回值】无
*/
void hintColor(int chessColor);

/**
* 【函数名】printWinInfo
* 【函数功能】输出谁胜谁负
* 【函数参数】win 胜出情况
* 【返回值】无
*/
void printWinInfo(int win);

/**
* 【函数名】printRankInfo
* 【函数功能】打印排行榜的信息
* 【函数参数】无
* 【返回值】无
*/
void printRankInfo();

#endif