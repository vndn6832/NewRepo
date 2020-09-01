#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> sch;
int ans = 0;
bool check[15];
int N;
int sum = 0;
void DFS(int index) {
	if (index == N) {
		if (sum > ans) {
			ans = sum;
		}
	}
	else {
		
		if (index+sch[index].first<=N) {
			sum += sch[index].second;
			DFS(index + sch[index].first);
			sum -= sch[index].second;
				
		}
		

		DFS(index+1);
	}
}
int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		sch.push_back(make_pair(a, b));
	}

	DFS(0);

	cout << ans << endl;
}