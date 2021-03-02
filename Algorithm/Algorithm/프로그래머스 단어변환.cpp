#include <string>
#include <vector>
#include <iostream>
using namespace std;
int wSize;
bool check[50];
vector<string> words2;
int maxVal = 51;
bool chk(string s1, string s2) {
	int cnt = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i])
			cnt++;
		if (cnt >= 2)
			return false;
	}
	return true;
}
void DFS(string b, string t, int cnt) {
	//cout << b << " " << t << " " << cnt << endl;
	if (b == t) {
		if (maxVal > cnt) {
			maxVal = cnt;
		}
	}
	else {
		for (int i = 0; i < wSize; i++) {
			//cout << words2[i] << endl;
			if (check[i] != true && chk(b, words2[i]) == true) {
				check[i] = true;
				DFS(words2[i], t, cnt + 1);
				check[i] = false;
			}
		}
	}
}
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	wSize = words.size();
	words2 = words;

	DFS(begin, target, 0);

	if (maxVal != 51)
		answer = maxVal;

	return answer;
}

int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
}