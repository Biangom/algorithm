//#include<iostream>
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int M, N, K;
//bool map[101][101]; // true = �簢��, false = �����ִ°���, �ʱ� false
//bool isVisit[101][101]; // �湮������1, �������� 0
//int cnt; // ���̸� ���ϴ� cnt
//
//vector<int> v; // ������ ������ ��Ÿ���� v����
//
//int dir[4][2] =
//{
//	{1 , 0},
//	{-1, 0},
//	{0 , 1},
//	{0 ,-1}
//};
//
//bool areaCheck(int r, int c)
//{
//	return r >= 0 && r < M && c >= 0 && c < N;
//}
//
//void dfs(int m, int n)
//{
//	// Ž�������� 4�����̴�.
//	for (int i = 0; i < 4; i++)
//	{
//		int r = m + dir[i][0];
//		int c = n + dir[i][1];
//		// ��ȿ�� �迭�����̰�, �湮�����ʾҰ�, �����ִٸ� ����.
//		if (areaCheck(r, c) && !map[r][c] && !isVisit[r][c])
//		{
//			cnt++;
//			isVisit[r][c] = true;
//			dfs(r, c);
//		}
//	}
//
//	
//
//}
//
//
//int main(void)
//{
//	cin >> M >> N >> K;
//	while (K--)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int i = y1; i < y2; i++)
//		{
//			for (int j = x1; j < x2; j++)
//			{
//				map[i][j] = true;
//			}
//		}
//	}
//
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (!map[i][j] && !isVisit[i][j])
//			{
//				cnt = 1; // �켱 ũ��� �ϳ��̴�.
//				isVisit[i][j] = true;
//				dfs(i, j); // ���̿켱Ž���� �ǽ��Ͽ� ������ ���Ѵ�.
//				v.push_back(cnt); // �簢���� �����Ƿ� �߰���Ű��, �� �������� ����
//			}
//		}
//	}
//	/*
//
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			printf("%d", map[i][j]);
//		}
//		printf("\n");
//	}
//	*/
//	sort(v.begin(), v.end());
//	int v_size = v.size();
//	int i = 1;
//	cout << v_size << '\n';
//	for (auto n : v)
//	{
//		if (i++ != v_size) cout << n << " ";
//		else cout << n << '\n';
//		
//	}
//}

// isVisit�迭 ���� ����
// ��尡 �湮������ map�迭�� �� ��ġ�� ������ �������.
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int M, N, K;
bool map[101][101]; // true = �簢��, false = �����ִ°���, �ʱ�
int cnt; // ���̸� ���ϴ� cnt

vector<int> v; // ������ ������ ��Ÿ���� v����

int dir[4][2] =
{
	{ 1 , 0 },
	{ -1, 0 },
	{ 0 , 1 },
	{ 0 ,-1 }
};

bool areaCheck(int r, int c)
{
	return r >= 0 && r < M && c >= 0 && c < N;
}

void dfs(int m, int n)
{
	// Ž�������� 4�����̴�.
	for (int i = 0; i < 4; i++)
	{
		int r = m + dir[i][0];
		int c = n + dir[i][1];
		// ��ȿ�� �迭�����̰�, �湮�����ʾҰ�, �����ִٸ� ����.
		if (areaCheck(r, c) && !map[r][c])
		{
			cnt++;
			map[r][c] = true; // ���ٸ� �� ������ ������ ����������.
			dfs(r, c);
		}
	}



}

int main(void)
{
	cin >> M >> N >> K;
	while (K--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				map[i][j] = true;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!map[i][j] )
			{
				cnt = 1; // �켱 ũ��� �ϳ��̴�.
				map[i][j] = true;
				dfs(i, j); // ���̿켱Ž���� �ǽ��Ͽ� ������ ���Ѵ�.
				v.push_back(cnt); // �簢���� �����Ƿ� �߰���Ű��, �� �������� ����
			}
		}
	}

	sort(v.begin(), v.end());
	int v_size = v.size();
	int i = 1;
	cout << v_size << '\n';
	for (auto n : v)
	{
		if (i++ != v_size) cout << n << " ";
		else cout << n << '\n';
	}
}