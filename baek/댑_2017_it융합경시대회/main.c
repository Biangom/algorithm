#include<stdio.h>
int d[10001]; // ��� ���� 0, �����ѹ���� ����
int dn(int i) {
	int res = i;
	if (i >= 10000) { res += i / 10000; i %= 10000; }
	if (i >= 1000) { res += i / 1000; i %= 1000; }
	if (i >= 100) { res += i / 100; i %= 100; }
	if (i >= 10) { res += i / 10; i %= 10; }
	return res += i;
}
void main() {
	int input;
	scanf("%d", &input);
	for (int i = 1; i <= 10000; i++) {
		d[dn(i)] = 1; // 1�̸� �����ѹ� �ƴ�(NO�ѹ�)
	}

	if (d[input] == 0)
		printf("Self\n");
	else
		printf("No\n");
}