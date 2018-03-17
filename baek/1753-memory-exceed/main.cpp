// made by http://kaspyx.tistory.com/64

#include <stdio.h>
#include <iostream>
#include <vector>

#define INF 1000000

int** a;
// 최단 경로를 저장하는 배열 dist
// 방문한 정점을 표시해주는 visit 배열

int* visit;
int* dist;
int start, end;
int n, m;

// n은 정점의 개수
// m은 간선의 개수

// input 값 sample

//첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다.
//(1≤V≤20, 000, 1≤E≤300, 000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다.
//둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다.
//셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수(u, v, w)가 순서대로 주어진다.
//이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다.u와 v는 서로 다르며 w는 10 이하의 자연수이다.
//서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.


/*

입력
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6


출력
0
2
3
7
INF

*/


void input()
{
	int i, j;
	int from, to;
	int w;
	// 정점의개수 V와 간선의갯수 E를 입력받는다.
	// 정점의개수 n, 간선의개수 m
	scanf("%d %d", &n, &m);
	scanf("%d", &start);

	a = new int*[n + 1];
	for (i = 1; i <= n; i++)
		a[i] = new int[n + 1];

	visit = new int[n + 1];
	dist = new int[n + 1];

	// 각 정점으로 가는 간선의 가중치를 무한대로 초기화한다.(최소값을 구하기위해)
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			a[i][j] = INF;

	for (i = 1; i <= m; i++) // 정점에서 정점으로 가는 간선의 가중치가 입력
	{
		scanf("%d %d %d", &from, &to, &w);
		a[from][to] = w;
	}

	for (i = 1; i <= n; i++)
		dist[i] = INF;

	for (i = 1; i <= n; i++)
		visit[i] = 0;

}

void dijkstra()
{
	int i, j;
	int min;

	// v는 방문한 정점
	int v;

	dist[start] = 0;        // 시작점의 거리 0

	for (i = 1; i <= n; i++)
	{
		min = INF;

		for (j = 1; j <= n; j++)
		{
			if (visit[j] == 0 && min > dist[j])    // 갈수 있는 정점중에 가장 가까운 정점 선택
			{
				min = dist[j];
				v = j;
			}
		}

		visit[v] = 1;   // 가장 가까운 정점으로 방문, i정점에서 가장 가까운 최단경로 v

		for (j = 1; j <= n; j++)
		{
			if (dist[j] > dist[v] + a[v][j])       // 방문한 정점을 통해 다른 정점까지의 거리가 짧아지는지 계산하여 누적된값 저장
				dist[j] = dist[v] + a[v][j];
		}
	}
}


int main(void)
{
	input();
	dijkstra();

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)
			printf("INF\n");
		// start가 지점이 아닌데도 최단거리가 0이라는 것은 못간다는 것을 의미
		else
			printf("%d\n", dist[i]);

		/*
		if (dist[i] == INF)
		printf("INF\n");
		// start가 지점이 아닌데도 최단거리가 0이라는 것은 못간다는 것을 의미
		else if (i != start && dist[i] == 0);
		else
		printf("%d\n", dist[i]);
		*/
	}
	return 0;
}
