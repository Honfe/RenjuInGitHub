#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include "GameService.h"
#include "GameSystemService.h"
#include "RankService.h"

#define MAX 15

/**
* ����������hello
* ���������ܡ������ӭ����
* ��������������
* ������ֵ����
*/
void hello();

/**
* ����������printMainMenu
* ���������ܡ�������˵�
* ��������������
* ������ֵ����
*/
void printMainMenu();

/**
* ����������end
* ���������ܡ������Ϸ��������
* ��������������
* ������ֵ����
*/
void end();

/**
* ����������drawChessboard
* ���������ܡ���������
* ��������������
* ������ֵ����
*/
void drawChessboard(int chessboard[MAX][MAX]);

/**
* ����������hintColor
* ���������ܡ���ʾ������ɫ
* ������������chessColor ������ɫ
* ������ֵ����
*/
void hintColor(int chessColor);

/**
* ����������printWinInfo
* ���������ܡ����˭ʤ˭��
* ������������win ʤ�����
* ������ֵ����
*/
void printWinInfo(int win);

/**
* ����������printRankInfo
* ���������ܡ���ӡ���а����Ϣ
* ��������������
* ������ֵ����
*/
void printRankInfo();

#endif