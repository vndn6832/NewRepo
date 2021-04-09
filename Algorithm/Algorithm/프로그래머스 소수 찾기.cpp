#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<char> ch;
int n;
char res[7];
bool check[7];
int nSize;
vector<int> v;
void DFS(int cnt) {

	if (cnt == n) {
		string st = "";
		for (int i = 0; i < n; i++) {
			st += res[i];
		}
		int num = stoi(st);
		v.push_back(num);

	}
	else {
		for (int i = 0; i < nSize; i++) {
			if (check[i] == true) continue;
			res[cnt] = ch[i];
			check[i] = true;
			DFS(cnt + 1);
			check[i] = false;
		}
	}
}
int solution(string numbers) {
	int answer = 0;
	nSize = numbers.size();
	for (int i = 0; i < nSize; i++) {
		ch.push_back(numbers[i]);
	}

	for (int i = 0; i < nSize; i++) {
		n = i + 1;
		DFS(0);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) continue;
		int num = v[i];
		bool flag = true;

		for (int j = 2; j <= sqrt(num); j++) {
			if (num % j == 0) {
				flag = false;
				break;
			}
		}

		if (num == 1) flag = false;
		if (flag == true) answer++;
	}


	return answer;
}