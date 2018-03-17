// made by dragostea
// boj.kr/1463 1로만들기

#include<iostream>
#include<cmath>

int d[1000001];

// 어떤 수 M의 최소 연산을 구하고 싶다.
// 그리고 d[] 배열 값에는 최소 연산의 수가 들어있다고 치자.

// 그럼 d[M]은 d[M-1] + 1, d[M/2] + 1, d[M/3] + 1

int main(void)
{
	int input;
	scanf("%d", &input);
	d[1] = 0;

	for (int i = 2; i <= 1000000; i++)
	{
		
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
			d[i] = fmin( d[i], d[i / 2] + 1 );
		if (i % 3 == 0)
			d[i] = fmin( d[i], d[i / 3] + 1 );
	}
	printf("%d\n",d[input]);
}