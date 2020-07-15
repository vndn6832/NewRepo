#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int num[100000] = { -1, };
string n;
bool zero = false;
void print() {
	sort(num,num+n.length());
	for (int i = n.length()-1; i>= 0; i--) {
		
		cout << num[i];
	
	}

}
int main() {
	
	cin >> n;
	//cout << n.length() << endl;
	int sum = 0;
	for (int i = 0; i < n.length(); i++) {
		num[i] = n[i] - '0';
		if (num[i] == 0) zero = true;
		sum += num[i];
	}

	if (sum % 3 == 0 && zero == true)
		print();
	else
		cout << -1 << endl;

}