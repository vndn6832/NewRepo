#include <string>
#include <vector>
#include <iostream>
using namespace std;
string reverse(string st){
    
    if(st.size() <= 2){
        st = "";
        return st;
    }
    
    string tmp = "";
    for(int i=1;i<st.size()-1;i++){
        if(st[i] == '(')
            tmp+=')';
        else 
            tmp+= '(';
        
    }
    
    return tmp;
}
string solution(string p) {
    string answer = "";
    if(p == "")
        return p;
    else{
        bool check = true;
        int left = 0;
        int right =0;
        string u = "";
        string v = "";
        int i;
        for(i=0;i<p.size();i++){
            u+=p[i];
            if(p[i] == ')'){
                right++;
            }else{
                left++;
            }
            if(right>left) 
                check = false;
            if(left == right)
                break;
        }
        if(i != p.size()-1)
            v = &p[i+1];
        //cout << u << ", " << v<<endl;
        if(check == true){
            return u + solution(v);
        }else{
            string st = "";
            st += '(';
            st += solution(v);
            st += ')';
            st += reverse(u);
            return st;
        }
    }
}
