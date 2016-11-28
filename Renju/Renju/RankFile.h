#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameSystemService.h"

#define NAME 100

typedef struct {
	int step;
	char name[NAME];
	struct Gamer *next;
} Gamer, *pGamer;

/**
* 【函数名】fileRead
* 【功能】从文件读取排名信息
* 【参数】g 结构体指针
* 【返回值】BOOL值，TRUE表示读入成功，FALSE表示失败
*/
BOOL fileRead(pGamer g);

/**
* 【函数名】fileWrite
* 【功能】将信息写入文件中
* 【参数】g 结构体指针
* 【返回值】BOOL值，TRUE表示读入成功，FALSE表示失败
*/
BOOL fileWrite(pGamer g);

/**
* 【函数名】initialLink
* 【功能】初始化链表
* 【参数】g 链表头
* 【返回值】BOOL值，TRUE表示初始化成功，FALSE表示初始化失败
*/
BOOL initialLink(pGamer *g);

/**
* 【函数名】insertNode
* 【功能】插入结点（按步数大小顺序插入）
* 【参数】g 链表
* 【返回值】无
*/
void insertNode(const pGamer g, Gamer node);

/**
* 【函数名】releaseLink
* 【功能】释放链表
* 【参数】g 链表
* 【返回值】无
*/
void releaseLink(pGamer *g);