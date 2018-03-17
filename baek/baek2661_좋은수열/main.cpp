// https://letyarch.blogspot.kr/2016/10/2661.html?showComment=1503672843290#c6838271136448560767

#include <cstdio> 
#include <iostream>
#include <algorithm>

using namespace std;


int n, a['ae'];
// 'ae' = 24933


void dfs(int here)

{

	for (int i = 1; i <= here / 2; i++)

	{

		if (equal(a + here - i, a + here, a + here - i - i)) return;
		// equal(f1, l1, f2)�� f1�� l1���� �����ϴ� ���� f2�� ������ �� f1, f2�� ����Ų �� ������ ������ ���θ� ����
	}


	if (here == n)

	{

		for (int i = 0; i < n; i++)

			cout << a[i];

		cout << '\n';

		exit(0);

	}


	for (int candi = 1; candi <= 3; candi++)

	{

		a[here] = candi;

		dfs(here + 1);

	}

}


int main()

{

	cin >> n;

	dfs(0);

	return 0;

}