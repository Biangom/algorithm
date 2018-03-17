// made by 김찬효


#include <iostream>
#include <queue>
#define SIZE 1000

using namespace std;

bool chkAns();
bool validLoc(int x, int y);


queue<pair<int, int>> src;   // src == source
int map[SIZE][SIZE];
int dir[4][2] = {
	{0, 1}, {0, -1},
	{1, 0}, {-1, 0}
};

int mx, my;   // max size(bound)

int main() {
	cin.sync_with_stdio(false);
	cin >> mx >> my;

	int temp;
	for (int y = 0; y < my; ++y) {
		for (int x = 0; x < mx; ++x) {
			cin >> temp;
			map[y][x] = temp;
			if (temp == 1) src.push(make_pair(x, y));
		}
	}
	int day = 0;   // day == ans
	int& ans = day;
	
	// 모두다 1이면 이 무한루프를 탈출한다.
	while (true) {
		bfs();
		if (src.empty()) {
			if (chkAns())
				break;
			day = -1;
			break;
		}
		++day;
	}


	cout << ans;

	return 0;
}

bool chkAns() {
	for (int x = 0; x < mx; ++x)
		for (int y = 0; y < my; ++y)
			if (map[y][x] == 0) return false; 
	return true;
}
bool validLoc(int x, int y) {
	return (map[y][x] != -1 && (0 <= x && x < mx) && (0 <= y && y < my));
}
void bfs() {

	queue<pair<int, int>> result;

	// src큐에 남아있다면
	while (!src.empty()) {
		pair<int, int> pos = src.front();
		int x = pos.first, y = pos.second;
		src.pop();
		for (int i = 0; i < 4; ++i) {
			int tx = x + dir[i][0], ty = y + dir[i][1];

			// 1이아니고, -1도아니고, (0이면) 범위안에 맞은면 담는다.
			if (validLoc(tx, ty) && map[ty][tx] != 1) {
				map[ty][tx] = 1;
				result.push(make_pair(tx, ty));
			}
		}
	}
	src = result;
}