/*어디서 멈추는지 찾기*/
#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
struct info {
	int num;
	int sec;
};
struct shark {
	int x;
	int y;
	int dir;
};
info map[21][21];
shark s[401];
int priority[401][5][5];
int cnt = 0;
int time = 0;
int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,-1,1};
void copyToMap(info org[21][21], info dest[21][21]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dest[i][j] = org[i][j];
		}
	}
}
void move() {
	while (cnt > 1) {
		time++;
		
		info cpyMap[21][21];
		copyToMap(map, cpyMap); //지금 맵 상태 복사
		for (int i = 1; i <= m; i++) { //상어 1~m 순으로
			int x = s[i].x; 
			int y = s[i].y;
			int d = s[i].dir;
			bool flag = false; //상어 이동 했는지 체크
			if (d == -1) continue; //상어가 이미 죽었으면 넘어가기
	
			//cout << "움직이기전" << endl;
			//cout << i << " " << x << " " << y << " " << d << endl;
			for (int j = 0; j < 4; j++) { //4방향으로 탐색
				int nd = priority[i][d][j]; //탐색 방향은 입력받은 우선순위 데이터기반으로
				int nx = x + dx[nd-1]; 
				int ny = y + dy[nd-1];

				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue; //맵 벗어 나면 넘어가기
				if (cpyMap[nx][ny].num != 0) continue; //해당 칸에 냄새가 있으면
				flag = true; //여기까지 왔다는건, 이동할 칸이 있다는 것
				if (map[nx][ny].num !=0 && map[nx][ny].num < i ) { //해당 칸에 다른 상어랑 같이 이동하는데, 내가 값이 더 큼
					s[i].dir = -1; //크기가 더 크니깐 죽음
					cnt--; //전체 상어 갯수 빼기
					
					/*cout << "커서 사망" << endl;
					cout << map[nx][ny].num << "    " << i << endl;
					cout << cnt << endl;*/
					
					break; //이동했으니깐 브레이크
				}
				else{

					if (map[nx][ny].num != 0) { //해당 칸에 다른 상어랑 같이 이동하는데, 내가 값이 더 작음
						s[map[nx][ny].num].dir = -1; //크기가 더 큰 상어가 죽음
						cnt--; //전체 상어 갯수 빼기
					}

					
					/*cout << "작아서 들어감" << endl;
					cout << map[nx][ny].num << "    " << i << endl;
					cout << cnt << endl;*/

			   
					map[nx][ny].num = i; //해당 칸으로 상어 이동
					map[nx][ny].sec = k; //냄새 k초
					

					s[i].x = nx; //상어 x좌표 변경
					s[i].y = ny; //상어 y좌표 변경
					s[i].dir = nd; //상어 방향 변경

					break; //이동했으니깐 브레이크

				}
				
			}

			if (flag == false) {
				//자신의 냄새로 돌아가
				
				for (int b = 0; b < 4; b++) { 
					int nd = priority[i][d][b];
					int nx = x + dx[nd - 1];
					int ny = y + dy[nd - 1];


					if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue; //맵 벗어나면 넘어가기
					if (cpyMap[nx][ny].num == i) { //나랑 번호가 같은것 = 나의 냄새로 돌어가기
						map[nx][ny].num = i; 
						map[nx][ny].sec = k; //다시 k초


						s[i].x = nx; 
						s[i].y = ny;
						s[i].dir = nd;
						map[nx][ny].sec = 1004; //상어가 자기 냄새로 돌아간 경우는 남은 초가 안줄어드는 것을 표현하기 위해
						break;
					}

				
				}

				

				
			}
			
			
		}

		//시간 지난거 없애주기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cpyMap[i][j].sec) {
					map[i][j].sec--;
					if (map[i][j].sec == 1003) //자기 냄새로 돌아간 경우
						map[i][j].sec = k;//다시 k초
					if (map[i][j].sec == 0) { //남은 초가 없는 경우
						map[i][j].num = 0; //냄새 사라짐
					}
				}
			}
		}
		/*cout << time <<" 초 후" << endl;
		cout << "1 " << s[1].x << " " << s[1].y << s[1].dir<< endl;
		cout << "2 " << s[2].x << " " << s[2].y << s[2].dir<<endl;
		cout << "3 " << s[3].x << " " << s[3].y << s[3].dir<<endl;
		cout << "4 " << s[4].x << " " << s[4].y << s[4].dir<< endl;*/
		//if (time == 1) {
			/*for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << map[i][j].num << " ";
				}
				cout << endl;
			}*/
			
		//}
		//cout << endl;
		//if (time == 1) {
			/*for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					cout << map[i][j].sec << " ";
				}
				cout << endl;
			}*/
			//return;
		//}
		if (cnt == 1) break; //상어 1만 남은 경우
		if (time == 1000) break; //1000초 초과
	}
}
int main() {
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int val;
			cin >> val;
			map[i][j].num = val;
			if (val > 0) { //상어
				s[val].x = i; //상어 x좌표 기록
				s[val].y = j; //상어 y좌표 기록
				map[i][j].sec = k; //K초
				cnt++; //상어 갯수
			}
		}

	}
	//cout << "cnt: " << cnt << endl;
	for (int i = 1; i <= m; i++) {
		cin >> s[i].dir;
	}

	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> priority[k][i][j]; //이동 우선순위
			}
		}
	}

	move();

	if (cnt == 1) {  //상어 1만 남은 경우
		cout << time << endl;
	}
	else {
		cout << -1 << endl;
	}
}