#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> t;
vector<int> p;
int res=0;
void DFS(int L, int sum) {
	if (L == n + 1) {
		if (sum > res) res = sum;
	}
	else {
		if (L + t[L] <= n+1) DFS(L + t[L], sum + p[L]);
		DFS(L + 1, sum);
	}
}
int main() {
	cin >> n;
	t.push_back(0);
	p.push_back(0);
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		t.push_back(a);
		p.push_back(b);
	}
	DFS(1, 0);
	cout << res << endl;
}