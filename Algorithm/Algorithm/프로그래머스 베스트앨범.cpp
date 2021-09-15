#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
unordered_map<string, int > map1;
//map<string, int> map2;


bool compare(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
    
}
bool compare2(pair<int,int> a, pair<int,int> b){
    
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second > b.second;
    
}
unordered_map<string, vector<pair<int,int> > > map3;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++){
        map1[genres[i]] += plays[i];
        map3[genres[i]].push_back(make_pair(i,plays[i]));
    }
     
    
    vector<pair<string,int> > v;
    v.assign(map1.begin(), map1.end());
    

    
    sort(v.begin(),v.end(),compare);
    
    for(int i=0;i<v.size();i++){
        //cout << map3[v[i].gen].size() << endl;
        vector<pair<int,int> > tmp;
        
        tmp.assign(map3[v[i].first].begin(),map3[v[i].first].end());
        sort(tmp.begin(),tmp.end(), compare2);
        
        for(int k=0;k<tmp.size() && k<2;k++){
            answer.push_back(tmp[k].first);
        }
    }

    
    return answer;
}

int main(){
    string tmp1[] = {"classic", "pop", "classic", "classic", "pop"};
    int tmp2[] = {500, 600, 150, 800, 2500 };
    vector<string> input1;
    for(int i=0;i<5;i++){
        input1.push_back(tmp1[i]);
    }
    vector<int> input2; 
    for(int i=0;i<5;i++){
        input2.push_back(tmp2[i]);
    }

    vector<int> res = solution(input1, input2);

    for(int i=0;i<res.size();i++)
        cout << res[i] << endl;
    return 0;
}