#include<iostream>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);

	string st;

	getline(cin, st);

	int cnt = 0;

	for (int i = 1; i < st.size()-1; i++) {
		if (st[i] == ' ') cnt++;
	}
	
	//�ƿ� ���鸸 �ԷµǴ� ���

	if (st == " ") 
		cout << 0 << endl;
	else
		cout << cnt + 1 << endl;
}