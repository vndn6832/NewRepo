#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
bool func(string s){
	stack<char> st1;

    if (s[0] == ')') return false;
    
	
	for (int j = 0; j < s.length(); j++) {
		if (s[j] == '(')  
			st1.push(s[j]);
		else {
			if (st1.empty()) return false;
			st1.pop();
		}
	}
	if (!st1.empty()) return false;
	
	return true;
}
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		bool result = func(s);
		if (result == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}