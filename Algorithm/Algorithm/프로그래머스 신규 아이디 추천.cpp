#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
	string answer = "";
	/*1단계*/
	/*
	for(int i=0;i<new_id.size();i++){
		if(new_id[i]>='A' && new_id[i]<='Z'){
			new_id[i] = new_id[i] + 32;
		}
	}
	*/

	for (int i = 0; i < new_id.size(); i++) {

		new_id[i] = tolower(new_id[i]);

	}


	string temp;
	/*2단계*/
	for (int i = 0; i < new_id.size(); i++) {
		if (new_id[i] >= 'a' && new_id[i] <= 'z')
			temp += new_id[i];

		if (new_id[i] >= '0' && new_id[i] <= '9')
			temp += new_id[i];

		if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
			temp += new_id[i];

	}

	/*3단계*/
	answer += temp[0];
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i - 1] == '.' && temp[i] == '.')
			continue;
		answer += temp[i];
	}

	/*4단계*/
	if (answer[0] == '.')
		answer.erase(0, 1);
	if (answer[answer.size() - 1] == '.')
		answer.erase(answer.size() - 1, 1);

	/*5단계*/
	if (answer.size() == 0)
		answer += 'a';

	/*6단계*/
	if (answer.size() >= 16)
		answer.erase(15, answer.size() - 15);
	if (answer[answer.size() - 1] == '.')
		answer.erase(answer.size() - 1, 1);

	/*7단계*/
	int size = answer.size();
	char ch = answer[size - 1];

	for (int i = 0; i < 3 - size; i++) {
		answer += ch;
	}

	return answer;
}

int main() {
	cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
}