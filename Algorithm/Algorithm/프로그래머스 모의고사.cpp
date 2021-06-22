#include <string>
#include <vector>
using namespace std;
int maxVal = 0;
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1 ={1,2,3,4,5};
    vector<int> p2 ={2,1,2,3,2,4,2,5};
    vector<int> p3 ={3,3,1,1,2,2,4,4,5,5};
    vector<int> score = {0,0,0}; //벡터 초기화
    for(int i=0;i<answers.size();i++){
        if(p1[i%5] == answers[i]){
            score[0] +=1;
            if(score[0] > maxVal) maxVal = score[0];
        }
        
        if(p2[i%8] == answers[i]){
            score[1] +=1;
            if(score[1] > maxVal) maxVal = score[1];
        }
        
        if(p3[i%10] == answers[i]){
            score[2] +=1;
            if(score[2] > maxVal) maxVal = score[2];
        }
    }
    
    for(int i=0;i<score.size();i++){
        if(score[i] == maxVal){
            answer.push_back(i+1);
        }
    }
    return answer;
}