// made by dragostea
/*

계단수문제

*/


/*
0 1 1
1 1 3 6
1 2 4 7
1 2 4 8
1 2 4 8
1 2 4 8
1 2 4 8
1 2 4 7
1 2 3 6
1 1 2 3



https://www.acmicpc.net/board/view/5434

9876543210에 방문한 애들을 표기하는 겁니다. 안했으면 0 방문했으면 1 다시방문해도 계속 1인거죠.
만약 3, 2, 1을 방문했다고 하면 0000001110으로 표현할 수 있습니다.
이는 2진수니까 이를 10진수로 표현하면 2+4+8=14가 되겠죠

그럼 이걸 왜 활용하냐면 |(or연산)의 경우 0|1이면 1이잖아요
그러니까 다음에 들어오는 숫자와 지금까지 방문한 정보를 비트로 저장해서 서로 or 연산해버리면
방문한 정보를 담고 있을 수 있게됩니다.

비트가 0부터 9까지 10개 필요하니까 2^10=1024로 나타낼 수 있는거죠.
그리고 14라는 숫자가 표현하는게 2, 4, 8을 방문했다는 유일한 정보입니다.
즉, 14라는 숫자는 다른 2,4,8말고 다른 숫자를 방문했다는 정보를 가질 수가 없죠..

d[n][x][a] = n이라는 길이의 계단수 맨 마지막 숫자가 x로 끝날때 a라는 비트 정보를 가지고 있는 방법의 수
d[n][x][bit|x] += d[n-1][x-1][bit]
이런식으로 bit가 가질 수 있는 모든 수 1, 3(1+2), 7(1+2+4), 15(1+2+4+8+...), ... 즉 10개의 수에 대해서만 체크해줍니다. (반복문 10번 돌리면 될 듯)





*/

#include<iostream>


int arr[10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int result[10] = { 0 };



int sum()
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += arr[i];
		if (sum > 1000000000)
			sum %= 1000000000;
	}
	return sum;
}



// n자리의 계단 수를 구한다.
int calc(int n)
{
	int i, k;

	for (i = 2; i <= n; i++)
	{
		result[0] = arr[1];
		for (k = 1; k < 9; k++)
		{
			result[k] = arr[k - 1] + arr[k + 1];
		}
		result[9] = arr[8];


		for (k = 0; k < 10; k++)
		{
			if (result[k] > 1000000000)
			{
				result[k] %= 1000000000;
			}
			arr[k] = result[k];
		}
	}

	return sum();
}


int main(void)
{
	int input, result;
	int sum = 0;

	scanf("%d",&input);

	result = calc(input);

	/*
	for (int i = 1; i < 40; i++)
	{
		
		sum += calc(i + 1);

	}
	*/

	printf("%d ",result);
}
