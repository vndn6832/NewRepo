#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 987654321
int Array[20][20];
int N;
int Mark[20][20];
void fill(int r, int c, int value) {
	if (r<0 || r>N - 1 || c < 0 || c > N - 1) return;
	if (Mark[r][c] != 0) return;

	Mark[r][c] = value;
	
	fill(r - 1, c, value); //상
	fill(r + 1, c, value); //하
	fill(r, c - 1, value); //좌
	fill(r, c + 1, value); //우

}
int solve() {
	int ret = INF;
	for (int x = 0; x <= N - 3; x++) {
		for (int y = 1; y <= N - 2; y++) {
			for (int d1 = 1;x+d1<=N-2 && y-d1>=0; d1++) {
				for (int d2 = 1;x+d1+d2 <=N-1 && y+d2<=N-1; d2++) {
					memset(Mark, 0, sizeof(Mark));
					for (int i = 0; i <= d1; i++) {
						Mark[x + i][y - i] = 5; //1
						Mark[x + d2 + i][y + d2 - i] = 5;//4
					}
					for (int i = 0; i <= d2; i++) {
						Mark[x + i][y + i] = 5; //2
						Mark[x + d1 + i][y - d1 + i] = 5; //3
					}

					for (int r = x - 1; r >= 0; r--) 
						Mark[r][y] = 1;

					for (int c = y + d2+1; c < N; c++)
						Mark[x + d2][c] = 2;
					
					for (int c = y - d1 - 1; c >= 0; c--)
						Mark[x + d1][c] = 3;

					for (int r = x + d1 + d2 + 1; r < N; r++)
						Mark[r][y - d1 + d2] = 4;
					
					fill(0, 0, 1); //모서리 1
					fill(0, N - 1, 2); //모서리 2
					fill(N - 1, 0, 3); //모서리 3
					fill(N - 1, N - 1, 4); //모서리 4

					int people[6] = { 0 };
					for (int r = 0; r < N; r++)
						for (int c = 0; c < N; c++)
							people[Mark[r][c]] += Array[r][c];

					people[5] += people[0];

					int minP=INF, maxP=0;
					for (int i = 1; i <= 5; i++) {
						minP = min(minP, people[i]);
						maxP = max(maxP, people[i]);
					}

					ret = min(ret, maxP - minP);
				}
			}
		}
	}
	return ret;
}
int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Array[i][j];
		}
	}

	cout << solve() << endl;
}