#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
int map[12][12];
struct info {
	int x;
	int y;
	int dir;
	info(int a, int b, int c) {
		x = a;
		y = b;
		dir = c;
	}
};
vector<info> v; //말
vector<int> map2[12][12];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans = 1;
bool compare(pair<int, int> a, pair<int,int > b) {
	return a.first > b.first;
}
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map2[i][j].size() << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int numChk(int x, int y, int size, int num) {
	for (int i = 0; i < size; i++) {
		if (map2[x][y][i] == num)
			return i;
	}
	return -1;
}
int main() {

	//cout << "start" <<endl;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

		}
	}

	for (int i = 1; i <= K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(info(a - 1, b - 1, c - 1));
		map2[a - 1][b - 1].push_back(i);

	}

	//cout << "input end" << endl;

	while (1) {
		//말 이동
		/*cout << endl;
		cout << "=========================" << endl;
		cout << "말 갯수: "<<v.size()<<endl;*/
		bool over = false;
		for (int i = 0; i < v.size(); i++) {
			
			vector<pair<int,int>> tmp; //움직일 말들
			int x = v[i].x;
			int y = v[i].y;
			int dir = v[i].dir;

			//cout << x <<" , "<<y<<" , " << dir << "-- " <<map2[x][y].size() <<endl;
			/*if(i==4)
				cout << x <<", " << y <<endl;*/

			//위에 말 있는지 찾기
			int mSize = map2[x][y].size();

			if (mSize > 1) {
				int num = numChk(x,y,mSize,i+1);
				//cout << "num" << " 번째" << endl;


				if (num == mSize - 1) {//가장 위에 있는 경우
					map2[x][y].pop_back();
					tmp.push_back(make_pair(0,i + 1));
				}
				else {

					for (int n = num; n < mSize; n++) {

						tmp.push_back(make_pair(n-num,map2[x][y][n]));
					}

					int p = mSize - num;

					while(p!=0){
						map2[x][y].pop_back();
						p--;
					}

				}

			}
			else {
				//1이면 그 칸에, 그 말만 있는 경우
				map2[x][y].pop_back();
				tmp.push_back(make_pair(0,i + 1));
				//cout << "only one"<<endl;
			}

			bool stop = false;
			int nx = x +dx[dir];
			int ny = y +dy[dir];
			//v[i].x = nx;
			//v[i].y = ny;

			if(nx <0 ||nx>=N || ny<0 ||ny >=N ||map[nx][ny] ==2){ //벗어나거나 파란색
				//cout << "this is blue" << endl;

				if(dir == 0) dir=1;
				else if(dir==1) dir=0;
				else if(dir==2) dir=3;
				else if(dir==3) dir=2;

				nx = x + dx[dir];
				ny = y + dy[dir];

				//v[i].x = nx;
				//v[i].y = ny;
				v[i].dir = dir;

				if(nx <0 ||nx>=N || ny<0 ||ny >=N ||map[nx][ny] ==2){
					//v[i].x = x;
					//v[i].y = y;
					stop = true;
					//cout << "blue again" << endl;
				}

				if (stop == true) {
					for (int t = 0; t < tmp.size(); t++) {
						map2[x][y].push_back(tmp[t].second);

					}
				}
				

			}

			if(stop == false){ 
			
				if(map[nx][ny] ==0){ //흰색
					//cout << "this is white : "<< nx << ", " << ny << endl;
					for(int t=0;t<tmp.size();t++){
						map2[nx][ny].push_back(tmp[t].second);
						v[tmp[t].second-1].x = nx;
						v[tmp[t].second-1].y = ny;
					}

				}else if(map[nx][ny] ==1){ //빨간색
					//cout << "this is red : " << nx << ", "<< ny<<endl;
					sort(tmp.begin(),tmp.end(),compare);

					for(int t=0;t<tmp.size();t++){
						map2[nx][ny].push_back(tmp[t].second);
						v[tmp[t].second-1].x = nx;
						v[tmp[t].second-1].y = ny;
					}

				}
			}

			//print();
			//4개 이상 쌓인게 있는지 확인
			for(int a=0;a<N;a++){
				for(int b=0;b<N;b++){
					if(map2[a][b].size() >=4){
						//cout<< a << " , "<< b << " check --- "<< map2[a][b].size() << endl;
						for(int z=0;z<map2[a][b].size();z++){
							//cout<< " * " << map2[a][b][z] << " ";
						}

						//cout << endl;
						over = true;
						break;
					}
					else {
						//cout << a << " , " << b <<"uncheck ---- "<< map2[a][b].size() << endl;
					}
				}
			}

			//cout << "over: "<<over<<endl;
			if(over == true) break;

			
		}



		if(over == true) break;


		ans++;
		if (ans > 1000) break;
	}

	//cout << "hi" <<endl;

	if (ans > 1000) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	
}
