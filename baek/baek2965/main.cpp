
#include<stdio.h>

int main(void)
{
	int x, y, z;
	int d1, d2;
	int maxDis;
	scanf("%d %d %d", &x, &y, &z);

	d1 = z - y;
	d2 = y - x;

	if (d1 > d2)
		maxDis = d1;
	else
		maxDis = d2;
	printf("%d ", maxDis-1);
}