#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int answer = 0;

    for(int i = 0; i<scoville.size(); i++){ // 힙 초기화.
        pq.push(scoville[i]);
    }

    while(!pq.empty()){
        int least = pq.top();
        pq.pop();

        if(least >= K) break; // 조건 충족. 성공.
        if(pq.empty()) { // 힙이 빈 경우. 섞어서 새로운 스코빌 지수 만들 수 없음. 실패.
            answer = -1;
            break;
        }

        int second = pq.top();
        pq.pop();

        int newScoville = least + second * 2;
        pq.push(newScoville);
        answer++;
    }

    return answer;
}