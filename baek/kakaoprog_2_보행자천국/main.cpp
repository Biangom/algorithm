#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int MOD = 20170805;
int r, c, **v, **h;
vector<vector<int>> map;

int dpv(int i, int j);
int dph(int i, int j);

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	r = m, c = n;
	v = new int* [r], h = new int* [r];
	map = city_map;
	for (int i = 0; i < r; ++i) {
		v[i] = new int[c], h[i] = new int[c];
		memset(v[i], -1, sizeof(int) * c);
		memset(h[i], -1, sizeof(int) * c);
	}

	answer = ( dpv(r - 2, c - 1) + dph(r - 1, c - 2) ) % MOD;
	cout << answer << '\n';
	return answer;
}
int dpv(int i, int j) {
	int &ret = v[i][j];
	if (ret != -1) return ret;
	if (i == r - 1) return ret = 0;
	if (i == 0 && j == 0) return ret = 1;

	int &pos = map[i][j];
	if (pos == 0) {
		if (i == 0) return ret = dph(i, j - 1) % MOD;
		if (j == 0) return ret = dpv(i - 1, j) % MOD;
		else		return ret = (dpv(i - 1, j) + dph(i, j - 1)) % MOD;
	}
	else if (pos == 1)	return ret = 0;
	else if (pos == 2) {
		if (i == 0)	return ret = 0;
		else		return ret = dpv(i - 1, j) % MOD;
	}
}
int dph(int i, int j) {
	int &ret = h[i][j];
	if (ret != -1) return ret;
	if (j == c - 1) return ret = 0;
	if (i == 0 && j == 0) return ret = 1;

	int &pos = map[i][j];
	if (pos == 0) {
		if (i == 0) return ret = dph(i, j - 1) % MOD;
		if (j == 0) return ret = dpv(i - 1, j) % MOD;
		else		return ret = (dpv(i - 1, j) + dph(i, j - 1)) % MOD;
	}
	else if (pos == 1)	return ret = 0;
	else if (pos == 2) {
		if (j == 0) return ret = 0;
		else		return ret = dph(i, j - 1) % MOD;
	}
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
		vector<int> element(m);
		city_map.push_back(element);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &input);
			city_map[i][j] = input;
		}
	}
	printf("%d", solution(m, n, city_map));
}