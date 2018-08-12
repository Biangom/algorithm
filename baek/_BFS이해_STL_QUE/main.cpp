/*
6
1 1 1 1 1 1
0 0 1 0 0 1
1 1 1 0 1 1
1 0 0 0 1 0
1 1 1 0 1 0
0 0 1 1 1 1

*/

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<queue>

#define MAX_SIZE 100

typedef struct data {
	int r = 0;
	int c = 0;
	int val = 0;
}DATA;

using namespace std;

queue<DATA> q;


int map[MAX_SIZE][MAX_SIZE];
int val[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];

int unitStpath[MAX_SIZE][MAX_SIZE]; // 각 점에서의 최단거리 길이

int input; // 배열길이

int dir[4][2] = {
	{0 , 1},
	{0 ,-1},
	{-1, 0},
	{1 , 0}
};

void getUnitStpath(int _r, int _c)
{
	int max = val[0][0];
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			if (val[i][j] > max)
				max = val[i][j];
		}
	}
	unitStpath[_r][_c] = max;
}

bool isVaild(int r, int c)
{
	return 0 <= r && 0 <= c && r < MAX_SIZE && c < MAX_SIZE;
}

void BFS(DATA firstData )
{
	q.push(firstData);
	
	visit[firstData.r][firstData.c] = 1;
	val[firstData.r][firstData.c] = firstData.val ; // 이 때 까지 간 거리 val을 배열값으로 초기화


	// 큐가 비어있으면 탈출
	while(!q.empty()){
		DATA data;
		data = q.front(), q.pop();

		for (int i = 0; i < 4; i++) {
			DATA temp;
			temp.r = data.r + dir[i][1];
			temp.c = data.c + dir[i][0];
			// 상하좌우의 좌표를 임시적으로 담을 변수
			//상하좌우로 갈 좌표들이 유효하고, 맵이 길이고, 현재 방문하지 않았다면 블락 실행
			if (isVaild(temp.r, temp.c) && map[temp.r][temp.c] == 1 && !visit[temp.r][temp.c]) {
				temp.val = data.val + 1;
				visit[temp.r][temp.c] = 1; // 푸쉬할거니까 이미 방문한것이다.
				val[temp.r][temp.c] = temp.val; // 이 때 까지 간 거리 val을 배열값으로 초기화
				q.push(temp);
			}
		}
	}
	return;
}

int main(void)
{
	DATA start;
	start.r = 0;
	start.c = 0;
	start.val = 0;
	cin >> input;// sdf

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {
			cin >> map[i][j];
		}
	}

	BFS(start);

	//printf("\n");

	//for (int i = 0; i < input; i++) {
	//	for (int j = 0; j < input; j++) {
	//		printf("%4d", map[i][j]);
	//	}
	//	printf("\n");
	//}

	//printf("\n");

	//for (int i = 0; i < input; i++) {
	//	for (int j = 0; j < input; j++) {
	//		printf("%4d", val[i][j]);
	//	}
	//	printf("\n");
	//}
	//	

	return 0;
}
