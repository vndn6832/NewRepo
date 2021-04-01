//11:50
//1:10
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, K;
struct info {
	bool robot;
	int val;
	info(bool a, int b) {
		robot = a;
		val = b;
	}
};
vector<info> v;
queue<int> r; //로봇위치
int ans = 1;
void print() {
	cout << endl;
	for (int i = 0; i < 2 * N; i++) {
		if (v[i].robot == true)
			cout << "*" << v[i].val << "*" << " ";
		else
			cout << v[i].val << " ";
	}
	cout << endl;
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		int a;
		cin >> a;
		v.push_back(info(false, a));
	}

	//print();
	while (1) {
		//cout << "==============================" << ans << " 번째" << "==========" << endl;
		//벨트 회전
		info tmp = v[2 * N - 1];
		for (int i = 2 * N - 1; i > 0; i--) {
			v[i] = v[i - 1];
		}
		v[0] = tmp;

		for (int i = 0; i < r.size(); i++) {
			int x = r.front();
			int nx = (x + 1) % (2 * N);
			r.pop();
			r.push(nx);

			v[x].robot = false;
			v[nx].robot = true;
		}

		//cout << "=======회전======" << endl;
		//print();
		int size = r.size(); //***
		for (int i = 0; i < size; i++) {
			int x = r.front();
			r.pop();

			v[x].robot = false;

			if (x == N - 1) {
				//cout << "회전 후 내림 ==> " << x << endl;
				//print();
				continue;
			}

			int nx = (x + 1) % (2 * N);

			//if (nx == N - 1) {
			//	cout << "이동 후 내림 ==> " << nx << endl;
			//	print();
			//	
			//}

			if (v[nx].robot == false && v[nx].val >= 1) {

				if (nx == N - 1) {
					v[nx].val -= 1;
					//cout << "이동 후 내림 ==> " << nx << endl;
					//print();
				}
				else {
					v[nx].robot = true;
					v[nx].val -= 1;
					r.push(nx);
				}

			}
			else {
				v[x].robot = true;
				r.push(x);
			}



		}
		if (v[0].robot == false && v[0].val != 0) {
			v[0].robot = true;
			v[0].val -= 1;
			r.push(0);
		}
		//cout << "======================새로운 로봇 타기" << endl;
		//print();

		int cnt = 0;
		for (int i = 0; i < 2 * N; i++) {
			if (v[i].val == 0)
				cnt++;
		}

		if (cnt >= K) break;

		ans++;
	}
	cout << ans << endl;
}