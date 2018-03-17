// made by dragostea
/*

동적계획법 기초 >> 숫자삼각형

*/

#include <iostream>
#include <cmath>

// 피라미드 index값이 유효한지 검사
bool isVaild(int** arr, int i, int j)
{
	// i의 값의 범위를 벗어나면 false를 출력
	if (i < 0 || arr[i][j] == -1)
		return false;
	return true;
}

// 피라미드 형태로 입력을 받는 함수
int insert(int** arr, int len)
{
	int i = 0;
	int limit = 2;
	int j = 0;
	int valLeft = 0, valRight = -1;
	int maxes = 0;
	int max = -1;

	scanf("%d",&arr[0][0]);

	for (i = 1; i < len; i++)
	{
		for (j = 0; j < limit; j++)
		{
			scanf("%d", &arr[i][j]);			

			// 각 왼쪽부모, 오른쪽 부모가 유효한지를 검사한다.
			// 유효한지를 검사했으면 각 방향 부모의 값을 담고
			// 그 부모와 자신에 더한 값 중 최댓값을
			// 자신에 초기화시킨다.
			if (isVaild(arr, i - 1, j - 1))
				valLeft = arr[i - 1][j - 1];
			else
				valLeft = -1;

			if (isVaild(arr, i - 1, j))
				valRight = arr[i - 1][j];
			else
				valRight = -1;
			maxes = fmax(valLeft + arr[i][j], valRight + arr[i][j]);
			arr[i][j] = maxes;

			// i 행의 마지막에 도달했다면
			// 마지막 중 최댓값을 골라 반환한다.
			if (i == len - 1)
			{
				if (arr[i][j] > max)
				{
					max = arr[i][j];
				}
			}

		}
		limit++;
	}
	return max;
}

int calc(int** arr, int len)
{
	int i, j;
	int limit = 1;


	for (i = 0; i < len; i++)
	{
		for (j = 0; j < limit; j++)
		{

		}
		limit++;
	}
	return 0;
}

int main(void)
{
	int input;
	int** arr;
	int i, j;
	int result;

	// 배열 초기화 단계
	scanf("%d", &input);
	arr = new int*[input];
	for (i = 0; i < input; i++)
	{
		arr[i] = new int[input];
		for (j = 0; j < input; j++)
		{
			arr[i][j] = -1;
		}
	}

	result = insert(arr, input);

	printf("%d ", result);

	return 0;
}