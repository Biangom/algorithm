// made by dragostea
// boj.kr/7576 토마토


#include<stdio.h>
#include<iostream>
#include<stdlib.h>

#include <queue>
using namespace std;

int col, row;


int dir[4][2] = {
	{0, 1}, {0, -1},
	{1, 0}, {-1, 0}
};


bool isValid(int r, int c)
{
	return r >= 0 && r <= row - 1 && c >= 0 && c <= col - 1;

}

bool isCheckArr(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
				return true;
		}
	}
	return false;
}

int calc(queue<pair <int,int>> que, int** arr, int row, int col)
{
	int result = 0;
	bool perfect = false;
	// 이전 익은토마토 개수
	int prevNum = 0;
	// 오늘 익은토마토개수
	int nowNum = 0;

	bool notAble = true;

	// 배열의 요소가 1인 요소
	pair<int, int> pu;

	// 초기설정
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			// 익은 토마토라면 push한다 
			if (arr[i][j] == 1)
			{
				pu.first = i;
				pu.second = j;
				que.push(pu);
				prevNum++;
				notAble = false;
			}
		}
	}

	// 익은 토마토가 하나라도 없다면
	// 토마토가 모두 익지 못하는 상황이라 -1반환
	if (notAble)
		return -1;

	// 익은 토마토가 하나라도 있다면 다음을 반복
	while (true)
	{
		if (que.empty())
		{
			if (isCheckArr(arr, row, col))
			{
				return -1;
			}
			return result;
		}
		
		if (prevNum == 0)
		{
			prevNum = nowNum;
			nowNum = 0;
			result++;
		}

		pu = que.front(); 
		que.pop();
		prevNum--;
		pair<int, int> zero;

		
		for (int i = 0; i < 4; i++)
		{
			int r_dir = dir[i][0];
			int c_dir = dir[i][1];

			if ( isValid(pu.first + r_dir, pu.second + c_dir) && arr[pu.first + r_dir][pu.second + c_dir] == 0)
			{
				zero.first = pu.first + r_dir;
				zero.second = pu.second + c_dir;
				que.push(zero);
				arr[zero.first][zero.second] = 1;
				nowNum++;
			}

		}
		
	
	}
}

int main(void)
{
	queue< pair<int, int>> que;

	
	int** arr;
	int turn;

	scanf("%d %d", &col, &row);
	//getchar();

	arr = new int*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	turn = calc(que, arr, row, col);

	printf("%d", turn);

}