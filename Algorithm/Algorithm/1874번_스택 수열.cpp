#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main() {

	int n;
	cin >> n;
	stack<int> s;
	vector<char> v;
	int top = 1;
	for (int i = 1; i <= n; i++) {

		int num;
		cin >> num;
		if (!s.empty() && s.top() == num) {
			//cout << '-' << endl;
			v.push_back('-');
			s.pop();
		}
		else {
			if (top > num) {
				cout << "NO" << endl;
				return 0;
			}
			for (int j = top; j <= num; j++) {
				s.push(j);
				top++;
				//cout << '+' << endl;
				v.push_back('+');
			}
			//cout << '-' << endl;
			v.push_back('-');
			s.pop();

		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] <<"\n";
	}
	
	return 0;
}