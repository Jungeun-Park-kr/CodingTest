#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000
int N, M;
using namespace std;
priority_queue <pair<int,int> > pq;
vector<pair<int, int> > a[1001]; // (도시 개수)간선 정보 담을 벡터
int d[10001]; // 최소 비용

void dijkstra(int s) {
    int cur, dist, next, nextDist;
    pq.push(make_pair(s, 0));
    d[s] = 0;
    
    while(!pq.empty()) {
        cur = pq.top().first;
        dist = -pq.top().second; // 오름차순
        pq.pop();

        if(d[cur] < dist) continue; // 최단거리 아닐경우 스킵
        for(int i=0; i<a[cur].size(); i++) { // 인접한 것중 최단거리 찾기
            next = a[cur][i].first;
            nextDist = dist + a[cur][i].second;
            if(nextDist < d[next]) { // 더 적으면 교체
                d[next] = nextDist;
                pq.push(make_pair(next, -nextDist));
            }
        }

    }
}

int main(void) {
    cin >> N >> M;
    int s, e, c;
    
    for(int i=0; i<M; i++) { // 버스 정보 (간선 경로, 가중치) 입력
        cin >> s >> e >> c;
        a[s].push_back(make_pair(e, c));
    }
    cin >> s >> e; // 출발지, 도착지 입력

    for(int i=0; i<=N; i++) d[i] = INF; // 초기 비용 무한대

    dijkstra(s);

    cout << d[e] << "\n";

}