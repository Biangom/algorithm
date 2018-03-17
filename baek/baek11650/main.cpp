// made by dragostea
// boj.kr/11650 좌표정렬하기
// http://codersbrunch.blogspot.kr/2016/12/11650.html

#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> p[100000];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p + n);
	for (int i = 0; i < n; i++) printf("%d %d\n", p[i].first, p[i].second);
	return 0;
}