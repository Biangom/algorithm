// made by dragostea
// boj.kr/14501 ���

#include<iostream>
#include<cmath>

using namespace std;

// n�� �ϼ� 
int n, capacity;
int day[100], need[100];
int cache[1001][100];
string name[100];

//ĳ��� ���� �뷮�� capacity�� ��, item ������ ���ǵ���
//��� ���� �� �ִ� �ִ� ��ġ�� ���� ��ȯ�Ѵ�.
int pack(int capacity, int item)
{
	//������� : �� ���� ������ ���� ��
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;

	//�� ������ ���� ���� ���
	ret = pack(capacity, item + 1);
	//�� ������ ���� ���
	if (capacity >= day[item])
		ret = fmax(ret, pack(capacity - day[item], item + 1) + need[item]);
	return ret;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &day[i], &need[i]);
	}
	
	printf("%d", pack(0, 0));


}

/*

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, dp[16], t[16], p[16];

//dp[n] n�� �϶� �ִ� ��ġ
// t[i] i���� ��� �ɸ��� ��
// p[i] i���� ����� ��ġ


//ĳ��� ���� �뷮�� capacity�� ��, item ������ ���ǵ���
//��� ���� �� �ִ� �ִ� ��ġ�� ���� ��ȯ�Ѵ�.
int func(int pos) {
	if (pos == n + 1)return 0;
	if (pos > n + 1)return -987654321;
	int &ret = dp[pos];

	if (ret != -1)return ret;
	// if(ret == -1)
	return ret = max(func(pos + 1), func(pos + t[pos]) + p[pos]);
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &t[i], &p[i]);
	printf("%d\n", func(1));
	return 0;
}
*/