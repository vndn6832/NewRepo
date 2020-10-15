/*��� ���ߴ��� ã��*/
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
		copyToMap(map, cpyMap); //���� �� ���� ����
		for (int i = 1; i <= m; i++) { //��� 1~m ������
			int x = s[i].x; 
			int y = s[i].y;
			int d = s[i].dir;
			bool flag = false; //��� �̵� �ߴ��� üũ
			if (d == -1) continue; //�� �̹� �׾����� �Ѿ��
	
			//cout << "�����̱���" << endl;
			//cout << i << " " << x << " " << y << " " << d << endl;
			for (int j = 0; j < 4; j++) { //4�������� Ž��
				int nd = priority[i][d][j]; //Ž�� ������ �Է¹��� �켱���� �����ͱ������
				int nx = x + dx[nd-1]; 
				int ny = y + dy[nd-1];

				if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue; //�� ���� ���� �Ѿ��
				if (cpyMap[nx][ny].num != 0) continue; //�ش� ĭ�� ������ ������
				flag = true; //������� �Դٴ°�, �̵��� ĭ�� �ִٴ� ��
				if (map[nx][ny].num !=0 && map[nx][ny].num < i ) { //�ش� ĭ�� �ٸ� ���� ���� �̵��ϴµ�, ���� ���� �� ŭ
					s[i].dir = -1; //ũ�Ⱑ �� ũ�ϱ� ����
					cnt--; //��ü ��� ���� ����
					
					/*cout << "Ŀ�� ���" << endl;
					cout << map[nx][ny].num << "    " << i << endl;
					cout << cnt << endl;*/
					
					break; //�̵������ϱ� �극��ũ
				}
				else{

					if (map[nx][ny].num != 0) { //�ش� ĭ�� �ٸ� ���� ���� �̵��ϴµ�, ���� ���� �� ����
						s[map[nx][ny].num].dir = -1; //ũ�Ⱑ �� ū �� ����
						cnt--; //��ü ��� ���� ����
					}

					
					/*cout << "�۾Ƽ� ��" << endl;
					cout << map[nx][ny].num << "    " << i << endl;
					cout << cnt << endl;*/

			   
					map[nx][ny].num = i; //�ش� ĭ���� ��� �̵�
					map[nx][ny].sec = k; //���� k��
					

					s[i].x = nx; //��� x��ǥ ����
					s[i].y = ny; //��� y��ǥ ����
					s[i].dir = nd; //��� ���� ����

					break; //�̵������ϱ� �극��ũ

				}
				
			}

			if (flag == false) {
				//�ڽ��� ������ ���ư�
				
				for (int b = 0; b < 4; b++) { 
					int nd = priority[i][d][b];
					int nx = x + dx[nd - 1];
					int ny = y + dy[nd - 1];


					if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue; //�� ����� �Ѿ��
					if (cpyMap[nx][ny].num == i) { //���� ��ȣ�� ������ = ���� ������ �����
						map[nx][ny].num = i; 
						map[nx][ny].sec = k; //�ٽ� k��


						s[i].x = nx; 
						s[i].y = ny;
						s[i].dir = nd;
						map[nx][ny].sec = 1004; //�� �ڱ� ������ ���ư� ���� ���� �ʰ� ���پ��� ���� ǥ���ϱ� ����
						break;
					}

				
				}

				

				
			}
			
			
		}

		//�ð� ������ �����ֱ�
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cpyMap[i][j].sec) {
					map[i][j].sec--;
					if (map[i][j].sec == 1003) //�ڱ� ������ ���ư� ���
						map[i][j].sec = k;//�ٽ� k��
					if (map[i][j].sec == 0) { //���� �ʰ� ���� ���
						map[i][j].num = 0; //���� �����
					}
				}
			}
		}
		/*cout << time <<" �� ��" << endl;
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
		if (cnt == 1) break; //��� 1�� ���� ���
		if (time == 1000) break; //1000�� �ʰ�
	}
}
int main() {
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int val;
			cin >> val;
			map[i][j].num = val;
			if (val > 0) { //���
				s[val].x = i; //��� x��ǥ ���
				s[val].y = j; //��� y��ǥ ���
				map[i][j].sec = k; //K��
				cnt++; //��� ����
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
				cin >> priority[k][i][j]; //�̵� �켱����
			}
		}
	}

	move();

	if (cnt == 1) {  //��� 1�� ���� ���
		cout << time << endl;
	}
	else {
		cout << -1 << endl;
	}
}