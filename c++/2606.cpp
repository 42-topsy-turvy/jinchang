#include <iostream>
#include <vector>

using namespace std;


int cnt;
vector<int> graph[101];
int visited[101];

void dfs(int start){
    visited[start] = 1;
    for(int i=0; i<graph[start].size(); i++){
        int next = graph[start][i];
        if(!visited[next]){
            dfs(next);
            cnt+=1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int c,n;
    cin >> c;
    cin >> n;
    int s, e;
    fill_n(visited,c+1,0);
    for (int i = 0; i < n; i++){
        cin >> s;
        cin >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    dfs(1);
    cout << cnt;
}