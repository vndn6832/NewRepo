#include <vector>
#include <iostream>
using namespace std;
bool ch[200001];
int solution(vector<int> nums)
{
	int answer = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (ch[nums[i]] != true) {
			ch[nums[i]] = true;
			answer++;
		}
	}
	if (answer > nums.size() / 2)
		answer = nums.size() / 2;

	return answer;
}
int main() {
	cout << solution({ 3,1,2,3 }) << endl;
}