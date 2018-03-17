// made by dragostea
// 카카오프로그래밍대회 2번문제 보행자천국
// 문제 : https://www.kakaocode.com/tryouts/1359/challenge_algorithm_codes/2778

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int MOD = 20170805;
int r, c, **v, **h;
vector<vector<int>> map;



bool check(int i, int j)
{
	return i >= 0 && i < r && j >= 0 && j < c;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	r = m, c = n;
	v = new int*[r], h = new int*[r];
	map = city_map;
	for (int i = 0; i < r; ++i) {
		v[i] = new int[c], h[i] = new int[c];
		memset(v[i], -1, sizeof(int) * c);
		memset(h[i], -1, sizeof(int) * c);
	}

	// 초기셋팅
	if (map[0][1] == 1 )
		v[0][0] = 0;
	else
		v[0][0] = 1;

	if (map[1][0] == 1)
		h[0][0] = 0;
	else
		h[0][0] = 1;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			

			// i,j일 때의 v와 h구하기
			// case 일직통행일때.
			if (map[i][j] == 2)
			{
				if (check(i - 1, j))	v[i][j] = v[i - 1][j] % MOD;
				else					v[i][j] = 0;


				if (check(i, j - 1))	h[i][j] = h[i][j - 1] % MOD;
				else					h[i][j] = 0;
			}
			// case 모든방향이 가능할 때
			else if (map[i][j] == 0)
			{
				if (check(i - 1, j) && check(i, j - 1))			h[i][j] = v[i][j] = (v[i - 1][j] + h[i][j - 1]) % MOD;
				else if (check(i - 1, j) && !check(i, j - 1))	h[i][j] = v[i][j] = v[i - 1][j] % MOD;
				else if (!check(i - 1, j) && check(i, j - 1))	h[i][j] = v[i][j] = h[i][j - 1] % MOD;


				
			}
			// case 통행 금지일 때
			else
			{
				h[i][j] = v[i][j] = 0;
			}
			
		}
	}

	return ( h[r - 1][c - 2] + v[r - 2][c - 1] ) % MOD;
}



int main(void)
{
	int m;
	int n;
	int input;

	vector<vector<int>> city_map;

	scanf("%d", &m);
	scanf("%d", &n);
	for (int i = 0; i < m; i++)
	{
		vector<int> element(n);
		city_map.push_back(element);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &input);
			city_map[i][j] = input;
		}
	}
	printf("%d", solution(m, n, city_map));


}