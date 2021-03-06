#include<iostream>
#include<limits.h>
using namespace std;
int n;
int num[12];
int tmp[4];
int maxVal = INT_MIN;
int minVal = INT_MAX;
int cal(int result, int target, int i) {
	if (i == 0) {
		return result + target;
	}
	else if (i == 1) {
		return result - target;
	}
	else if (i == 2) {
		return result * target;
	}
	else {
		return result / target;
	}
}
void DFS(int result, int target, int cnt) {
	if (cnt == n) {
		if (result < minVal)
			minVal = result;

		if (result > maxVal)
			maxVal = result;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (tmp[i] != 0) {
				tmp[i] -= 1;
				int t = cal(result, target, i);
				DFS(t, num[cnt + 1], cnt + 1);
				tmp[i] += 1;
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
		cin >> tmp[i];
	}

	DFS(num[0], num[1],1);

	cout << maxVal << endl;
	cout << minVal << endl;
}