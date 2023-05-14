#include <iostream>
#include <queue>
#include <algorithm>

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

using namespace std;
queue<pair<int,int> > q;

int bfs(int graph[25][25], int i, int j, int N){
    q.push(pair<int,int>(i,j));
    graph[i][j] = 0;
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
            if (graph[nx][ny] == 1){
                graph[nx][ny] = 0;
                q.push(pair<int,int>(nx,ny));
                cnt+=1;
            }
        }
    }
    return cnt;
}

int main(){
    int N; cin >> N;
    int graph[25][25];
    vector<int> cnt;
    for (int i = 0; i < N; i++){
        string n; cin >> n;
        for (int j = 0; j < N; j++){
            graph[i][j] = (int)n[j] - '0';
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(graph[i][j]==1){
                cnt.push_back(bfs(graph,i,j,N));
            }
        }
    }
    sort(cnt.begin(),cnt.end());
    cout << cnt.size() << endl;
    for (int i = 0; i < cnt.size(); i++){
        cout << cnt[i] << endl;
    }
}