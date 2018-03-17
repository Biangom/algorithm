// made by dragostea
// boj.kr/1790 수 이어쓰기 2

// j 자리의 길이

#include<iostream>
#include<cmath>

long long calc(long long n);
long long sum_part(int n);
long long multi_part(int n);
int wantJari(int n);
int check_k_placeJari(int k);
int play(int jari, long long value);
int devide(long long num, long long deci, long long value);

// deci 숫자 9, 99, 999 .... (9자리)까지의 수를 이어붙였을 때 길이를 저장
long long deci[10];

int main(void)
{
	int n;
	int n_jari; // 입력받은 n의 자리수
	int k_place_jari; // k는 어디자리에 위치하는지 => k는 k_place_jari번째자리수이다.
	int k_place_value; // k중에서 deci[k]를 뺀 값. 즉 그 이전자리수를 나열한 길이를 뺀값.
	int j; // n까지의 수를 이어붙였을 때 자리
	int k; // 자리의 길이중 몇번째

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
	// k 와 k가 해당하는 자리의 이전 자리수만큼 나열한 것을 다뺀다
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
	// n은 입력받은 수

	// temp_n은 n의 자리를 구하기 위한 임시 n
	// nj는 입력받은 수의 자리수
	// j는 이어쓴 수의 해답

	long long temp_n = n;
	int nj = 0;
	long long j = 0;

	// n의 자리수를 구하기 위한 루프
	// nj는 n의 자리수가 된다
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


long long sum_part(int nj)
{
	// nj는 입력받은 n이 몇자리인지.
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
	// 3자리수 일때부터 이 multi_part는 실행된다.
	for (int i = 3; i <= nj; i++)
	{
		x = x * 10 + 9;
	}
	return x;

}

// temp로 들어오는 수의 자리를 리턴
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

// 뺸값과 자리를 통해서
// 이제 위치하는 수를 구한다.
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
	//calc_deci = 해당하는 번째 숫자가 몇자리 숫자인지를 나타냄.
	calc_deci = (long long)pow(10, jari - 1);
	calc_num = calc_deci + count;

	// 이제 calc_num에 value 자리에 해당하는 숫자만 추출하면 된다.
	// 194 일때 1 = "1", 2 = "9", 3 = "4"

	// calc_num을 calc_deci로 나누면됀다. 해당하는 value값만큼 반복

	final_num = devide(calc_num, calc_deci, value);


	return final_num;
}


// value = 그 추출한 숫자에서 몇번쨰 자리인지
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