/*
//오답
#include<iostream>
using namespace std;
int n, r;
int ans = 0;
bool check[21];
void DFS(int num, int cnt) {
	if (cnt == r) {
		ans++;
	}
	else {
		if (check[num] != true) {
			check[num] = true;
			DFS(num + 1, cnt + 1);
			check[num] = false;
		}
	}
}
int main() {
	cin >> n >> r;
	DFS(1, 1);
	cout << ans<< endl;
}*/

/*
//정답
#include<iostream>
using namespace std;
int n, r;
int ans = 0;
bool check[21];
void DFS(int num, int cnt) {
	if (cnt == r) {
		ans++;
	}
	else {

		for (int i = num; i < n; i++) {
			if (check[i] != true) {
				check[i] = true;
				DFS(i, cnt + 1);
				check[i] = false;
			}
		}
		
	}
}
int main() {
	cin >> n >> r;
	DFS(0, 0);
	cout << ans << endl;
}*/

/*
//1부터 넣으면?
#include<iostream>
using namespace std;
int n, r;
int ans = 0;
bool check[21];
void DFS(int num, int cnt) {
	if (cnt == r) {
		ans++;
	}
	else {

		for (int i = num; i <= n; i++) {
			if (check[i] != true) {
				check[i] = true;
				DFS(i, cnt +1);
				check[i] = false;
			}
		}

	}
}
int main() {
	cin >> n >> r;
	DFS(1, 0); //1부터 넣으면
	cout << ans << endl;
}*/

/*
//강의내용
#include<iostream>
using namespace std;
int dfs(int n, int r) {
	if (n == r || r == 0) return 1;
	else return dfs(n - 1, r) + dfs(n - 1, r - 1);
}
int main() {
	int n, r;
	cin >> n >> r;
	cout << dfs(n, r) << endl;
}*/


//강의내용 +메모제이션
#include<iostream>
using namespace std;
int dy[21][21];
int dfs(int n, int r) {
	if (dy[n][r] > 0) return dy[n][r];
	if (n == r || r == 0) return 1;
	else return dy[n][r]=dfs(n - 1, r) + dfs(n - 1, r - 1);
}
int main() {
	int n, r;
	cin >> n >> r;
	cout << dfs(n, r) << endl;
}