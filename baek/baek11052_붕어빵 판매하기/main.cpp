#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void) {
	int num;
	int cost[1001] = { 0, }; // �� ������� ������ ��´�.
	int opti[1001] = { 0, }; // �ش��ϴ� ������ ������ ��´�.
	
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		int input;
		scanf("%d", &input);
		cost[i] = input;
	}

	for (int i = 1; i <= num; i++) {
		opti[i] = cost[i]; // �ʱ� ���� ����ȭ���� ����⸦ �� i���� ���� ����
		// �ʱ�ȭ�Ѵ�. �� �迭���� ������ �ڿ� ������
		// �ݺ����� ���ؼ� �� �� �����Ͽ� �ٽ� ������������ ���Ե� �����̴�.
		for (int j = 1; j <= i/2; j++) {
			// opti[i] �� i���� ����� ������ ������ ������ �����ϴ� �迭
			// opti[i]�� j���� ����� �������� + i -j���� ����� ���� ������ ���Ͽ�
			// �� ū ���� opti[i]�� ����
			opti[i] = max(opti[i], opti[j]+opti[i - j]);
		}
	}
	printf("%d\n", opti[num]);
	return 0;
}