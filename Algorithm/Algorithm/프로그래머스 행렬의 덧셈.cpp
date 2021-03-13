#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) {
		vector<int> temp;
		for (int j = 0; j < arr1[i].size(); j++) {
			temp.push_back(arr1[i][j] + arr2[i][j]);
		}
		answer.push_back(temp);
	}
	return answer;
}

int main() {
	vector<vector<int>>ans = solution({ {1,2},{2,3} }, { {3,4},{5,6} });
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}