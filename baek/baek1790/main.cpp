// made by dragostea
// boj.kr/1790 �� �̾�� 2

// j �ڸ��� ����

#include<iostream>
#include<cmath>

long long calc(long long n);
long long sum_part(int n);
long long multi_part(int n);
int wantJari(int n);
int check_k_placeJari(int k);
int play(int jari, long long value);
int devide(long long num, long long deci, long long value);

// deci ���� 9, 99, 999 .... (9�ڸ�)������ ���� �̾�ٿ��� �� ���̸� ����
long long deci[10];

int main(void)
{
	int n;
	int n_jari; // �Է¹��� n�� �ڸ���
	int k_place_jari; // k�� ����ڸ��� ��ġ�ϴ��� => k�� k_place_jari��°�ڸ����̴�.
	int k_place_value; // k�߿��� deci[k]�� �� ��. �� �� �����ڸ����� ������ ���̸� ����.
	int j; // n������ ���� �̾�ٿ��� �� �ڸ�
	int k; // �ڸ��� ������ ���°

	int result;
	

	scanf("%d", &n);
	scanf("%d", &k);

	n_jari = wantJari(n);
	//printf("%d\n",n_jari);

	deci[1] = 9;
	deci[2] = 189;

	for (int i = 3; i <= 9; i++)
	{
		long long r = multi_part(i+1);
		deci[i] = calc(r);
		//printf("%d\n", deci[i]);
	}

	k_place_jari = check_k_placeJari(k);
	// k �� k�� �ش��ϴ� �ڸ��� ���� �ڸ�����ŭ ������ ���� �ٻ���
	k_place_value = k - deci[k_place_jari - 1];


	printf("%d\n", k_place_jari);
	printf("%d\n", k_place_value);

	result = play(k_place_jari, k_place_value);

	printf("%d\n", result);
	
	printf("%lld\n", deci[1]);
	printf("%lld\n", deci[2]);
	printf("%lld\n", deci[3]);
	printf("%lld\n", deci[4]);
	printf("%lld\n", deci[5]);
	printf("%lld\n", deci[6]);
	printf("%lld\n", deci[7]);
	printf("%lld\n", deci[8]);
	printf("%lld\n", deci[9]);
	
	
}

long long calc(long long n)
{
	// n�� �Է¹��� ��

	// temp_n�� n�� �ڸ��� ���ϱ� ���� �ӽ� n
	// nj�� �Է¹��� ���� �ڸ���
	// j�� �̾ ���� �ش�

	long long temp_n = n;
	int nj = 0;
	long long j = 0;

	// n�� �ڸ����� ���ϱ� ���� ����
	// nj�� n�� �ڸ����� �ȴ�
	while (temp_n > 0)
	{
		temp_n = long long(temp_n / 10);
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


long long sum_part(int nj)
{
	// nj�� �Է¹��� n�� ���ڸ�����.
	long long sum = 0;
	for (int i = 2; i <= nj - 1; i++)
	{
		sum += 9 * i * (long long)pow(10, i - 1);
	}
	return sum;
}

long long multi_part(int nj)
{
	long long x = 9;
	// 3�ڸ��� �϶����� �� multi_part�� ����ȴ�.
	for (int i = 3; i <= nj; i++)
	{
		x = x * 10 + 9;
	}
	return x;

}

// temp�� ������ ���� �ڸ��� ����
int wantJari(int temp)
{
	int n = 0;
	while (temp > 0)
	{
		temp = int(temp / 10);
		n++;
	}
	return n;
}

int check_k_placeJari(int k)
{
	int placeJari = 1;
	for (int i = 1; i <= 10; i++)
	{
		if (k > deci[i])
		{
			placeJari = i + 1;
		}
		else
			break;
	}
	return placeJari;

}

// �A���� �ڸ��� ���ؼ�
// ���� ��ġ�ϴ� ���� ���Ѵ�.
int play(int jari, long long value)
{
	long long count = 0;
	long long calc_deci = 0;
	long long calc_num = 0;

	long long final_num = 0;
	for (long long i = 0; value > jari; i++)
	{
		value -= jari;
		count++;
	}
	//calc_deci = �ش��ϴ� ��° ���ڰ� ���ڸ� ���������� ��Ÿ��.
	calc_deci = (long long)pow(10, jari - 1);
	calc_num = calc_deci + count;

	// ���� calc_num�� value �ڸ��� �ش��ϴ� ���ڸ� �����ϸ� �ȴ�.
	// 194 �϶� 1 = "1", 2 = "9", 3 = "4"

	// calc_num�� calc_deci�� ������´�. �ش��ϴ� value����ŭ �ݺ�

	final_num = devide(calc_num, calc_deci, value);


	return final_num;
}


// value = �� ������ ���ڿ��� ����� �ڸ�����
int devide(long long num, long long deci, long long value)
{
	long long result;
	for (long long i = 1; i <= value; i++)
	{
		result = num / deci;
		num = num - deci;
		deci = deci / 10;
	}
	return result;

}