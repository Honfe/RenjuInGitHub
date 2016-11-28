#pragma once

#include <stdio.h>
#include <Windows.h>
#include <ctype.h>
#include "GameSystemService.h"
#include "RankService.h"
#include "Menu.h"

// ���̴�С
#define MAX 15

// ������ɫ
#define WHITE 1
#define BLACK -1
#define NON 0

/**
* ����������PeopleToPeople
* �����ܡ���Ϸ����ʱ
* ��������chessboard ����
* ������ֵ����
*/
void PeopleToPeople(int chessboard[MAX][MAX]);

/**
* ����������playPiece
* �����ܡ����Ӽ�¼����λ��
* ��������chessboard ����
*				 pos ѡ����λ��
*				 chessColor ������ɫ
* ������ֵ����
*/
void playPiece(int chessboard[MAX][MAX], COORD pos, int chessColor);

/**
* ����������selectPos
* �����ܡ�ѡ������λ��
* ��������chessboard ����
* ������ֵ��COORDֵ��ѡ��������
*/
COORD selectPos(int chessboard[MAX][MAX]);

/**
* ����������coverTarget
* �����ܡ�������ǵ�����ԭ������
* ��������chessboard ����
*				x ����x��
*				y ����y��
* ������ֵ����
*/
void coverTarget(int chessboard[MAX][MAX], int x, int y);

/**
* ����������quit
* �����ܡ�ѯ���û��Ƿ�����˳���ǰ����
* ����������
* ������ֵ��BOOLֵ����ѡ���˳��򷵻�TRUE�����򷵻�FALSE
*/
BOOL quit();

/**
* ����������initialChessboard
* �����ܡ���ʼ������
* ��������chessboard ����
* ������ֵ����
*/
void initialChessboard(int chessboard[MAX][MAX]);

/**
* ����������whoWin
* �����ܡ��ж�ʤ��
* ��������chessboard ����
* ������ֵ��intֵ��1��ʾ�׷�ʤ��-1��ʾ�ڷ�ʤ��0��ʾ��ʤ����2��ʾƽ��
*/
int whoWin(int chessboard[MAX][MAX]);

/**
* ����������readPlayerInfo
* �����ܡ���ȡ�����Ϣ
* ��������step Ӯ�ҵĲ���
* ������ֵ����
*/
void readPlayerInfo(int step);