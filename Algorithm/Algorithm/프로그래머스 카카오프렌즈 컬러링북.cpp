#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

vector<int> solution(int m, int n, vector<vector<int> > picture) {
    bool check[100][100]= {false,};
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
   
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j] !=0 && check[i][j] != true){
                number_of_area++;
                
                queue<pair<int,int> > q;
                q.push({i,j});
                check[i][j] = true;
                int cnt = 1;
    
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
        
                    for(int i=0;i<4;i++){
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        
                        if(nx<0 || nx >=m || ny <0 || ny >= n) continue;
                        if(picture[nx][ny] == picture[x][y] && check[nx][ny] != true){
                
                            check[nx][ny] = true;
                            q.push({nx,ny});
                        cnt++;
                        }
                    }
                }
    
                if(cnt> max_size_of_one_area)
                    max_size_of_one_area = cnt;
            }
        }
    }
    
    
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
} 