#include <string>
#include <vector>
#include <iostream>
using namespace std;
int check[200];
int n2;
vector<vector<int>> computers2;
void DFS(int v) {
	check[v] = 1;
	for (int i = 0; i < n2; i++) {
		if (check[i] != 1 && computers2[v][i] == 1) {
			DFS(i);
		}
	}

}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	n2 = n;
	computers2 = computers;
	for (int i = 0; i < n; i++) {
		if (check[i] != 1) {
			answer++;
			DFS(i);
		}
	}

	return answer;
}

int main() {
	cout << solution(3, { {1, 1, 0},{1, 1, 0},{0, 0, 1} }) << endl;
}