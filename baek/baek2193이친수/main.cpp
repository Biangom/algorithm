// made by dragostea
// boj.kr/2193 ��ģ��

#include <iostream>

unsigned long long dp[91][2];
// ù��°��� : �ڸ���
// �ι�°��� : �� �ڸ��� �������� �ش��ϴ� ���� 0,�� 1�� ����

void init()
{
	dp[1][1] = 1;
	dp[2][0] = 1;
	// ������ 0
}


// g(n,x)�� n�ڸ� ���ڿ��� x�� ������ ������� ����.
// �� ������ g(n,0)�� g(n-1,0) + g(n-1,1)�̴�.
// g(n,1)�� g(n-1,0)�̴�.

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