#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
char ch[3] = {'4','1','2'};

string solution(int n) {
    string answer = "";
    while(1){
        int temp = n%3;
        n = (n-1) / 3;
       
        answer = ch[temp] + answer;
        
        if(n==0) break;
    }
    
    //reverse(answer.begin(),answer.end());
    return answer;
}
/*
string solution(int n) { 
    string answer = ""; 
    char end[3] = {'4','1','2'}; 
    while(n>0){ 
        int r = n%3; 
        answer = end[r] + answer; 
         n = (n-1)/3; 
} cout << n; return answer; }

*/