#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	string st1, st2;
	cin >> st1 >> st2;
	sort(st1.begin(), st1.end());
	sort(st2.begin(), st2.end());

	/*
	vector<char> tmp1, tmp2;
	
	for (int i = 0; i < st1.size(); i++) {
		tmp1[i] = st1[i];
	}

	for (int i = 0; i < st2.size(); i++) {
		tmp2[i] = st2[i];
	}
	*/
	bool flag = true;
	for (int i = 0; i < st1.size(); i++) {
		if (st1[i] != st2[i]) {
			flag = false;
			break;
		}
	}

	if (flag)
		printf("YES");
	else
		printf("NO");

}