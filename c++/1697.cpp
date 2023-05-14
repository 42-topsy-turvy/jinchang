#include <iostream>
#include <queue>

using namespace std;

int visited[100001];

void bfs(int start, int end){
    queue<int> q;
    q.push(start);
    visited[start]=1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if (v+1 < 100001 && (visited[v+1] == 0 || visited[v]+1 < visited[v+1])){
            visited[v+1] = visited[v]+1;
            if(v+1 != end) q.push(v+1);
        }
        if (v-1 >=0 && (visited[v-1] == 0 || visited[v]+1 < visited[v-1])){
            visited[v-1] = visited[v]+1;
            if(v-1 != end) q.push(v-1);
        }
        if (2*v < 100001 && (visited[2*v] == 0 || visited[v]+1 < visited[2*v])){
            visited[2*v] = visited[v]+1;
            if(2*v != end) q.push(2*v);
        }
    }
}

int main(){
    int N,K; cin >> N >> K;
    bfs(N,K);
    cout << visited[K]-1;
}