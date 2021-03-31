#include<iostream>
#include<cmath>
using namespace std;
int N;
int v[1000001]; //벡터 대신 배열
int a, b;
long long ans; //int 범위 벗어날 수도 있으므로 long long
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	cin >> a >> b;
	ans = N;
	for (int i = 0; i < N; i++) {
		int tmp = v[i] - a;

		if (tmp > 0) { //continue 보다는 if문 쓰기
			ans += ceil((double)tmp / b);
		}
	}
	cout << ans << endl;
}