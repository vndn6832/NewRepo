#include <string>
#include <vector>

using namespace std;
int n, target2, cnt = 0;
vector<int> numbers2;
void DFS(int idx, int sum) {
	if (idx == n) {
		if (sum == target2)
			cnt++;
	}
	else {
		DFS(idx + 1, sum + numbers2[idx]);
		DFS(idx + 1, sum - numbers2[idx]);
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	numbers2 = numbers;
	target2 = target;
	n = numbers.size();
	DFS(0, 0);
	answer = cnt;
	return answer;
}