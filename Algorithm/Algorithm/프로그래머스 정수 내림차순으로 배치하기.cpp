#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<char> v;
    /*
    vector<int> v;
    while(n){
        v.push_back(n%10);
        n = n/10;
    }
    sort(v.begin(),v.end());
    int pos =1;
    for(int i=0;i<v.size();i++){
        answer += v[i] * pos;
        pos *=10;
    }
    */
    string st = to_string(n);
    for(int i=0;i<st.size();i++){
        v.push_back(st[i]);
    }
    sort(v.rbegin(),v.rend());
    string st2 ="";
    for(int i=0;i<v.size();i++){
        st2+=v[i];
    }
    answer = stoll(st2);
    return answer;
}