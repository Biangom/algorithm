// made by dragostea
// boj.kr/2293 동전1

#include <iostream>

#define MAX_SIZE 100
#define INF 0x7fffffff

using namespace std;

// coin[i] = i번째 코인의 값
// dp[i] = i원일때의 경우의수
int coin[MAX_SIZE];
int dp[10001];

int main()
{
	// n = 동전의 개수							1<= n <= 100
	// k = 우리가 원하는 k원을 만드는 경우의수	1<= k <= 10000
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);

	dp[0] = 1;

	// 동전의 개수 만큼 반복
	// 모든 동전의 가치만큼 반복한다.
	for (int i = 0; i < n; i++)
	{
		// j=> 1~k원을 만드는 경우의수를 차례로 구하기 위함
		for (int j = 1; j <= k; j++)
		{
			// j원 >= i번쨰 코인의 값
			if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d\n", dp[k]);

	return 0;
}
