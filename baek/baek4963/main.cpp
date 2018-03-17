// made by dragostea
// boj.kr/4963 섬의개수

#include<iostream>

using namespace std;

int r, c;
int** arr;
int count;
int now;

//int dir[4][2] = { { -1, 0 },{ 1, 0 },{0, -1},{ 0, 1 } };

const int dir[8][2] = {
		{ -1, -1 },{ 0, -1 },{ 1, -1 },
		{ -1,  0 },			 { 1,  0 },
		{ -1,  1 },{ 0,  1 },{ 1,  1 }
};

bool isValid(int i, int j)
{
	if (i < 0 || i >= r || j < 0 || j >= c)
	{
		return false;
	}
	return true;
}

// 깊이우선탐색을하여 모두 0으로 만든다.
void dfs(int i, int j)
{
	arr[i][j] = 0;

	for (int k = 0; k < 8; k++)
	{
		if (isValid(i + dir[k][0], j + dir[k][1]) && arr[i + dir[k][0]][j + dir[k][1]] == 1)
			dfs(i + dir[k][0], j + dir[k][1]);
	}
}

int main(void)
{
	pair<int, int> now;
	pair<int, int> next;
	int count_land = 0;
	
	while (true)
	{
		scanf("%d %d", &c, &r);

		if (r == 0 && c == 0) return 0;
		
		arr = new int*[r];
		for (int i = 0; i < r; i++) arr[i] = new int[c];

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == 1)
				{
					dfs(i, j);
					count_land++;
				}
			}
		}
		printf("%d\n", count_land);
		count_land = 0;
	}
	return 0;
}


