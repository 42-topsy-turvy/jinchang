#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int graph[1001][1001];
queue<pair<int,int> > q;

void bfs(int x,int y){
    int date = 0;
    while(!q.empty()){
        int size = q.size();
        date++;
        for (int i = 0; i < size; i++){
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++){
                int nextx = nx + dx[j];
                int nexty = ny + dy[j];
                if (nextx >= 0 && nexty >= 0 && nextx < x && nexty < y && graph[nexty][nextx] == 0){
                    q.push(pair<int,int>(nextx,nexty));
                    graph[nexty][nextx] = 1;
                }
            }
        }
    }
    for (int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            if (graph[i][j]==0){
                cout << -1;
                return;
            }
        }
    }
    cout << date-1;
}

int main(){
    int M,N; cin >> M >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 1) q.push(pair<int, int>(j,i));
        }
    }
    bfs(M,N);
}