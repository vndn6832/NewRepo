#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int r, c, k;
int rSize = 3, cSize = 3;
int map[101][101];
int cnt = 0;
struct num {
	int val;
	int cnt;
	num(int a, int b) {
		val = a;
		cnt = b;
	}
};
bool compare(num n1, num n2) {
	if (n1.cnt == n2.cnt) {
		return n1.val < n2.val;
	}
	else {
		return n1.cnt < n2.cnt;
	}
}
void R() {

	vector<num> v[101];
	int s = 0;
	for (int i = 1; i <= rSize; i++) {
		int tmp[101] = { 0, }; //*초기화

		for (int j = 1; j <= cSize; j++) { //
			//cout << "val: " << map[i][j] << endl;
			tmp[map[i][j]]++;
			//cout << "cnt: " << tmp[map[i][j]] << endl;
		}
		for (int k = 1; k <= 100; k++) {
			if (tmp[k] >= 1)
				v[i].push_back(num(k, tmp[k]));
		}
		sort(v[i].begin(), v[i].end(), compare);
		//cout << "v[i]: " << v[i].size() << endl;

		if (v[i].size() * 2 > s) {
			s = v[i].size() * 2;
			if (s > 100)
				s = 100;
			//cout << "s: " << s << endl;
		}
	}
	cSize = s;
	for (int i = 1; i <= rSize; i++) {
		for (int z = 1; z <= s; z++) {
			//cout << "* " << v[i].size() << endl;
			if (z > v[i].size() * 2) {
				map[i][z] = 0;
				continue;
			}

			if (z % 2 == 1) {
				map[i][z] = v[i][(z - 1) / 2].val;
			}
			else {
				map[i][z] = v[i][(z - 1) / 2].cnt;
			}

		}
	}

	//cout << "R" << endl;
}
void C() {

	vector<num> v[101];
	int s = 0;
	for (int i = 1; i <= cSize; i++) {
		int tmp[101] = { 0, }; //*초기화

		for (int j = 1; j <= rSize; j++) { //
			//cout << "val: " << map[j][i] << endl;
			tmp[map[j][i]]++;
			//cout << "cnt: " << tmp[map[j][i]] << endl;
		}
		for (int k = 1; k <= 100; k++) {
			if (tmp[k] >= 1)
				v[i].push_back(num(k, tmp[k]));
		}
		sort(v[i].begin(), v[i].end(), compare);
		//cout << "v[i]: " << v[i].size() << endl;
		if (v[i].size() * 2 > s) {
			s = v[i].size() * 2;
			if (s > 100)
				s = 100;
			//cout << "s: " << s << endl;
		}
	}
	rSize = s; //***
	for (int i = 1; i <= cSize; i++) {
		for (int z = 1; z <= s; z++) {
			//cout << "* " << v[i].size() << endl;
			if (z > v[i].size() * 2) {
				map[z][i] = 0;
				continue;
			}

			if (z % 2 == 1) {
				map[z][i] = v[i][(z - 1) / 2].val;
			}
			else {
				map[z][i] = v[i][(z - 1) / 2].cnt;
			}

		}
	}

	//cout << "C" << endl;



}
void cal() {

	while (1) {
		if (rSize >= cSize) {
			R();

		}
		else {
			C();
		}
		cnt++;
		cout << cnt << " " << rSize << " " << cSize << " " << map[r][c] << endl;

		for (int i = 1; i <= rSize; i++) {
			for (int j = 1; j <= cSize; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}

		if (map[r][c] == k)
			break;
		if (cnt == 100) {
			cnt = -1;
			break;
		}
	}
}
int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}

	if (map[r][c] == k) {
		cout << 0 << endl;
	}
	else {

		cal();
		cout << cnt << endl;
	}
}