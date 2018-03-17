
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
//입력
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
//출력
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
//	// 우선순위 큐, 우선순위가 높은 노드가 가장 top에 위치
//	// 우선순위가 높다는 것은 제일 거리가 최단 길이인 애가 위로 위치
//
//	// 시작점 빼고 최단거리를 전부 INF로 초기화
//	// 간선을 저장하는 큐
//	priority_queue<edg> pq;
//	for (int i = 0; i < v; ++i)
//		pq.push(edg(i, dst[i]));
//
//	// 이 코드로 인해 start지점으로 초기화했던게 top에 위치할 것이다.
//
//	// 이 반복으로 인해 dst 배열에 최단경로의 값이 들어가게 된다.
//	// pq를 이용하여 순회하면, 
//	while (!pq.empty()) {
//		edg now = pq.top(); pq.pop();
//
//		// 현재 꺼낸 노드의 거리와 최단경로가 다르면
//		// 교체구문을 실행하지 않는다.
//		// 처음에는 start인 번지만 실행하게 되어있다.
//
//		// 이구문은 현재 꺼낸 애가 edg가 최단경로 일때만
//		// 그 edg를 비롯한 주변애들과의 검색을 시작하여
//		// 또 다른 최단경로를 찾아보는 것이다.
//		if (now.dst > dst[now.idx]) continue;
//
//		/*
//		for (edg next : gph[now.idx])
//		*/
//
//
//		// << dst를 교체하는 구문>>
//		vector<edg>::const_iterator next;
//		for (next = gph[now.idx].begin(); next != gph[now.idx].end(); ++next)
//		{
//			// (*next).dst 의미 : gph[now.idx][0~n-1]까지의 거리.
//			// 즉 now.idx와 (0~n-1)idx의 거리
//			if (dst[(*next).idx] > now.dst + (*next).dst) {
//				dst[(*next).idx] = now.dst + (*next).dst;
//				// 그 거리를 pq에 넣어준다.
//				// 이 pq는 추후에 어떤 정점으로가는 최단길이인 애가
//				// 위에 위치하므로 이정보를 이용해서 다시 반복할 것이다.
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
