/*
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다.
정점 번호는 1번부터 N번까지이다.

인풋
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다.
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다.
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다.
입력으로 주어지는 간선은 양방향이다.

아웃풋
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int max1 = 1001;

int N, M, V;
int adj[max1][max1];
int visit[max1];
queue<int> q;


void dfs(int x) {
    cout << x <<" ";
    
    for (int i=1; i <= N; i++){
        if (adj[x][i] && !visit[i]){  
            //해당 행렬에 연결되어 있다고 나오고 아직 출력되지 않은 행렬이면 출력한다. 
            
            visit[i] = 1; // 방문했다고 표기
            //그리고 새로 출력된 정점에 연결된 새로운 정점이 있으면 출력하고 그렇지 않으면 마저 진행한다.            
            dfs(i);
            
        }
    }
    
}

void bfs(int x) {
    q.push(x); // 
    visit[x] = 1;  // 방문했다고 표기
    
    while(!q.empty()){  //큐가 모두 빌 때까지 진행
        x = q.front();  //변수에 현재 가장 먼저 탐색된 정점을 저장
        q.pop();  //그리고 삭제
        
        cout << x << " "; // 저장했던 정점을 출력
        
        for(int i=1; i<=N; i++){
            if(adj[x][i] && !visit[i]){
                //x와 인접한 정점 중 아직 방문하지 않은 정점을 큐에 저장
                q.push(i); // 아직 방문하지 않은, 새로 발견한 행렬의 위치를 저장
                visit[i] = 1; //방문여부 기록
                
            }
            
        }
        
    }
    
}


int main(void) {
    cin >> N >> M >> V;
    
    for (int i = 0; i < M; i++){   //행렬 만들기
        int a,b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    visit[V] = 1; // V에서 시작하니까
    dfs(V);
    cout << endl;
    
    memset(visit, false, sizeof(visit));
    bfs(V);
    cout <<endl;

     
    
}
