#pragma once

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include "GameSystemService.h"
#include "RankService.h"
#include "Menu.h"

// 棋盘大小
#define MAX 15

// 棋子颜色
#define WHITE 1
#define BLACK -1
#define NON 0

/**
* 【函数名】PeopleToPeople
* 【功能】游戏进行时
* 【参数】chessboard 棋盘
* 【返回值】无
*/
void PeopleToPeople(int chessboard[MAX][MAX]);

/**
* 【函数名】playPiece
* 【功能】下子记录棋子位置
* 【参数】chessboard 棋盘
*				 pos 选定的位置
*				 chessColor 棋子颜色
* 【返回值】无
*/
void playPiece(int chessboard[MAX][MAX], COORD pos, int chessColor);

/**
* 【函数名】selectPos
* 【功能】选择下子位置
* 【参数】chessboard 棋盘
* 【返回值】COORD值，选定的坐标
*/
COORD selectPos(int chessboard[MAX][MAX]);

/**
* 【函数名】coverTarget
* 【功能】输出覆盖掉棋盘原有内容
* 【参数】chessboard 棋盘
*				x 棋盘x轴
*				y 棋盘y轴
* 【返回值】无
*/
void coverTarget(int chessboard[MAX][MAX], int x, int y);

/**
* 【函数名】quit
* 【功能】询问用户是否真的退出当前界面
* 【参数】无
* 【返回值】BOOL值，若选择退出则返回TRUE，否则返回FALSE
*/
BOOL quit();

/**
* 【函数名】initialChessboard
* 【功能】初始化棋盘
* 【参数】chessboard 棋盘
* 【返回值】无
*/
void initialChessboard(int chessboard[MAX][MAX]);

/**
* 【函数名】whoWin
* 【功能】判断胜负
* 【参数】chessboard 棋盘
* 【返回值】int值，1表示白方胜，-1表示黑方胜，0表示无胜负，2表示平局
*/
int whoWin(int chessboard[MAX][MAX]);

/**
* 【函数名】readPlayerInfo
* 【功能】读取玩家信息
* 【参数】step 赢家的步数
* 【返回值】无
*/
void readPlayerInfo(int step);