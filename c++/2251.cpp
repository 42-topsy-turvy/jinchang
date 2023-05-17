#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define DPAIR pair<pair<int,int>,int>
#define IPAIR(x,y) pair<int,int>(x,y)

using namespace std;

int visited[201][201][201];
queue<DPAIR > q;
vector<int> result;

int A,B,C;

void bfs(){
    while(!q.empty()){
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        if (visited[a][b][c] == 1) continue;
        visited[a][b][c] = 1;

        if (a == 0) result.push_back(c);

        if (a + b > B) q.push(DPAIR(IPAIR(a+b-B,B),c));
        else q.push(DPAIR(IPAIR(0,a+b),c));
        if (a + b > A) q.push(DPAIR(IPAIR(A,a+b-A),c));
        else q.push(DPAIR(IPAIR(a+b,0),c));
        if (a + c > C) q.push(DPAIR(IPAIR(a+c-C,b),C));
        else q.push(DPAIR(IPAIR(0,b),a+c));
        if (a + c > A) q.push(DPAIR(IPAIR(A,b),a+c-A));
        else q.push(DPAIR(IPAIR(a+c,b),0));
        if (b + c > C) q.push(DPAIR(IPAIR(a,b+c-C),b+c));
        else q.push(DPAIR(IPAIR(a,0),b+c));
        if (b + c > B) q.push(DPAIR(IPAIR(a,B),b+c-B));
        else q.push(DPAIR(IPAIR(a,b+c),0));
    }
    sort(result.begin(),result.end());
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
}

int main(){
    cin >> A >> B >> C;
    q.push(DPAIR(IPAIR(0,0),C));
    bfs();
}