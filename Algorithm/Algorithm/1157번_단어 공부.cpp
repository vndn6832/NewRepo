#include<iostream>
#include<string.h>
using namespace std;
int main() {

	string st;
	cin >> st;

	int cnt[26] = { 0, };

	for (int i = 0; i < st.length(); i++) {
		if (st[i] >= 'a')
			cnt[st[i] - 'a']++;
		else
			cnt[st[i] - 'A']++;
	}
	
	

	//for (int i = 0; i < 26; i++)
	//	cout << cnt[i] << endl;
	int max = cnt[0];
	int index = 0;
	for (int i = 1; i < 26; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (max == cnt[i] && i != index) {
			cout << '?' << endl;
			return 0;
		}
	}


	cout << (char)(index + 65) << endl;



	return 0;
}