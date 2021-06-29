#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    int dist[100][100] = {0,};
    
    queue<pair<int,int> > q;
    q.push({0,0});
    
    int n = maps.size();
    int m = maps[0].size();
    
    bool flag = true;
    
    dist[0][0] =1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny] == 0 && maps[nx][ny] == 1){
           
                dist[nx][ny] = dist[x][y] +1;
               // cout << dist[nx][ny] << endl;
                if(nx==n-1 && ny ==m-1){ //⭐⭐⭐
                    flag = false; 
                    break;
                } 
                q.push({nx,ny});
                
                
            }
        }
        if(flag == false) break; //⭐⭐⭐
        
    }
    
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    if(flag == true)
        answer = -1;
    else
        answer = dist[n-1][m-1];
  
    
    return answer;
}