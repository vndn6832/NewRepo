#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int zero = 0;
    int start = 0;
    int same = 0;
    for(int i=0;i<lottos.size();i++){
        if(lottos[i] == 0){
            zero++;
            continue;
        }
        
        
        for(int j=start;j<win_nums.size();j++){
            if(lottos[i] == win_nums[j] ){
                same++;
                break;
            }
        }
            
    }
    

    
    if(same+zero == 1 || same+zero == 0)
        answer.push_back(6);
    else
        answer.push_back(7-(same+zero));
    
    if(same == 1 || same == 0)
        answer.push_back(6);
    else
        answer.push_back(7-same);
    
    
    
    
    return answer;
}