/*
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW
-> 8

5 6
WLWWWW
WLLLLW
WWWWLL
WLLLLW
WWWWLL
-> 9
*/

#include<iostream>
#include<cstring>
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


char map[MAX_SIZE][MAX_SIZE];
int val[MAX_SIZE][MAX_SIZE];
char visit[MAX_SIZE][MAX_SIZE];

int unitStpath[MAX_SIZE][MAX_SIZE]; // 각 점에서의 최단거리 길이

int input_r; // 배열길이
int input_c;

int dir[4][2] = {
	{ 0 , 1 },
	{ 0 ,-1 },
	{ -1, 0 },
	{ 1 , 0 }
};

void getUnitStpath(int _r, int _c)
{
	int max = val[0][0];
	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
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

void BFS(DATA firstData)
{
	q.push(firstData);

	visit[firstData.r][firstData.c] = 1;
	val[firstData.r][firstData.c] = firstData.val; // 이 때 까지 간 거리 val을 배열값으로 초기화


												   // 큐가 비어있으면 탈출
	while (!q.empty()) {
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

	// 다 끝났으면 현재 위치에서 제일 긴 거리를 unitStpath 배열에 저장한다.
	// 시작점 마다 unitStpath 값이 다르므로, 시작점의 좌표에 해당하는 unitStpath에 저장한다.
	getUnitStpath(firstData.r, firstData.c);
	return;
}

int main(void)
{
	DATA start;
	int allPathMax; // 각 정점의 BFS 최댓값 중에서의 최댓값

	cin >> input_r;
	cin >> input_c;

	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
			char temp;
			cin >> temp;
			if (temp == 'L')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	// 모든 정점에 대해서 BFS 시작
	// 이 아니라 위쪽 일자, 아래쪽일자, 왼쪽일자, 오른쪽 일자의 정점에서만 BFS를 시작한다.
	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
			if (map[i][j] == 1) {
				start.r = i;
				start.c = j;
				start.val = 0;
				BFS(start);

				for(int i = 0 ; i < input_r; i++) {
					memset(val[i], 0, input_c * sizeof(int));
					memset(visit[i], 0, input_c * sizeof(int));				
				}
			}

		}
	}
	allPathMax = unitStpath[0][0];
	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
			if (unitStpath[i][j] > allPathMax)
				allPathMax = unitStpath[i][j];
		}
	}

	printf("%d", allPathMax);
	return 0;
}
