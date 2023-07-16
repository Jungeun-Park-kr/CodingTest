#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int num_trucks = truck_weights.size();
    int remain_weight = weight;
    vector<int> remains; // 남은 트럭
    vector<pair<int,int>> onload; // 다리 이동중인 트럭
    int cnt = 0; // 다리에 올라탈 트럭의 번호
    
    for(int i=0; i<num_trucks; i++) {
        remains.push_back(truck_weights[i]);
    }
    
    while(remains.size() > 0 || onload.size() > 0) {
        answer++;
        // 이미 다 건넌 트럭은 큐에서 지우기
        for(int i=0; i<onload.size(); i++) {
            if(onload[i].second >= bridge_length) {
                remain_weight += onload[i].first;
                onload.erase(onload.begin()+i);
            }
        }
        
         // 다리에 남은 무게가 있다면 남은 트럭 올리기
        if(remains.size() > 0 && (remain_weight >= truck_weights[cnt])) {
            onload.push_back({truck_weights[cnt], 0});
            remain_weight -= truck_weights[cnt]; // 다리 중량 감소
            remains.erase(remains.begin());
            cnt++;
        }
        
        // 다리 위에 있는 트럭은 한칸씩 거리 이동
        for(int i=0; i<onload.size(); i++) {
            onload[i].second++;
        }
    }
    return answer;
}
