#include<iostream>
using namespace std;
int n, r; //n: 선택지 수, r: 선택해야하는 숫자 갯수
int cnt = 0; //조합 수
int ch[20];
void DFS(int s, int l) { // 시작 숫자(start)와 l(level)을 매개변수로 받는다

	if (l == r) { // 재귀함수 종료조건: l==r (즉, 뽑으려는 숫자를 모두 뽑았을 때)
		for (int i = 0; i < r; i++) {
			cout << ch[i] << " "; 
		}//재귀함수가 종료되기 전 뽑힌 숫자들을 보여주고,

		cout << endl;
		cnt++; //조합의 개수를 구하기 위해 ++
	}
	else {
		for (int i = s; i < n; i++) {
			ch[l] = i;
			DFS(i + 1, l + 1); // DFS() 함수에 사용한 숫자+1, level+1을 인자로 넘겨준다
		}
	}

}
int main() {
	cin >> n >> r;

	DFS(0, 0);

	cout << cnt << endl;
}