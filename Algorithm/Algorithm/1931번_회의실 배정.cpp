#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> time;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		time.push_back(make_pair(end,start));
	}

	sort(time.begin(), time.end());

	int cnt = 0;
	int preEnd = 0;
	for (int i = 0; i < n; i++) {
		if (time[i].second >= preEnd) {
			cnt++;
			preEnd = time[i].first;
		}

	}

	cout << cnt << endl;
	
}