#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;
vector<vector<int>> b;
vector<int> m;
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	//cout << "move: " << moves.size() << endl;
	//cout << "board: " << board.size() << endl;
	vector<int> v;
	for (int i = 0; i < moves.size(); i++) {
		
		int pos = moves[i];
		
		for (int j = 0; j < board.size(); j++) {
			
			if (board[j][pos - 1] != 0)
			{
				v.push_back(board[j][pos - 1]);
				board[j][pos - 1] = 0;
				break;
			}

			
		}

		if (v.size() > 1) {
			if (*(v.end() - 2) == *(v.end() - 1)) {
				v.pop_back();
				v.pop_back();
				answer += 2;
			}
		}
	}

	return answer;
}
void main() {
	b = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
	m = { 1, 5, 3, 5, 1, 2, 1, 4 };
	cout << solution(b, m) << endl;
}