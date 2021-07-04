#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int map[101][101];
    
    int num =1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            map[i][j] = num;
            num++;
        }
    }
    
    for(int i=0;i<queries.size();i++){
        vector<int> tmp = queries[i];
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        
        int t = map[x1][y1];
        int minVal = t;
        
        for(int j=x1;j<x2;j++){
            map[j][y1] = map[j+1][y1];
            if(map[j][y1] < minVal)
                minVal = map[j][y1];
        }
        
        for(int j=y1;j<y2;j++){
            map[x2][j] = map[x2][j+1];
            if(map[x2][j] < minVal)
                minVal = map[x2][j];
        }
        
        for(int j=x2;j>x1;j--){
            map[j][y2] = map[j-1][y2];
            if(map[j][y2] < minVal)
                minVal = map[j][y2];
        }
        
        for(int j=y2; j>y1+1;j--){
            map[x1][j] = map[x1][j-1];
            if(map[x1][j] < minVal)
                minVal = map[x1][j];
        }
        
        map[x1][y1+1] = t;
        
        answer.push_back(minVal);
        
    }
    
    return answer;
}