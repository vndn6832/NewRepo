#include <string>
#include <vector>

using namespace std;
int minVal;
void cal(int num1, int num2) {
	int temp = num1 < num2 ? num1 : num2;
	int val = num1 * num2;
	for (int i = 2; i <= temp; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			if (i * (num1 / i) * (num2 / i) < val)
				val = i * (num1 / i) * (num2 / i);
		}
	}
	minVal = val;
}
int solution(vector<int> arr) {
	int answer = 0;
	minVal = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		int num = arr[i];
		cal(minVal, num);
	}
	answer = minVal;
	return answer;
}