#pragma once

#include <stdio.h>
#include <string.h>
#include "RankFile.h"

/**
* 【函数名】registerWinner
* 【函数功能】登记赢家的成绩
* 【函数参数】name 赢家姓名
*					   step 赢家走的步数
* 【返回值】无
*/
void registerWinner(char *name, int step);

/**
* 【函数名】printRank
* 【函数功能】输出赢家的排名
* 【函数参数】无
* 【返回值】无
*/
void printRank();

