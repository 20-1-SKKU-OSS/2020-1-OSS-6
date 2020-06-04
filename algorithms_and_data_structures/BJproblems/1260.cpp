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
