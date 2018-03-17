// made by dragostea
// boj.kr/2293 ����1

#include <iostream>

#define MAX_SIZE 100
#define INF 0x7fffffff

using namespace std;

// coin[i] = i��° ������ ��
// dp[i] = i���϶��� ����Ǽ�
int coin[MAX_SIZE];
int dp[10001];

int main()
{
	// n = ������ ����							1<= n <= 100
	// k = �츮�� ���ϴ� k���� ����� ����Ǽ�	1<= k <= 10000
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

	dp[0] = 1;

	// ������ ���� ��ŭ �ݺ�
	// ��� ������ ��ġ��ŭ �ݺ��Ѵ�.
	for (int i = 0; i < n; i++)
	{
		// j=> 1~k���� ����� ����Ǽ��� ���ʷ� ���ϱ� ����
		for (int j = 1; j <= k; j++)
		{
			// j�� >= i���� ������ ��
			if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d\n", dp[k]);

	return 0;
}
