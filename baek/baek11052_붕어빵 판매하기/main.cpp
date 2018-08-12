#include<stdio.h>
#include<algorithm>

using namespace std;

int main(void) {
	int num;
	int cost[1001] = { 0, }; // 각 물고기의 가격을 담는다.
	int opti[1001] = { 0, }; // 해당하는 최적의 가격을 담는다.
	
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		int input;
		scanf("%d", &input);
		cost[i] = input;
	}

	for (int i = 1; i <= num; i++) {
		opti[i] = cost[i]; // 초기 가장 최적화값을 물고기를 그 i개로 샀을 때로
		// 초기화한다. 이 배열값은 어차피 뒤에 나오는
		// 반복문에 의해서 비교 후 대입하여 다시 최적가격으로 대입될 예정이다.
		for (int j = 1; j <= i/2; j++) {
			// opti[i] 는 i개의 물고기 갯수로 최적의 가격을 저장하는 배열
			// opti[i]와 j개의 물고기 최적가격 + i -j개의 물고기 최적 가격을 비교하여
			// 더 큰 값을 opti[i]에 저장
			opti[i] = max(opti[i], opti[j]+opti[i - j]);
		}
	}
	printf("%d\n", opti[num]);
	return 0;
}