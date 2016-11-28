#include "RankFile.h"

BOOL fileRead(pGamer g)
{
	FILE *fin;
	fin = fopen("rank.txt", "r");
	if (fin == NULL) {
		return FALSE;
	}
	Gamer node;
	while (~fscanf(fin, "%s %d", node.name, &node.step)) {
		node.next = NULL;
		insertNode(g, node);
	}
	fclose(fin);
	return TRUE;
}

BOOL fileWrite(pGamer g)
{
	FILE *fout;
	fout = fopen("rank.txt", "w");
	if (fout == NULL) {
		return FALSE;
	}
	pGamer temp = g->next;
	while (temp != NULL) {
		fprintf(fout, "%s %d\n", temp->name, temp->step);
		temp = temp->next;
	}
	fclose(fout);
	return TRUE;
}

BOOL initialLink(pGamer *g)
{
	// 申请头结点
	*g = (pGamer)malloc(sizeof(Gamer));
	if (*g == NULL) return FALSE;
	else {
		// 将头结点步数设置为-1，表示该结点为头结点
		(*g)->step = -1;
		(*g)->next = NULL;
		return TRUE;
	}
}

void insertNode(const pGamer g, Gamer node)
{
	pGamer cur = g->next;
	pGamer pre = g;
	pGamer temp = (pGamer)malloc(sizeof(Gamer));
	*temp = node;
	// 是否已经将结点插入
	BOOL flag = FALSE; 
	while (cur != NULL) {
		if (!flag && !strcmp(cur->name, temp->name)) {
			if (cur->step > temp->step) {
				pre->next = temp;
				temp->next = cur->next;
				free(cur);
			}
			// 由于本次游戏成绩比最好成绩差，故放弃本次成绩，视为已插入
			flag = TRUE;
			break;
		}
		else if (!flag && cur->step > temp->step) {
			pre->next = temp;
			temp->next = cur;
			flag = TRUE;
		}
		else {
			if (!strcmp(cur->name, temp->name) && flag) {
				pre->next = cur->next;
				free(cur);
				break;
			}
		}
		cur = cur->next;
		pre = pre->next;
	}
	// 若遍历完链表依然未插入（既是成绩在排名中最差的），在此插入链表
	if (!flag) {
		pre->next = temp;
	}
}

void releaseLink(pGamer *g)
{
	pGamer temp = *g, t;
	while (temp != NULL) {
		t = temp;
		temp = temp->next;
		free(t);
	}
	*g = NULL;
}
