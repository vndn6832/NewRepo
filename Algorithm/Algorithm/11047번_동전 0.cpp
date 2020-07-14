#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int value;//동전의 가치
		cin >> value;
		v.push_back(value);

	}

	sort(v.rbegin(), v.rend());

	int count=0;
	for (int i = 0; i < n; i++) {
		count += k / v[i];
		k = k % v[i];
		if (k == 0) break;
	}

	cout << count << endl;
}