#include "RankService.h"

void registerWinner(char * name, int step)
{
	pGamer g = NULL;
	Gamer player;
	player.step = step;
	strcpy(player.name, name);
	player.next = NULL;
	initialLink(&g);
	fileRead(g);
	insertNode(g, player);
	fileWrite(g);
	releaseLink(&g);
}

void printRank()
{
	pGamer g = NULL;
	initialLink(&g);
	if (!fileRead(g)) {
		printf("�ļ���ʧ���鿴����ʧ��\n");
		return;
	}
	pGamer temp = g->next;
	if (temp == NULL) {
		printf("��Ҳ����ڣ�\n");
	}
	else {
		int i;
		for (i = 1; temp != NULL; temp = temp->next, ++i) {
			printf("%3d��%10s\t\t%3d\n", i, temp->name, temp->step);
		}
	}
	releaseLink(&g);
}

