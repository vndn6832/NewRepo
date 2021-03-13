#include<iostream>
using namespace std;
int dy[21][21]; //***
int c(int n, int r) {
	if (dy[n][r] > 0) return dy[n][r]; //***
	if (n == r || r == 0) return 1;
	else return dy[n][r] = c(n - 1, r) + c(n - 1, r - 1);
}
int main(){
	int n, r;
	cin >> n >> r;
	cout << c(n, r) << endl;
}
