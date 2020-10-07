#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input.txt");
	if (!cin) {
		cout << "열수없음" << endl;
	}

	map<char, int> ch;

	map<char, int>::iterator it;
	char a[100];
	cin >> a;

	for (int i = 0; a[i] != '\0'; i++) {
		ch[a[i]]++;
	}

	for (it = ch.begin(); it != ch.end(); it++) {
		cout << it->first << ' ' << it->second << "\n";
	}

	
	return 0;
}