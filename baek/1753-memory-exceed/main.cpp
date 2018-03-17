// made by http://kaspyx.tistory.com/64

#include <stdio.h>
#include <iostream>
#include <vector>

#define INF 1000000

int** a;
// �ִ� ��θ� �����ϴ� �迭 dist
// �湮�� ������ ǥ�����ִ� visit �迭

int* visit;
int* dist;
int start, end;
int n, m;

// n�� ������ ����
// m�� ������ ����

// input �� sample

//ù° �ٿ� ������ ���� V�� ������ ���� E�� �־�����.
//(1��V��20, 000, 1��E��300, 000) ��� �������� 1���� V���� ��ȣ�� �Ű��� �ִٰ� �����Ѵ�.
//��° �ٿ��� ���� ������ ��ȣ K(1��K��V)�� �־�����.
//��° �ٺ��� E���� �ٿ� ���� �� ������ ��Ÿ���� �� ���� ����(u, v, w)�� ������� �־�����.
//�̴� u���� v�� ���� ����ġ w�� ������ �����Ѵٴ� ���̴�.u�� v�� ���� �ٸ��� w�� 10 ������ �ڿ����̴�.
//���� �ٸ� �� ���� ���̿� ���� ���� ������ ������ ���� ������ �����Ѵ�.


/*

�Է�
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6


���
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
	// �����ǰ��� V�� �����ǰ��� E�� �Է¹޴´�.
	// �����ǰ��� n, �����ǰ��� m
	scanf("%d %d", &n, &m);
	scanf("%d", &start);

	a = new int*[n + 1];
	for (i = 1; i <= n; i++)
		a[i] = new int[n + 1];

	visit = new int[n + 1];
	dist = new int[n + 1];

	// �� �������� ���� ������ ����ġ�� ���Ѵ�� �ʱ�ȭ�Ѵ�.(�ּҰ��� ���ϱ�����)
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			a[i][j] = INF;

	for (i = 1; i <= m; i++) // �������� �������� ���� ������ ����ġ�� �Է�
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

	// v�� �湮�� ����
	int v;

	dist[start] = 0;        // �������� �Ÿ� 0

	for (i = 1; i <= n; i++)
	{
		min = INF;

		for (j = 1; j <= n; j++)
		{
			if (visit[j] == 0 && min > dist[j])    // ���� �ִ� �����߿� ���� ����� ���� ����
			{
				min = dist[j];
				v = j;
			}
		}

		visit[v] = 1;   // ���� ����� �������� �湮, i�������� ���� ����� �ִܰ�� v

		for (j = 1; j <= n; j++)
		{
			if (dist[j] > dist[v] + a[v][j])       // �湮�� ������ ���� �ٸ� ���������� �Ÿ��� ª�������� ����Ͽ� �����Ȱ� ����
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
		// start�� ������ �ƴѵ��� �ִܰŸ��� 0�̶�� ���� �����ٴ� ���� �ǹ�
		else
			printf("%d\n", dist[i]);

		/*
		if (dist[i] == INF)
		printf("INF\n");
		// start�� ������ �ƴѵ��� �ִܰŸ��� 0�̶�� ���� �����ٴ� ���� �ǹ�
		else if (i != start && dist[i] == 0);
		else
		printf("%d\n", dist[i]);
		*/
	}
	return 0;
}
