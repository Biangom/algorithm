//made by dragostea
//boj.kr/9663 N-Queen
// http://hsp1116.tistory.com/17

/*
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.
N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

// a(i) i��° �࿡�� ���ո��� ���� �ִ� ��

#include<iostream>
#include<cmath>

int n, a[15];
int cnt;

using namespace std;


//�� ��ġ�� ���ո��� ���� �� �ִ���, �������� üũ


bool check(int cur) {

	// �� ���ε��� ���� cur ����
	// ��� i�� ���������� üũ�Ѵ�.
	for (int i = 0; i < cur; i++) {
		// ���� ���� ���� �ְų�, �밢�� ���� ���� ������ �Ұ����� ����̹Ƿ�
		// false��ȯ.
		if (a[i] == a[cur] || cur - i == abs(a[cur] - a[i])) {
			return false;
		}
	}
	return true;
}

// nqueen �Լ�
// cnt�� ���� ������ Ƚ���� ����̳� �ִ��� üũ�Ѵ�.
// cur�� �ε���
void nqueen(int cur) {

	// �������
	// ���� �����Ͽ����� ī���͸� ������Ű�� ��ȯ�Ѵ�.
	if (cur == n - 1) {
		cnt++;
		return;
	}

	// ���� ���� �������� �ʾ����� ���� ��ġ�� ã�´�.
	// i �� �� index�� ��� �ݺ�
	for (int i = 0; i < n; i++) {
		a[cur + 1] = i;
		// �� ��ġ�� �������� �˻�, check�� ���̸� ���� ���� ���� ã��,
		// �� ã���� ��Ʈ��ŷ�Ѵ�.
		if (check(cur + 1)) {
			// ������ nqueen func ����
			nqueen(cur + 1);
		}
	}
}


int main() {

	cnt = 0;
	scanf("%d", &n);
	// ���� 0���� �����ϱ�����
	nqueen(-1);
	printf("%d\n", cnt);
}