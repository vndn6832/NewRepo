#include <iostream>
#include <string>
using namespace std;

string S;
int Alphabet[26];

void solution() {
	cin >> S;
	for (int i = 0; i < 26; i++) {
		char alpha = char(i + 'a');
		Alphabet[i] = S.find_first_of(alpha);
	}
	for (int i = 0; i < 26; i++) {
		cout << Alphabet[i] << ' ';
	}
}

int main() {
	solution();
	return 0;
}