#include <iostream>
#include <queue>

using namespace std;

int ch[8] = {1,10,100,1000,-1,-10,-100,-1000};

queue<int> q;

int sosu[10000];
int visited[10000];

int sosucheck(int num){
    for(int i=2; i<=num; i++){
        for(int j=2; i*j<=num; j++){
            if(num % i*j == 0) return 0;
        }
    }
    return 1;
}

void bfs(){
    while(!q.empty()){
        int v = q.front();
        int vv;
        q.pop();
        for (int j = 0; j < 8; j++){
            for (int i = 1; i < 10; i++){
                int flag = 1;
                int n = v + i*ch[j];
                int nn = n/(ch[j%4]*10);
                vv = v/(ch[j%4]*10);
                //cout << nn << " " << vv << endl;
                if(nn%10 != vv%10) continue;
                if (n >= 1000 && n <= 9999 && sosu[n] == 1){
                    if (visited[n]==0){
                        visited[n] = visited[v] + 1;
                        q.push(n);
                        //cout << v << "->" << n <<  " " << visited[n] << endl;
                    }
                    else if (visited[n] > visited[v] + 1){
                        visited[n] = visited[v] + 1;
                        q.push(n);
                        //cout << v << "->" << n <<  " " << visited[n] << endl;
                    }
                }
            }
        }
    }
}

int main(){
    for(int i = 2; i < 10000; i++){
        sosu[i] = sosucheck(i);
    }
    int T; cin >> T;
    for (int i = 0; i < T; i++){
        int start, end; cin >> start >> end;
        fill_n(visited,10000,0);
        q.push(start);
        visited[start]=1;
        bfs();
        if (visited[end]==0) cout << "impossible" << endl;
        else cout << visited[end] - 1 << endl;
    }
}