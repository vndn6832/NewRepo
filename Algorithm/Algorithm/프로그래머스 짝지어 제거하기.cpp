#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    for(int i=0; i<s.length();i++){
        if(stk.empty()){
            stk.push(s[i]);
            continue;
        }else{
            char ch = stk.top();
            
            if(ch==s[i])
                stk.pop();
            else
                stk.push(s[i]);
        }
    }
    
    if(stk.empty())
        return 1;
    else
        return 0;

}