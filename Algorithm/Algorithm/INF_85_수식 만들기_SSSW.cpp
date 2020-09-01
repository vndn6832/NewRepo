#include<iostream>
#include<limits.h>
using namespace std;
int n;
int num[10];
int pick[9];
int what[4];
int min = INT_MAX;
int max = INT_MIN;

void DFS(int L, int sum) {
	if (L == n - 1) {
		if (sum > max) max = sum;
		if (sum < min) min = sum;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (what[i] != 0) {
				what[i] -= 1;
				if (i == 0 ) {
					DFS(L + 1, sum + num[L + 1]);
				}
				else if (i == 1) {
					DFS(L + 1, sum - num[L + 1]);
				}
				else if (i == 2) {
					DFS(L + 1, sum * num[L + 1]);
				}
				else {
					DFS(L + 1, sum / num[L + 1]);
				}
				
				what[i] += 1;
			}
		}

	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> what[i];
	}
	DFS(0,num[0]);
	cout << max << endl;
	cout << min << endl;
}