#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> v;
	for (int i = 0; i < moves.size(); i++) {

		int pos = moves[i];
		//cout << pos << endl;
		for (int x = 0; x < board.size(); x++) {
			if (board[x][pos - 1] != 0) {
				//cout<<"find"<<endl;
				v.push_back(board[x][pos - 1]);
				board[x][pos - 1] = 0;
				break;
			}
		}

		//logic
		if (v.size() >= 2) {
			if (*(v.end() - 2) == *(v.end() - 1)) {
				v.pop_back();
				v.pop_back();
				answer += 2;
			}
		}



	}
	return answer;
}

int main() {

	cout << solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 }) << endl;


}