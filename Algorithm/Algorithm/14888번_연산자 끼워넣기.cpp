#include<iostream>
#include<limits.h>
using namespace std;
int n;
int num[100];
int cal[4];
int ch[100];
int maxVal = INT_MIN;
int minVal = INT_MAX;
void DFS(int idx, int sum) {
	if (idx == n) {
		if (sum > maxVal) {
			maxVal = sum;
		}

		if (sum < minVal) {
			minVal = sum;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (cal[i] != 0) {
				int result;
				if (i == 0) {
					result = sum + num[idx];
				}
				else if (i == 1) {
					result = sum - num[idx];
				}
				else if (i == 2) {
					result = sum * num[idx];
				}
				else if (i == 3) {
					result = sum / num[idx];
				}
				cal[i]--;

				DFS( idx+1, result);

				cal[i]++;
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
		cin >> cal[i];
	}

	DFS(1, num[0]);
	cout << maxVal << endl;
	cout << minVal << endl;
}