#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int a, int b) {
	string st1 = to_string(a);
	string st2 = to_string(b);
	string temp1 = st1 + st2;
	string temp2 = st2 + st1;

	//bool res = temp1 > temp2;
	//return res;

	return temp1 > temp2;

}
string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	if (answer[0] == '0')
		answer = "0";
	return answer;
}