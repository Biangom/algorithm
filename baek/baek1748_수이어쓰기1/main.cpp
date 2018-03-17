// made by dragostea
// boj.kr/1748 수이어쓰기1

// 입력 n = 붙여쓸 1~n까지 숫자
// 원하는 답 j = 자리의 길이

#include<iostream>
#include<cmath>

int calc(int n);
int sum_part(int n);
int multi_part(int n);

int main(void)
{	
	int n;
	int sol;

	scanf("%d",&n);
	
	sol = calc(n);

	printf("%d", sol);
}

int calc(int n)
{
	// n은 입력받은 수

	// temp_n은 n의 자리를 구하기 위한 임시 n
	// nj는 입력받은 수의 자리수
	// j는 이어쓴 수의 해답
	
	int temp_n = n;
	int nj = 0;
	int j = 0;

	// n의 자리수를 구하기 위한 루프
	// nj는 n의 자리수가 된다
	while (temp_n > 0)
	{
		temp_n = int(temp_n / 10);
		nj++;
	}
	/*
	nj = 1  n = x    -> j = n
	nj = 2  n = xx   -> j = 9 +								( n - 9 ) * 2
	nj = 3  n = xxx  -> j = 9 + ( 9 * 20 ) +				( n - 99 ) * 3
	nj = 4  n = xxxx -> j = 9 + ( 9 * 20 ) + ( 9 * 300 ) +  ( n - 999 ) * 4

	결론

	k > 3

	nj = k  n = x..x(k개)  -> j = 
	
	9 +
	sig_i=2_k-1 { 9 * i * 10^i-1 } +
	{{start x = 9 }}
	{ n - [( x * 10) + 9] ( k - 2 반복) * k
	

	
	*/
	if (nj == 1) return j = n;
	else if (nj == 2) return j = 9 + (n - 9) * 2;
	else
	{
		j = 9 + sum_part(nj) + (n - multi_part(nj)) * nj;
	}
	return j;
}


int sum_part(int nj)
{
	// nj는 입력받은 n이 몇자리인지.
	int sum = 0;
	for (int i = 2; i <= nj - 1; i++)
	{
		sum += 9 * i * (int)pow(10, i - 1);
	}
	return sum;
}

int multi_part(int nj)
{
	int x = 9;
	// 3자리수 일때부터 이 multi_part는 실행된다.
	for (int i = 3; i <= nj; i++)
	{
		x = x * 10 + 9;
	}
	return x;

}