#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;



int bfs(int start, int N, vector<int> graph[101]){
    int visited[101] = {0,};
    int *num = new int[N+1];
    int sum = 0;
    fill_n(num,N+1,0);
    queue<int> q;
    visited[start] = 1; 
    q.push(start);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        while(!graph[v].empty()){
            int next = graph[v].back();
            graph[v].pop_back();
            if (!visited[next]){
                num[next] = num[v] + 1;
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    for (int i = 0; i< N+1; i++){ sum+=num[i];}
    cout << sum << endl;
    return sum;
}
int main(){
    int N, M; cin >> N >> M;
    vector<int> result[101];
    vector<int> graph[101];
    for (int i = 0; i<M; i++){
        int s, e; cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    int min = bfs(1, N,graph);
    int minnum = 1;
    int tmp;
    for (int i = 2; i <= N; i++ ){
        tmp = bfs(i,N,graph);
        if (tmp < min){ min = tmp;}
    }
    cout << tmp;
}