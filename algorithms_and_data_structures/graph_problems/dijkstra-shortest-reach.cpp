/**

 * 주어진 그래프는 N개의 노드(1에서 N)로 이루어져 있고 S는 시작 노드
 * 두 노드 사이의 엣지는 길이를 통해 주어짐, 다른 엣지의 길이와 같을수도 있고 다를수도 있음
 * 시작 노드와 다른 모든 노드사이의 최단거리를 구해야함
 * Note 1 : 노드가 갈 수 없는 노드라면 거리는 -1로 한다
 
 * 인풋
 * 첫 줄에는 T를 포함 -> 테스트 케이스의 숫자
 * 각 테스트 케이스의 첫 줄에는 두개의 integer N과 M -> N : 노드의 수, M : 엣지의 수
 * 다음 M개의 줄에는 세개의 인티저 x,y,w -> x, y : 엣지가 있는 두 노드, w : 두 노드 사이의 거리
 * 마지막 줄에는 인티저 S -> 시작 위치
 
 * 아웃풋
 * T개의 테스트 케이스 각각에 대해 시작점 S에서 각 노드에 도달하는 최단거리를 한줄에 N-1개의 ' '로 구분된 인티저들을 출력
 * 갈 수 없는 노드는 -1을 출력
 * 같은 노드쌍에 대해 다른 weight를 가진 엣지가 존재하면, 그는 multiple edges로 생각한다.
 
 * Given a graph consisting N nodes (labelled 1 to N) where a specific given node S represents the starting position S
 * and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.
 * It is required to calculate the shortest distance from the start position (Node S) to all of the other nodes in the graph.
 * Note 1: If a node is unreachable , the distance is assumed as −1.
 
 * Input Format
 * The first line contains T, denoting the number of test cases.
 * First line of each test case has two integers N, denoting the number of nodes in the graph and M,
 * denoting the number of edges in the graph.
 * The next M lines each consist of three space separated integers x y w, where x and y
 * denote the two nodes between which the undirected edge exists, w denotes the length of edge between these corrresponding nodes.
 * The last line has an integer S, denoting the starting position.
 *
 * Output Format
 * For each of the T test cases, Print a single line consisting N−1 space separated integers denoting
 * the shortest distance of N−1 nodes from starting position S. For unreachable nodes, print −1.
 *
 * If there are edges between the same pair of nodes with different weights,
 * they are to be considered as is, like multiple edges.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <climits>
#include <set>
using namespace std;

vector<int> dist;
 struct lstDist {
    bool operator()(int u, int v) const {
      return make_pair(dist[u], u) <  make_pair(dist[v], v);
    }
  };

class Graph {
  int N;
  vector<vector<int>> weights;
  int S;

  public:
    Graph( int n )
        : N{n}, weights(N, vector<int>(N, -1)){}

    void addEdge( int x, int y, int w) {
        if (weights[x-1][y-1] == -1 || (weights[x-1][y-1] != -1 && weights[x-1][y-1] > w )) {
            weights[x-1][y-1] = w;
            weights[y-1][x-1] = w;
        }
    }
    void setStart(int s) {
        S = s-1;
        dist[S] = 0;
    }

    void distance() {
        set<int, lstDist> q;
        q.insert(S);
        while(!q.empty()) {
            int u = *q.begin();
            q.erase(q.begin());
            for( int v = 0; v < N ; ++v ) {
               if (weights[u][v] != -1) {
                   int newDist = dist[u] + weights[u][v];
                   if (newDist < dist[v]) {
                       dist[v] = newDist;
                       if (q.count(v)) {
                           q.erase(v);
                       }
                       q.insert(v);
                   }
               }
            }
        }
    }

    void printDistance() {
        for ( unsigned  int i = 0; i < dist.size(); ++i ) {
            if ( int(i) != S) {
                if (dist[i] == INT_MAX) dist[i] = -1;
                std::cout << dist[i] << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int T, N, M, x, y, w, S;
    cin >> T;
    while( T ) {
        cin >> N >> M;
        dist.resize(N);
        for( int i = 0; i < N; ++i) {
            dist[i] = INT_MAX;
        }
        Graph G(N);
        for ( int i = 0; i < M; ++i) {
            cin >> x >> y >> w;
            G.addEdge(x, y, w);
        }
        cin >> S;
        G.setStart(S);
        G.distance();
        G.printDistance();
        --T;
    }
    return 0;
}

