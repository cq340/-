#include <stdio.h>
#include <stdlib.h>

#define N 9
#define totalStep 64

typedef struct{
	int x;
	int y;
}Step;

Step step[totalStep];
int board[N][N] = { 0 };
int a[9] = { 0, 1, 1, 2, 2, -1, -1, -2, -2 };
int b[9] = { 0, 2, -2, 1, -1, 2, -2, 1, -1 };
int flag = 0;

void knightTour(int steps, int x, int y) {
	int i, m;
	int nextX, nextY;
	int bestX, bestY;
	int min = 8;
	int sum;

	if (steps == totalStep) {
		flag = 1;
		return;
	}
	//试探性往前走一步，看下一步可以选择的方向，选择可选方向最少的那条路
	for (i = 1; i <= N - 1; i++) {
		nextX = x + a[i];
		nextY = y + b[i];
		if (nextX > 0 && nextX < N && nextY>0 && nextY < N && board[nextX][nextY] == 0) {
			sum = 0;
			for (m = 1; m <= N - 1; m++) {
				if (nextX + a[m] > 0 && nextX + a[m] < N && nextY + b[m]>0 && nextY + b[m] < N && board[nextX + a[m]][nextY + b[m]] == 0)
					sum++;
			}
			if (sum < min) {
				min = sum;
				bestX = nextX;
				bestY = nextY;
			}
		}
	}
	//找到之后走下一步
	board[bestX][bestY] = steps + 1;
	step[steps].x = bestX;
	step[steps].y = bestY;
	knightTour(steps + 1, bestX, bestY);
	if (flag)
		return;
	board[bestX][bestY] = 0;
}


int main() {
	int startx, starty;
	int i, j;
	int steps = 1;

	printf("输入骑士起始坐标\n");
	scanf_s("%d %d", &startx, &starty);
	step[0].x = startx;
	step[0].y = starty;
	board[startx][starty] = 1;
	knightTour(steps, startx, starty);
	printf("骑士巡游的路径为：\n");
	for (i = 0; i < totalStep; i++) {
		printf("(%d,%d)%s", step[i].x, step[i].y, (i < totalStep - 1) ? "->" : " ");
		if ((i + 1) % 8 == 0)
			printf("\n");
	}
	printf("\n");
	for (i = 1; i <= N - 1; i++) {
		for (j = 1; j <= N - 1; j++)
			printf("%02d ", board[i][j]);
		printf("\n");
	}
	system("pause");
	return 0;
}