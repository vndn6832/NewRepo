#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int caseNum;
	cin >> caseNum;
	for (int t = 0; t < caseNum; t++) {
		int people;
		cin >> people;
		vector<pair<int, int>> v;
		for (int value = 0; value < people; value++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end());
		int cnt = 1;
		int score = v[0].second;
		for (int i = 1; i < people; i++) {
			if (score  > v[i].second) {
				cnt++;
				score = v[i].second;

			}
		}
		
	
		cout << cnt << endl;
	
	}

}