/*
6
1 1 1 1 1 1
0 0 1 0 0 1
1 1 1 0 1 1
1 0 0 0 1 0
1 1 1 0 1 0
0 0 1 1 1 1



*/

#include <stdio.h>
#include<iostream>
#include<iomanip>

using namespace std;

int n, cnt; // 맵의 크기와 카운트 변수
int map[10][10]; // 맵을 나타내는 2차원 배열
int x[100], y[100], l[100]; // 좌표와 길이를 담을 배열
int min;

							// 큐에 좌표 정보와 길이를 삽입하는 함수
void enqueue(int _x, int _y, int _l)
{
	x[cnt] = _x;
	y[cnt] = _y;
	l[cnt] = _l;
	cnt++;
}

void BFS(int _x, int _y)
{
	int pos = 0;

	// 시작점의 좌표 정보와 길이를 큐에 삽입한다
	enqueue(_x, _y, 1);
	map[y[pos]][x[pos]] = 0;
	// 더 이상 방문할 지점이 없거나, 도착 지점에 도착하면 루프를 탈출한다
	while (pos < cnt && (x[pos] != n - 1 || y[pos] != n - 1))
	{
		// 두 번 방문하게 하면 안되므로, 이미 지나갔다는 표시를 해둔다
		map[y[pos]][x[pos]] = l[cnt];

		// 위로 갈 수 있다면, 위 지점의 좌표 정보와 길이를 큐에 삽입한다
		if (y[pos] > 0 && map[y[pos] - 1][x[pos]] == 1)
			enqueue(x[pos], y[pos] - 1, l[pos] + 1);
		// 아래로 갈 수 있다면, 아래 지점의 좌표 정보와 길이를 큐에 삽입한다
		if (y[pos] < n - 1 && map[y[pos] + 1][x[pos]] == 1)
			enqueue(x[pos], y[pos] + 1, l[pos] + 1);
		// 왼쪽으로 갈 수 있다면, 왼쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
		if (x[pos] > 0 && map[y[pos]][x[pos] - 1] == 1)
			enqueue(x[pos] - 1, y[pos], l[pos] + 1);
		// 오른쪽로 갈 수 있다면, 오른쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
		if (x[pos] < n - 1 && map[y[pos]][x[pos] + 1] == 1)
			enqueue(x[pos] + 1, y[pos], l[pos] + 1);

		// 큐의 다음 순서의 지점을 방문한다
		pos++;

		cout << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(3) <<map[i][j];
			}
			cout << endl;
		}
	}

	// cnt가 pos보다 크다면, 도착 지점에 무사히 도착한 것이라고 말할 수 있다.
	// 위의 반복문은 도착점에 도착하게 되면 루프를 바로 빠져나오기 때문에,
	// 길이를 삽입하는 큐의 마지막 요소가 최단 경로의 길이라고 할 수 있다.
	if (pos < cnt)
		printf("최단 경로 길이: %d\n", l[pos]);
}

int main()
{
	int i, j;

	scanf("%d", &n);
	min = n * n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	BFS(0, 0); // BFS 시작!

	return 0;
}
