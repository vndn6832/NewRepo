#include <string>
#include <vector>

using namespace std;

int cal(string st, int width){
    
    string tmp = "";
    int cnt =1;
        

    string a = st.substr(0,width);
        
    for(int i=width;i<st.length();i+=width){
        string b = st.substr(i,width);
        if(a==b)
            cnt++;
        else{
            if(cnt>1){
                tmp += to_string(cnt);
            }
            tmp += a;
            
            a = b;
            cnt = 1;
                
        }
            
    }
        
    if(cnt>1)
        tmp += to_string(cnt);
        
    tmp += a;
            
    

    return tmp.length();
}

int solution(string s) {
    int answer = 0;
    
    int width = 0;
    int minVal = s.length();
    while(width <= s.length()/2){
        width++;

        int val = cal(s,width);
        
        if(val < minVal)
            minVal = val;
        
    }
    
    answer = minVal;
    
    return answer;
}
