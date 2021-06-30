#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> num;
    vector<char> cal;
    
    string tmp = "";

    
    for(int i=0;i<expression.length();i++){
        if(expression[i]>='0' && expression[i] <='9'){
            tmp += expression[i];
        }else{
            num.push_back(stoi(tmp));
            tmp = "";
            cal.push_back(expression[i]);
        }
    }
    
    num.push_back(stoi(tmp));
    
    /*
    cout << num.size() << endl;
    cout << cal.size() << endl;
    */
    
    for(int i=0;i<num.size();i++)
        cout << num[i] << " ";
    
    cout << endl;
    
    for(int i=0;i<cal.size();i++)
        cout << cal[i] << " ";
    
    cout << endl;
    
    string prior[6] = {
      "+-*", "+*-",
      "-+*", "-*+",
      "*+-", "*-+"
    };
    
    
    for(int i=0;i<6;i++){
        vector<long long> numCpy = num;
        vector<char> calCpy = cal;
    
        for(int j=0;j<3;j++){

            for(int k=0;k<calCpy.size();k++){
                if(prior[i][j]==calCpy[k]){
                    if(calCpy[k] == '*'){
                        numCpy[k] = numCpy[k] * numCpy[k+1];
                        numCpy.erase(numCpy.begin()+k+1);
                    }else if(calCpy[k] == '+'){
                        numCpy[k] = numCpy[k] + numCpy[k+1];
                        numCpy.erase(numCpy.begin()+k+1);
                    }else if(calCpy[k]== '-'){
                        numCpy[k] = numCpy[k] - numCpy[k+1];
                        numCpy.erase(numCpy.begin()+k+1);
                    }
                    
                   // cout << calCpy[k] << ": " << numCpy[k] << endl;
                    
                    calCpy.erase(calCpy.begin()+k);
                    k--;
                    
                }
                
               
            }
        }
       

       answer = max(answer, abs(numCpy[0]));
        
    }
    
    return answer;
}