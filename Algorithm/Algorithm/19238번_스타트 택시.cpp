#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N,M, val=0;
int x,y;
int map[20][20];
bool check[20][20]={false,};
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
vector<pair<int, int> > v;
bool flag = false;
struct info{
    int x;
    int y;
    int dis;
    info(int a, int b, int c){
        x=a;
        y=b;
        dis = c;
    }
};
struct compare{
    bool operator()(info& i1, info& i2){
        if(i1.dis == i2.dis){
            if(i1.x == i2.x){
                return i1.y > i2.y;
            }

            return i1.x > i2.x;
            
        }
        return i1.dis > i2.dis;
    }
};
int move(int x,int y, int num){
    cout << "손님 데려다 주기 시작" <<endl;
    int endX = v[num].first;
    int endY=  v[num].second;

    cout << "도착지: " << endX << " ,  "<<endY<<endl;
    bool check2[20][20];
    int dist[20][20];

    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    check2[x][y] = true;
    dist[x][y] = 0;

    
    while(!q.empty()){
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        if(nowX == endX && nowY == endY){
            return dist[nowX][nowY];
        }

        for(int i=0;i<4;i++){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            
            if(nextX < 0 || nextX >=N || nextY <0 || nextY >= N ) continue;

            if(map[nextX][nextY] != -1 && check2[nextX][nextY] != true){
                check2[nextX][nextY] = true;
                dist[nextX][nextY] = dist[nowX][nowY] + 1;
                q.push(make_pair(nextX,nextY));

            }

        }


    }

    return -1;


}
void bfs(int a, int b){
    priority_queue<info,vector<info>,compare> pq;
    pq.push(info(a,b,0));
    check[a][b] = true;

    while(!pq.empty()){
        info tmp = info(0,0,0);
        tmp = pq.top();
        pq.pop();

        int x = tmp.x;
        int y = tmp.y;
        int dis = tmp.dis;
        check[x][y] = true;


        if(map[x][y] >0){
        
			int num = map[x][y];
			cout << endl;
			cout << x << " ,  "<<y<<endl;
			cout << "손님과 거리: " << dis << endl;
            val -= dis;
            

            if(val <= 0){ //손님 데릴러 가는 도중에 연료 소진
                val = -1;
                cout << "out1" <<endl;
                
                break;
            }
             
            int m = move(x,y,num);
            cout<< "데려다 주는데 드는 연료: " << m <<endl;
            if( m == -1){ //도착지에 갈 수 없을때 
                val = -1;
                cout << "out2" <<endl;
                break;
            }    
            val -= m;
            if(val<0){  //손님 데려다 주는 도중에 연료 소진
                val = -1;
                cout << "out3" <<endl;
                break;
            }
			map[x][y] = 0;
            x= v[num].first; 
            y= v[num].second;
            cout << "택시 위치: " <<x<<" , "<<y<<endl;
           
			flag = true;
            val += 2 * m;

            cout << "데려다 준 뒤 총 연료: " << val << endl;
            dis = 0;
            memset(check,false,sizeof(check));

            while(!pq.empty()){
                pq.pop();
            }

            M--;
            if(M==0) break;

        }

        /*
        if(flag == false){
            cout << "hey" <<endl;
            val = -1;
            break;
        }
        */

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=N|| ny<0 ||ny>=N) continue;
            if(map[nx][ny] != -1 && check[nx][ny] == false){
                check[nx][ny] = true;
                pq.push(info(nx,ny,dis+1));

            }
        }

    }

}
int main(){
    cin >> N>>M >> val;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 1) //벽
                map[i][j] = -1;
        }
    }

    for(int i=0;i<M+1;i++){
        v.push_back(make_pair(0,0));
    }

    cin >> x >> y;

    for(int i=1;i<=M;i++){
        int a, b,c,d;
        cin >>a>>b>>c>>d;
        map[a-1][b-1] = i; //승객 번호
        v[i].first = c-1;
        v[i].second = d-1;
    }

	for (int i = 1; i <= M; i++)
		cout << v[i].first << "---- " << v[i].second << endl;


    cout << "input done" << endl;

    bfs(x-1,y-1);

	if (flag == false) {
		cout << -1 << endl;
	}
	else {
		cout << val << endl;
	}
} 