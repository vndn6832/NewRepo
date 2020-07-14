#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int s = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += v[j];
		}
		s += sum;
	}

	cout << s << endl;
}