//made by dragostea
//boj.kr/9663 N-Queen
// http://hsp1116.tistory.com/17

/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
*/

// a(i) i번째 행에서 여왕말이 놓여 있는 열

#include<iostream>
#include<cmath>

int n, a[15];
int cnt;

using namespace std;


//이 위치에 여왕말을 놓을 수 있는지, 유망한지 체크


bool check(int cur) {

	// 그 새로들어온 아이 cur 까지
	// 모든 i에 적합한지를 체크한다.
	for (int i = 0; i < cur; i++) {
		// 열에 같은 것이 있거나, 대각선 범위 내에 있으면 불가능한 경우이므로
		// false반환.
		if (a[i] == a[cur] || cur - i == abs(a[cur] - a[i])) {
			return false;
		}
	}
	return true;
}

// nqueen 함수
// cnt를 통해 가능한 횟수가 몇번이나 있는지 체크한다.
// cur는 인덱스
void nqueen(int cur) {

	// 기저사례
	// 끝에 도달하였으면 카운터를 증가시키고 반환한다.
	if (cur == n - 1) {
		cnt++;
		return;
	}

	// 아직 끝에 도달하지 않앗으면 다음 위치를 찾는다.
	// i 는 열 index를 계속 반복
	for (int i = 0; i < n; i++) {
		a[cur + 1] = i;
		// 이 위치가 유망한지 검사, check이 참이면 다음 여왕 말을 찾고,
		// 못 찾으면 백트래킹한다.
		if (check(cur + 1)) {
			// 다음열 nqueen func 시작
			nqueen(cur + 1);
		}
	}
}


int main() {

	cnt = 0;
	scanf("%d", &n);
	// 열을 0부터 시작하기위함
	nqueen(-1);
	printf("%d\n", cnt);
}