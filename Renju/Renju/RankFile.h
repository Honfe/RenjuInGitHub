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
* ����������fileRead
* �����ܡ����ļ���ȡ������Ϣ
* ��������g �ṹ��ָ��
* ������ֵ��BOOLֵ��TRUE��ʾ����ɹ���FALSE��ʾʧ��
*/
BOOL fileRead(pGamer g);

/**
* ����������fileWrite
* �����ܡ�����Ϣд���ļ���
* ��������g �ṹ��ָ��
* ������ֵ��BOOLֵ��TRUE��ʾ����ɹ���FALSE��ʾʧ��
*/
BOOL fileWrite(pGamer g);

/**
* ����������initialLink
* �����ܡ���ʼ������
* ��������g ����ͷ
* ������ֵ��BOOLֵ��TRUE��ʾ��ʼ���ɹ���FALSE��ʾ��ʼ��ʧ��
*/
BOOL initialLink(pGamer *g);

/**
* ����������insertNode
* �����ܡ������㣨��������С˳����룩
* ��������g ����
* ������ֵ����
*/
void insertNode(const pGamer g, Gamer node);

/**
* ����������releaseLink
* �����ܡ��ͷ�����
* ��������g ����
* ������ֵ����
*/
void releaseLink(pGamer *g);