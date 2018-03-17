// made by dragostea
// boj.kr/1748 ���̾��1

// �Է� n = �ٿ��� 1~n���� ����
// ���ϴ� �� j = �ڸ��� ����

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
	// n�� �Է¹��� ��

	// temp_n�� n�� �ڸ��� ���ϱ� ���� �ӽ� n
	// nj�� �Է¹��� ���� �ڸ���
	// j�� �̾ ���� �ش�
	
	int temp_n = n;
	int nj = 0;
	int j = 0;

	// n�� �ڸ����� ���ϱ� ���� ����
	// nj�� n�� �ڸ����� �ȴ�
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

	���

	k > 3

	nj = k  n = x..x(k��)  -> j = 
	
	9 +
	sig_i=2_k-1 { 9 * i * 10^i-1 } +
	{{start x = 9 }}
	{ n - [( x * 10) + 9] ( k - 2 �ݺ�) * k
	

	
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
	// nj�� �Է¹��� n�� ���ڸ�����.
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
	// 3�ڸ��� �϶����� �� multi_part�� ����ȴ�.
	for (int i = 3; i <= nj; i++)
	{
		x = x * 10 + 9;
	}
	return x;

}