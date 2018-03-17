// made by dragostea
// boj.kr/1463 1�θ����

#include<iostream>
#include<cmath>

int d[1000001];

// � �� M�� �ּ� ������ ���ϰ� �ʹ�.
// �׸��� d[] �迭 ������ �ּ� ������ ���� ����ִٰ� ġ��.

// �׷� d[M]�� d[M-1] + 1, d[M/2] + 1, d[M/3] + 1

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