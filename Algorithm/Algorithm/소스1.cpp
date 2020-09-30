//연속하는 0 가장 긴 범위
//중간값
//10001
//입력
//7
//1 0 1 0 0 0 1
//출력
//2

#include<iostream>
int n;
using namespace std;
int main() {
	cin >> n;
	int cnt = 0;
	int sideCnt1 = 0;
	int sideCnt2 = 0;
	int max = 0;
	bool side1 = false;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			if (side1 == true) {
				if (cnt > max) max = cnt;
			}else{
				side1 = true;
				sideCnt1 = cnt;
			}
			cnt = 0;
		}
		else {
			cnt++;
			if (i == n - 1) sideCnt2 = cnt;
		}
	}

	cout << sideCnt1 << endl;
	cout << max << endl;
	cout << sideCnt2 << endl;

	int sideMax = sideCnt1;
	if (sideCnt2 > sideCnt1) sideMax = sideCnt2;

	max = (max + 1) / 2;

	if (sideMax > max) {
		cout << sideMax << endl;
	}
	else {
		cout << max << endl;
	}
}