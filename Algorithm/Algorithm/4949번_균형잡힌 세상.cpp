#include<iostream>
#include<string>
#include<stack>
using namespace std;
int func(string st) {
	stack<char> token;
	for (int i = 0; i < st.length(); i++) {
		if (st[i] == '(') token.push('(');
		else if (st[i] == '[') token.push('[');
		else if (st[i] == ')') {
			/*
			if (token.size() == 0) {
				cout << "no" << endl;
				return 0;
			}
			if (token.top() != '(') {
				cout << "no" << endl;
				return 0;
			}
			token.pop();
			*/

			if (!token.empty() && token.top() == '(') {
				token.pop();
			}
			else {
				cout << "no" << endl;
				return 0;
			}
		}
		else if (st[i] == ']') {
			/*
			if (token.size() == 0) {
				cout << "no" << endl;
				return 0;
			}
			if (token.top() != '[') {
				cout << "no" << endl;
				return 0;
			}
			token.pop();
			*/

			if (!token.empty() && token.top() == '[') {
				token.pop();
			}
			else {
				cout << "no" << endl;
				return 0;
			}
		}
	}

	if (token.size() == 0)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}
int main() {
	string st;
    
	while (1) {
		getline(cin, st);
		//cout << st << endl;
		if (st == ".") break;
		func(st);
	}
}