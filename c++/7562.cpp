#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

int visited[301][301];

void bfs(vector<pair<int, int> > start, vector<pair<int, int> > end, int l){
    queue<pair<int, int> > q;
    q.push(start.front());
    while(!q.empty()){
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++){
            int nextx = nx+dx[i];
            int nexty = ny+dy[i];
            if (nextx < l && nextx >= 0 && nexty < l && nexty >=0  && (visited[nextx][nexty] == 0 || visited[nextx][nexty] > visited[nx][ny] + 1)){
                q.push(pair<int,int>(nextx,nexty));
                visited[nextx][nexty] = visited[nx][ny]+1;
            }
        }
    }
}

int main(){
    int T; cin >> T;
    for (int i = 0; i< T; i++){
        int l; cin >> l;
        for(int j = 0; j < l; j++){
            fill_n(visited[j],301,0);
        }
        vector<pair<int, int> > start;
        vector<pair<int, int> > end;
        int a,b; cin >> a >> b;
        start.push_back(pair<int,int>(a,b));
        cin >> a >> b;
        end.push_back(pair<int, int>(a,b));
        bfs(start,end,l);
        if (start == end){
            cout << 0 << endl;
        }
        else{
            cout << visited[end.front().first][end.front().second] << endl;
        }
        
    }
}