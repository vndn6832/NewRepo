#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
bool check[50];
int answer = 0;
vector<int> nums2;
bool cal(int num) {

	bool flag = true;
	if (num < 2) {
		flag = false;
	}
	else {
		for (int i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) {
				flag = false;
				break;
			}
		}
	}
	//cout<< num <<": "<<flag<< endl;
	return flag;
}
void DFS(int idx, int cnt) {
	if (cnt == 3) {
		int ret = 0;
		for (int i = 0; i < nums2.size(); i++) {
			if (check[i] == true)
				ret += nums2[i];
		}
		if (cal(ret) == true) {
			answer++;
		}
	}
	else {
		for (int i = idx; i < nums2.size(); i++) {
			if (check[i] != true) {
				check[i] = true;
				DFS(i, cnt + 1);
				check[i] = false;
			}
		}
	}
}
int solution(vector<int> nums) {
	nums2 = nums;
	DFS(0, 0);

	return answer;
}

int main() {
	cout << solution({ 1,2,7,6,4 }) << endl;
}