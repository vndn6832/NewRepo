#include<iostream>
using namespace std;
int a[11], n, m, cnt=0;
int path[11]; //경로
void DFS(int L, int val){
    if(L==n+1){
        if(val == m){
            cnt++;
            for(int i=1;i<L;i++){
                cout << path[i] << ' ';
            }
            puts("");
        } 

    }else{
        path[L] = a[L];
        DFS(L+1, val+a[L]);
        path[L] = -a[L];
        DFS(L+1, val-a[L]);
        path[L] = 0;
        DFS(L+1, val);
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    DFS(1, 0);
    if(cnt == 0)
        cout << -1 << endl;
    else
        cout << cnt << endl;
}