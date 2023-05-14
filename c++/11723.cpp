#include <iostream>

using namespace std;

int main(){
    int M; cin >> M;
    string order;
    int re[20]={ 0, };
    int index;

    for(int i = 0; i<M; i++){
        cin >> order;
        if (order == "add"){
            cin >> index;
            re[index-1]=1;
        }
        else if (order == "remove"){
            cin >> index;
            re[index-1]=0;
        }
        else if (order == "check"){
            cin >> index;
            if (re[index-1])
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (order == "toggle"){
            cin >> index;
            if (re[index-1])
                re[index-1]=0;
            else
                re[index-1]=1;
        }
        else if (order == "all"){
            for (int i=0; i<20; i++)
                re[i]=1;
        }
        else if (order == "empty"){
            for (int i=0; i<20; i++)
                re[i]=0;
        }
    }
}