#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool check[100000000];
string ans = "a";
void DFS(vector<vector<string>> &tickets, string cur, string path, int cnt) {
	if (cnt == tickets.size()) {
		if (path < ans)
			ans = path;
	}
	else {
		for (int i = 0; i < tickets.size(); i++) {
			if (check[i] != true && cur ==tickets[i][0]) {
				check[i] = true;
				DFS(tickets,tickets[i][1], path+tickets[i][1], cnt+1);
				check[i] = false;
			}
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	
	DFS(tickets, "ICN", "ICN", 0);

	/* 3ÀÚ¸®¾¿*/
	for (int i = 0; i < ans.size(); i += 3) {
		answer.push_back(ans.substr(i, 3));
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