#include<iostream>
#include<vector>
using namespace std;
int n;
int main() {
	cin >> n;
	vector<vector< int > > arr(n, vector<int>(n, 0));

	int cnt = 1;
	for (int layer = 0; layer < (n + 1) / 2; layer++) {
		// direction 1 - traverse from left to right
		for (int ptr = layer; ptr < n - layer; ptr++) {
			arr[layer][ptr] = cnt++;
		}
		// direction 2 - traverse from top to bottom
		for (int ptr = layer + 1; ptr < n - layer; ptr++) {
			arr[ptr][n - layer - 1] = cnt++;
		}
		// direction 3 - traverse from right to left
		for (int ptr = layer + 1; ptr < n - layer; ptr++) {
			arr[n - layer - 1][n - ptr - 1] = cnt++;
		}
		// direction 4 - traverse from bottom to top
		for (int ptr = layer + 1; ptr < n - layer - 1; ptr++) {
			arr[n - ptr - 1][layer] = cnt++;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}