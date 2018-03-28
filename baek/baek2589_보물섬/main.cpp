/*
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW
-> 8

5 6
WLWWWW
WLLLLW
WWWWLL
WLLLLW
WWWWLL
-> 9
*/

#include<iostream>
#include<cstring>
#include<iomanip>
#include<queue>

#define MAX_SIZE 100

typedef struct data {
	int r = 0;
	int c = 0;
	int val = 0;
}DATA;

using namespace std;

queue<DATA> q;


char map[MAX_SIZE][MAX_SIZE];
int val[MAX_SIZE][MAX_SIZE];
char visit[MAX_SIZE][MAX_SIZE];

int unitStpath[MAX_SIZE][MAX_SIZE]; // �� �������� �ִܰŸ� ����

int input_r; // �迭����
int input_c;

int dir[4][2] = {
	{ 0 , 1 },
	{ 0 ,-1 },
	{ -1, 0 },
	{ 1 , 0 }
};

void getUnitStpath(int _r, int _c)
{
	int max = val[0][0];
	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
			if (val[i][j] > max)
				max = val[i][j];
		}
	}
	unitStpath[_r][_c] = max;
}

bool isVaild(int r, int c)
{
	return 0 <= r && 0 <= c && r < MAX_SIZE && c < MAX_SIZE;
}

void BFS(DATA firstData)
{
	q.push(firstData);

	visit[firstData.r][firstData.c] = 1;
	val[firstData.r][firstData.c] = firstData.val; // �� �� ���� �� �Ÿ� val�� �迭������ �ʱ�ȭ


												   // ť�� ��������� Ż��
	while (!q.empty()) {
		DATA data;
		data = q.front(), q.pop();

		for (int i = 0; i < 4; i++) {
			DATA temp;
			temp.r = data.r + dir[i][1];
			temp.c = data.c + dir[i][0];
			// �����¿��� ��ǥ�� �ӽ������� ���� ����
			//�����¿�� �� ��ǥ���� ��ȿ�ϰ�, ���� ���̰�, ���� �湮���� �ʾҴٸ� ��� ����
			if (isVaild(temp.r, temp.c) && map[temp.r][temp.c] == 1 && !visit[temp.r][temp.c]) {
				temp.val = data.val + 1;
				visit[temp.r][temp.c] = 1; // Ǫ���ҰŴϱ� �̹� �湮�Ѱ��̴�.
				val[temp.r][temp.c] = temp.val; // �� �� ���� �� �Ÿ� val�� �迭������ �ʱ�ȭ
				q.push(temp);
			}
		}
	}

	// �� �������� ���� ��ġ���� ���� �� �Ÿ��� unitStpath �迭�� �����Ѵ�.
	// ������ ���� unitStpath ���� �ٸ��Ƿ�, �������� ��ǥ�� �ش��ϴ� unitStpath�� �����Ѵ�.
	getUnitStpath(firstData.r, firstData.c);
	return;
}

int main(void)
{
	DATA start;
	int allPathMax; // �� ������ BFS �ִ� �߿����� �ִ�

	cin >> input_r;
	cin >> input_c;

	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
			char temp;
			cin >> temp;
			if (temp == 'L')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	// ��� ������ ���ؼ� BFS ����
	// �� �ƴ϶� ���� ����, �Ʒ�������, ��������, ������ ������ ���������� BFS�� �����Ѵ�.
	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
			if (map[i][j] == 1) {
				start.r = i;
				start.c = j;
				start.val = 0;
				BFS(start);

				for(int i = 0 ; i < input_r; i++) {
					memset(val[i], 0, input_c * sizeof(int));
					memset(visit[i], 0, input_c * sizeof(int));				
				}
			}

		}
	}
	allPathMax = unitStpath[0][0];
	for (int i = 0; i < input_r; i++) {
		for (int j = 0; j < input_c; j++) {
			if (unitStpath[i][j] > allPathMax)
				allPathMax = unitStpath[i][j];
		}
	}

	printf("%d", allPathMax);
	return 0;
}
