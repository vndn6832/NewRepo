#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = 0; j < phone_book.size(); j++) {
			if (j != i) {
				int findIdx = phone_book[j].find(phone_book[i], 0);
				if (findIdx == 0) {
					answer = false;
					return answer;
				}
			}

		}
	}
	return answer;
}