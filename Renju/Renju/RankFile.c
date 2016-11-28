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
	// ����ͷ���
	*g = (pGamer)malloc(sizeof(Gamer));
	if (*g == NULL) return FALSE;
	else {
		// ��ͷ��㲽������Ϊ-1����ʾ�ý��Ϊͷ���
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
	// �Ƿ��Ѿ���������
	BOOL flag = FALSE; 
	while (cur != NULL) {
		if (!flag && !strcmp(cur->name, temp->name)) {
			if (cur->step > temp->step) {
				pre->next = temp;
				temp->next = cur->next;
				free(cur);
			}
			// ���ڱ�����Ϸ�ɼ�����óɼ���ʷ������γɼ�����Ϊ�Ѳ���
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
	// ��������������Ȼδ���루���ǳɼ������������ģ����ڴ˲�������
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
