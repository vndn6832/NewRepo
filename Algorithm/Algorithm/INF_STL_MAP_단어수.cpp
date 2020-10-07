#include<iostream>
#include<fstream>
#include<map>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input2.txt");
	if (!cin) {
		cout << "열수없음" << endl;
	}

	map<string, int> ch;

	map<string, int>::iterator it;
	//char a[100];
	string a; //char 배열 대신
	int n;
	cin >> n;

	for (int i = 1; i<=n; i++) {
		cin >> a;
		ch[a]++;
	}

	
	for (it = ch.begin(); it != ch.end(); it++) {
		cout << it->first << ' ' << it->second << "\n";
	}
	

	/*가장 많이 등장한 단어 출력*/
	int max = 0;
	string res;
	for (it = ch.begin(); it != ch.end(); it++) {
		if (it->second > max) {
			max = it->second;
			res = it->first;
		}
	}

	cout << res << " : " << max<<"\n";

	return 0;
}