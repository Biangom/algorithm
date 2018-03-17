// made by dragostea
// boj.kr/2580 ������
// ���� ��ó: http://ksj14.tistory.com/entry/BackJoon2580-������ [:: ENJOY ::]

#include <stdio.h>

typedef struct point {
	int x; // col
	int y; // row
}POINT;

POINT p[90];
int size;
int nemo[9][10];
int horizon[9][10];
int vertical[9][10];
int map[9][9];
int flag;

void input()
{
	int i, j;
	int idx = 0;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);

			// map�� 0�� ��ǥ�̸�
			if (!map[i][j]) {
				p[idx].y = i; // �� ��ǥ���� ����
				p[idx].x = j;
				idx++;
				// �������� ������Ŵ
			}
			else {
				// �װ� �ƴ϶��, �Է¹��� �ش���ڸ� 1�� �����.
				// ���� �׸�, ��, �� ������ ���� ���ڸ� 1�� ����
				nemo[3 * (i / 3) + (j / 3)][map[i][j]] = 1;
				horizon[i][map[i][j]] = 1;
				vertical[j][map[i][j]] = 1;
			}
		}
	}

	size = idx;
}

void print()
{
	int i, j;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void process(int idx)
{
	// ��Ʈ��ŷ
	// ��������, ��������, �ڽĵ���
	int i;
	int number[10] = { 0, };

	// ������(������ ++�ߴ�) ���� idx�� �������� ����.(finish)
	if (flag)    return; // ���� ����1
	if (idx == size) {
		print();
		flag = 1;
		return; // // ���� ����2
	}

	// ���� ���ڵ� üũ
	for (i = 1; i < 10; i++) {
		number[i] = 1;

		if (nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i])   number[i] = 0;
		else if (horizon[p[idx].y][i])                    number[i] = 0;
		else if (vertical[p[idx].x][i])                   number[i] = 0;

		// ���� ���ڵ��� ��ִ��� number[0]�� ++ ��Ų��.
		if (number[i])        number[0]++;
	}

	// ���� ���ڵ��� ���ٸ�, �Ϻ��ϴٸ� ����.(finish) (�ڽ����� �� �ʿ䰡 ����)
	if (!number[0]) return; // ���� ����3


	// ��Ʈ��ŷ ����
	for (i = 1; i < 10; i++) {

		// i�� �ش��ϴ� ���ڰ� ���ٸ� (i�� ���ٸ�) 
		// number[i] i�� ������ 0, i�� ������ 1
		if (number[i]) {

			// �ϴ� 1�θ����
			map[p[idx].y][p[idx].x] = i;
			nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i] = 1;
			horizon[p[idx].y][i] = 1;
			vertical[p[idx].x][i] = 1;

			// ���� �� ���ڷ�  ����
			process(idx + 1);

			//process�� ���� �����ٴ°�
			// �ش��� ������ ���ߴٴ� ���̹Ƿ� �ٽ� �ʱ�ȭ.
			nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i] = 0;
			vertical[p[idx].x][i] = 0;
			horizon[p[idx].y][i] = 0;
			map[p[idx].y][p[idx].x] = 0;
		}
	}
}

int main()
{
	input();

	process(0);

	return 0;
}


