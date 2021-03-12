#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;
	vector<bool> v(n);
	for (int i = 2; i*i <= n; i++) {
		for (int j = i * 2; j <= n; j += i) {
			if (v[j - 1] == true) continue;
			v[j - 1] = true;
		}
	}

	for (int i = 1; i < v.size(); i++) {
		if (v[i] != true)
			answer++;
	}
	return answer;
}

int main() {
	cout << solution(10) << endl;
}