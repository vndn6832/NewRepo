#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int alphaArr[26];

	for (int i = 0; i < 26; i++) {
		alphaArr[i] = -1;
	}

	for (int j = 0; j < str.length(); j++) {
		if (alphaArr[str[j] - 'a'] == -1) {
			alphaArr[str[j] - 'a'] = j;
		}
	}

	for (int k = 0; k < 26; k++) {
		cout << alphaArr[k] << " ";
	}

	cout << endl;
}
