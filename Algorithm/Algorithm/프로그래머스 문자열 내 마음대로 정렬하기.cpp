#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int N;
bool compare(string a, string b) {
	if (a[N] == b[N])
		return a < b;
	else
		return a[N] < b[N];
}
vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	N = n;
	sort(strings.begin(), strings.end(), compare);

	for (int i = 0; i < strings.size(); i++) {
		answer.push_back(strings[i]);
	}

	return answer;
}

int main() {
	
	vector<string> tmp = solution({ "abce", "abcd", "cdx" }, 2);

	for (int i = 0; i < tmp.size(); i++) {
		cout << tmp[i] << " ";
	}
}