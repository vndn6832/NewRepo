#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	answer = n - lost.size();
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost[i] = -1;
				reserve[j] = -1;
				answer++;
				break;
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] - 1 == reserve[j]) {
				reserve[j] = -1;
				answer++;
				break;
			}
			else if (lost[i] + 1 == reserve[j]) {
				reserve[j] = -1;
				answer++;
				break;
			}
		}
	}

	return answer;
}

int main() {
	cout << solution(5, { 2,4 }, { 1,3,5 }) << endl;
}