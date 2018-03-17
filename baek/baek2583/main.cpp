//#include<iostream>
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//int M, N, K;
//bool map[101][101]; // true = 사각형, false = 갈수있는공간, 초기 false
//bool isVisit[101][101]; // 방문했으면1, 안했으면 0
//int cnt; // 넓이를 구하는 cnt
//
//vector<int> v; // 영역의 개수를 나타내는 v벡터
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
//	// 탐색방향은 4방향이다.
//	for (int i = 0; i < 4; i++)
//	{
//		int r = m + dir[i][0];
//		int c = n + dir[i][1];
//		// 유효한 배열범위이고, 방문되지않았고, 갈수있다면 간다.
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
//				cnt = 1; // 우선 크기는 하나이다.
//				isVisit[i][j] = true;
//				dfs(i, j); // 깊이우선탐색을 실시하여 영역을 구한다.
//				v.push_back(cnt); // 사각형이 있으므로 추가시키고, 그 영역값을 저장
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

// isVisit배열 없는 버전
// 노드가 방문했으면 map배열의 그 위치를 벽으로 만들었음.
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int M, N, K;
bool map[101][101]; // true = 사각형, false = 갈수있는공간, 초기
int cnt; // 넓이를 구하는 cnt

vector<int> v; // 영역의 개수를 나타내는 v벡터

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
	// 탐색방향은 4방향이다.
	for (int i = 0; i < 4; i++)
	{
		int r = m + dir[i][0];
		int c = n + dir[i][1];
		// 유효한 배열범위이고, 방문되지않았고, 갈수있다면 간다.
		if (areaCheck(r, c) && !map[r][c])
		{
			cnt++;
			map[r][c] = true; // 갔다면 그 공간을 벽으로 만들어버린다.
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
				cnt = 1; // 우선 크기는 하나이다.
				map[i][j] = true;
				dfs(i, j); // 깊이우선탐색을 실시하여 영역을 구한다.
				v.push_back(cnt); // 사각형이 있으므로 추가시키고, 그 영역값을 저장
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