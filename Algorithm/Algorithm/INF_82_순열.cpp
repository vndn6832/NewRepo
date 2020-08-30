#include<iostream>
using namespace std;
int a[4];
int res[4];
bool check[4];
int cnt = 0;
int N, R;
void DFS(int L) {
	if (L == R) {
		for (int i = 0; i < R; i++) {
			cout << res[i]<< " ";
		}
		cnt++;
		cout << endl;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (check[i] != true) {
				res[L] = a[i];
				check[i] = true;
				DFS(L + 1);
				check[i] = false;
			}
		}
	}
}
int main() {
	
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	DFS(0);
	cout << cnt << endl;

}