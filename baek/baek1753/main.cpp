
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

#define _v 2001
#define INF 2000000


int vcount, ecount;
int start;

vector<ev> gmap[_v];



struct ev {
	int idx;
	int dst;
	ev() {}
	ev(int vidx, int vdst) {
		idx = vidx;
		dst = vdst;
	}

	bool operator <(ev A) { return dst > A.dst; }

};


int input()
{
	int i;
	int in1, in2, in3;
	scanf("%d %d", &vcount, &ecount);
	scanf("%d", &start);
	for (i = 0; i < vcount; i++) {
		scanf("%d %d %d", &in1, &in2, &in3);
		gmap[in1].push_back(ev(in2, in3));
	}

}

int main(void)
{
	input();
	

}

































//
//// made by http://wookje.dance/2017/02/14/boj-1753-%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C/
//
//#include <stdio.h>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//
//const int v_ = 20000 + 1;
//const int INF = 987654321;
//
///*
//
//�Է�
//
//5 6
//1
//5 1 1
//1 2 2
//1 3 3
//2 3 4
//2 4 5
//3 4 6
//
//
//
//���
//
//0
//2
//3
//7
//INF
//
//*/
//
//struct edg {
//	int idx, dst;
//	edg() {}
//	edg(int idx, int dst) : idx(idx), dst(dst) {}
//	bool operator <(edg A)const { return dst > A.dst; }
//};
//
//int v, e, s, dst[v_];
//vector<edg> gph[v_];
//
//void dijkstra() {
//	for (int i = 0; i < v; ++i) dst[i] = INF;
//	dst[s] = 0;
//
//	// �켱���� ť, �켱������ ���� ��尡 ���� top�� ��ġ
//	// �켱������ ���ٴ� ���� ���� �Ÿ��� �ִ� ������ �ְ� ���� ��ġ
//
//	// ������ ���� �ִܰŸ��� ���� INF�� �ʱ�ȭ
//	// ������ �����ϴ� ť
//	priority_queue<edg> pq;
//	for (int i = 0; i < v; ++i)
//		pq.push(edg(i, dst[i]));
//
//	// �� �ڵ�� ���� start�������� �ʱ�ȭ�ߴ��� top�� ��ġ�� ���̴�.
//
//	// �� �ݺ����� ���� dst �迭�� �ִܰ���� ���� ���� �ȴ�.
//	// pq�� �̿��Ͽ� ��ȸ�ϸ�, 
//	while (!pq.empty()) {
//		edg now = pq.top(); pq.pop();
//
//		// ���� ���� ����� �Ÿ��� �ִܰ�ΰ� �ٸ���
//		// ��ü������ �������� �ʴ´�.
//		// ó������ start�� ������ �����ϰ� �Ǿ��ִ�.
//
//		// �̱����� ���� ���� �ְ� edg�� �ִܰ�� �϶���
//		// �� edg�� ����� �ֺ��ֵ���� �˻��� �����Ͽ�
//		// �� �ٸ� �ִܰ�θ� ã�ƺ��� ���̴�.
//		if (now.dst > dst[now.idx]) continue;
//
//		/*
//		for (edg next : gph[now.idx])
//		*/
//
//
//		// << dst�� ��ü�ϴ� ����>>
//		vector<edg>::const_iterator next;
//		for (next = gph[now.idx].begin(); next != gph[now.idx].end(); ++next)
//		{
//			// (*next).dst �ǹ� : gph[now.idx][0~n-1]������ �Ÿ�.
//			// �� now.idx�� (0~n-1)idx�� �Ÿ�
//			if (dst[(*next).idx] > now.dst + (*next).dst) {
//				dst[(*next).idx] = now.dst + (*next).dst;
//				// �� �Ÿ��� pq�� �־��ش�.
//				// �� pq�� ���Ŀ� � �������ΰ��� �ִܱ����� �ְ�
//				// ���� ��ġ�ϹǷ� �������� �̿��ؼ� �ٽ� �ݺ��� ���̴�.
//				pq.push(edg((*next).idx, dst[(*next).idx]));
//			}
//		}
//	}
//}
//
//int main() {
//	scanf("%d %d", &v, &e);
//	scanf("%d", &s); --s;
//
//	for (int i = 0; i < e; ++i) {
//		int u, v, w;
//		scanf("%d %d %d", &u, &v, &w);
//		--u, --v;
//		gph[u].push_back(edg(v, w));
//	}
//
//	dijkstra();
//
//	for (int i = 0; i < v; ++i) {
//		dst[i] != INF ? printf("%d", dst[i]) : printf("INF");
//		printf("\n");
//	}
//
//	return 0;
//}
