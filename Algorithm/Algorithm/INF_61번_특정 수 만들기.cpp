#include<iostream>
using namespace std;
int a[11], n, m, cnt=0;
void DFS(int L, int val){
    if(L==n+1){
        if(val == m) cnt++;

    }else{
        DFS(L+1, val+a[L]);
        DFS(L+1, val-a[L]);
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