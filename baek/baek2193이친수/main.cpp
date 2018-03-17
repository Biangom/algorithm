// made by dragostea
// boj.kr/2193 이친수

#include <iostream>

unsigned long long dp[91][2];
// 첫번째요소 : 자리수
// 두번째요소 : 그 자리의 마지막에 해당하는 숫자 0,과 1의 갯수

void init()
{
	dp[1][1] = 1;
	dp[2][0] = 1;
	// 나머진 0
}


// g(n,x)를 n자리 숫자에서 x로 끝나는 갯수라고 하자.
// 그 다음의 g(n,0)은 g(n-1,0) + g(n-1,1)이다.
// g(n,1)은 g(n-1,0)이다.

unsigned long long calc(int input)
{

	for (int i = 3; i <= input; i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	return dp[input][0] + dp[input][1];
}

int main(void)
{
	int input;
	unsigned long long result;
	scanf("%d", &input);

	init();

	result = calc(input);

	printf("%lld", result);
}