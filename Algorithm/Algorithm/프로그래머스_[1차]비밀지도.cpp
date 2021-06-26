#include <string>
#include <vector>
#include <iostream>
using namespace std;
int width;
string cal(int num) {
	string tmp = "";
	int cnt = width;
	while (cnt > 0) {
		if (num != 0) {
			tmp += to_string(num % 2);
		}
		else {
			tmp += '0';
		}
		num = num / 2;
		cnt--;
	}
	return tmp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	width = n;
	for (int i = 0; i < arr1.size(); i++) {
		int x = arr1[i];
		int y = arr2[i];
		string st1 = cal(x);
		//cout << st1 << endl;
		string st2 = cal(y);
		//cout << st2 << endl;
		string tmp = "";
		for (int i = n - 1; i >= 0; i--) {
			if (st1[i] == '0' && st2[i] == '0')
				tmp += ' ';
			else
				tmp += '#';
		}
		answer.push_back(tmp);
	}

	return answer;
}

int main() {
	vector<string> v;
	v = solution(6, {46,33,33,22,31,50 }, { 27,56,19,14,14,10 });
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}