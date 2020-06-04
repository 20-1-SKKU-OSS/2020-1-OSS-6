/*
kruskal's algorithm에 priority queue를 적용시켜 time complexity를 낮춤
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#pragma warning(disable:4996)

const int INF = 987654321;

typedef struct Edge {
  int s, t, w;
  Edge(int _s, int _t, int _w) : s(_s), t(_t), w(_w) {}
};

struct Disjoint {
  int dis[100];
  int rank[100];
  
  Disjoint() {
    memset(rank, 0, sizeof(rank));
    for (int i = 0; i < 100; ++i)
      dis[i] = i;
  }
  
  int find(int s) {
    if (dis[s] == s) return s;
    else return dis[s] = find(dis[s]);
  }
  
  void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
      dis[a] = b;
    }
    else if (rank[a] > rank[b]) {
      dis[b] = a;
    }
    else {
      dis[a] = b;
      rank[b]++;
    }
  }
};

int main(void) {
  int N, M;
  cin >> N >> M;
  
  // 그래프 행렬 초기화
  Disjoint disj;
  auto comp = [](const Edge& a, const Edge& b) {
    return a.w > b.w;
  };
  
  priority_queue< Edge, vector<Edge>, decltype(comp)> pq(comp);
  
  for (int m = 0, a, b, c; m < M; ++m) {
    cin >> a >> b >> c;
    pq.push(Edge(a, b, c));
  }
  
  int cnt = 1;
  int ret = 0;
  
  while (!pq.empty()) {
    Edge e = pq.top(); pq.pop();
    if (disj.find(e.s) == disj.find(e.t)) continue;
    ret += e.w;
    cnt++;
    if (cnt == N) break;
  }
  
  cout << ret << endl;
}














