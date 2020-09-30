#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int map[151];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i < b; i++) {
			map[i] += 1;
		}
	}

	int maxVal = 0;
	for (int i = 0; i < 150; i++) {
		
		if (map[i] > maxVal) maxVal = map[i];
	}
	

	cout << maxVal << endl;

}