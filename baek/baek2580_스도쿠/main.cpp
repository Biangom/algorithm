// made by dragostea
// boj.kr/2580 스도쿠
// 참고 출처: http://ksj14.tistory.com/entry/BackJoon2580-스도쿠 [:: ENJOY ::]

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

			// map의 0의 좌표이면
			if (!map[i][j]) {
				p[idx].y = i; // 그 좌표들을 저장
				p[idx].x = j;
				idx++;
				// 차곡차곡 증가시킴
			}
			else {
				// 그게 아니라면, 입력받은 해당숫자를 1로 만든다.
				// 각각 네모, 행, 열 정보에 대한 숫자를 1로 만듬
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
	// 백트래킹
	// 리턴조건, 유망조건, 자식들어가기
	int i;
	int number[10] = { 0, };

	// 사이즈(이전에 ++했던) 것이 idx와 같아지면 리턴.(finish)
	if (flag)    return; // 리턴 조건1
	if (idx == size) {
		print();
		flag = 1;
		return; // // 리턴 조건2
	}

	// 없는 숫자들 체크
	for (i = 1; i < 10; i++) {
		number[i] = 1;

		if (nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i])   number[i] = 0;
		else if (horizon[p[idx].y][i])                    number[i] = 0;
		else if (vertical[p[idx].x][i])                   number[i] = 0;

		// 없는 숫자들이 몇개있는지 number[0]에 ++ 시킨다.
		if (number[i])        number[0]++;
	}

	// 없는 숫자들이 없다면, 완벽하다면 리턴.(finish) (자식으로 들어갈 필요가 없다)
	if (!number[0]) return; // 리턴 조건3


	// 백트래킹 입장
	for (i = 1; i < 10; i++) {

		// i에 해당하는 숫자가 없다면 (i가 없다면) 
		// number[i] i가 있으면 0, i가 없으면 1
		if (number[i]) {

			// 일단 1로만들고
			map[p[idx].y][p[idx].x] = i;
			nemo[3 * (p[idx].y / 3) + p[idx].x / 3][i] = 1;
			horizon[p[idx].y][i] = 1;
			vertical[p[idx].x][i] = 1;

			// 다음 빈 숫자로  ㄱㄱ
			process(idx + 1);

			//process가 여길 만났다는건
			// 해답을 구하지 못했다는 것이므로 다시 초기화.
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


