#include <iostream>
#include <string>
#include <queue>
using namespace std;

int visited[101][101];
int graph[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int sx, int sy){
    queue<pair<int,int> > q;
    q.push(pair<int,int>(sx,sy));
    visited[sx][sy] = 1;
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for (int i = 0; i< 4; i++){
            if (nx + dx[i] < 101 && nx + dx[i] >= 0 && ny + dy[i] < 101 && ny + dy[i] >= 0 && (visited[nx+dx[i]][ny+dy[i]]==0 || visited[nx+dx[i]][ny+dy[i]] > visited[nx][ny]+1)){
                if (graph[nx+dx[i]][ny+dy[i]]==1){
                    q.push(pair<int,int>(nx+dx[i],ny+dy[i]));
                    visited[nx+dx[i]][ny+dy[i]] = visited[nx][ny] + 1;
                }
            }
        }
    }
}

int main(){
    int N,M; cin >> N >> M;
    string num;
    for (int i = 0; i < N; i++){
        cin >> num;
        for (int j = 0; j < M; j++){
            graph[i][j] = num[j] - '0';
        }
    }
    bfs(0,0);
    cout << visited[N-1][M-1];
}