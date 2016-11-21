#pragma once

#include <Windows.h>
#include <conio.h>

// ������궨��
#define UP 0x48
#define DOWN 0x50
#define RIGHT 0x4d
#define LEFT 0x4b
// �س����궨��
#define ENTER VK_RETURN
// �˳����궨��
#define ESC VK_ESCAPE


typedef struct {
	int up;
	int down;
	int left;
	int right;
}LIMIT;

/**
* ����������userSelectMainMenu
* ���������ܡ������û�ѡ�����˵��Լ�ѡ����Ŀ
* ����������
* ������ֵ��intֵ���û�ѡ��
*/
int userSelectMainMenu();

/**
* ����������moveCursorPos
* ���������ܡ��ƶ����λ��
* ��������handle ָ����
*				*pos ���λ��
*				direct �ƶ�����
*              upLimit ����
*              downLimit ����
*				step �ƶ�����
* ������ֵ����
*/
void moveCursorPos(HANDLE handle, COORD *pos, int direct, LIMIT limit, int step);

/**
* ����������hideCursor
* ���������ܡ����ع��
* ��������handle ���
* ������ֵ����
*/
void hideCursor(HANDLE handle);

/**
* ����������showCursor
* ���������ܡ���ʾ���
* ��������handle ���
* ������ֵ����
*/
void showCursor(HANDLE handle);