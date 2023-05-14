#include <iostream>

using namespace std;

int main(){
    int S; cin >> S;
    int N=1;
    int i,j = 1;
    int flag = 1;
    int cnt = 0;
    int re;
    while(flag){
        while(i<=j){
            cnt+=i;
            i++;
            if(cnt == S){
                re = j;
                flag=0;
            }
        }
        
        cnt = 0;
        j++;
    }
}