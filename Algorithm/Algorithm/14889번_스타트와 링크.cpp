#include<iostream>
#include<vector>
#include<limits.h>
#include<cmath>
using namespace std;
int N;
bool ch[20]; //√ ±‚»≠ ***
int map[20][20];
int minVal = INT_MAX;
int cal(vector<int> tmp) {
	int ret = 0;
	for (int i = 0; i < tmp.size(); i++) {
		for (int j = 0; j < tmp.size(); j++) {
			ret += map[tmp[i]][tmp[j]];
		}
	}
	cout << "*** " << tmp.size()<<endl;
	cout << ret << endl;
	return ret;
}
void init() {
	for (int i = 0; i < N; i++) {
		ch[i] = false;
	}
}
void DFS(int idx, int cnt) {
	if (cnt == N / 2) {
		vector<int> v1;
		vector<int> v2;

		for (int i = 0; i < N; i++) {

			if (ch[i] == true) {

				v1.push_back(i);
				cout<< "1 ";
			}
			else {
				v2.push_back(i);
				cout << "0 ";
			}


		}
			cout<< endl;
			init();
		if (minVal > abs(cal(v1) - cal(v2))) {
			minVal = abs(cal(v1) - cal(v2));

		}
	}
	else {
		for (int i = idx; i < N; i++) {
			if (ch[i] != true) {
				ch[i] = true;
				DFS(i, cnt + 1);
				ch[i] = false;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	DFS(0, 0);
	cout << minVal << endl;
}



