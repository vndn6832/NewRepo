#include <string>
#include <vector>
#include <iostream>
using namespace std;
int tSize;
bool check[100000000];
vector<vector<string>> tickets2;
vector<vector<string>> ans;
void DFS(string des, int cnt, vector<string> path) {
	if (cnt == tSize) {
		ans.push_back(path);
	}
	else {
		for (int i = 0; i < tSize; i++) {
			if (check[i] != true) {
				if (des != tickets2[i][0]) continue;
				check[i] = true;
				path.push_back(tickets2[i][1]);
				DFS(tickets2[i][1], cnt + 1, path);
				path.pop_back();
				check[i] = false;
			}
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	tSize = tickets.size();
	tickets2 = tickets;
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == "ICN") {
			check[i] = true;
			DFS(tickets[i][1], 1, { tickets[i][0], tickets[i][1] });
			check[i] = false;
		}
	}

	answer = ans[0];

	for (int i = 1; i < ans.size(); i++) {
		for (int j = 0; j <= tSize; j++) {

			if (ans[i][j].compare(answer[j]) < 0) {
				answer = ans[i];
				break;
			}
			else if (ans[i][j].compare(answer[j]) > 0) {
				break;
			}
		}
	}
	return answer;
}

int main() {
	vector<string> print;
	print = solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL", "SFO"} });
	for (int i = 0; i < print.size(); i++) {
		cout << print[i] << " ";
	}
}