#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 210000000
using namespace std;
int N, E, v1, v2, d[801];
priority_queue<pair<int, int> > pq;
vector<pair<int, int> > a[801];
void dijkstra(int start) {
    int cur, dist, next, nextDist;
    d[start] = 0;
    pq.push(make_pair(start, 0));

    while(!pq.empty()) {
        cur = pq.top().first;
        dist = -pq.top().second;
        pq.pop();

        if(d[cur] < dist) continue; // 최단거리 아닐경우 skip
        for(int i=0; i<a[cur].size(); i++) {
            next = a[cur][i].first; // 인접 노드
            nextDist = dist + a[cur][i].second; // 거쳐가는 비용
            if(nextDist < d[next]) { // 거쳐가는게 더 작으면 교체
                d[next] = nextDist;
                pq.push(make_pair(next, -nextDist));
            }
        }
    }
}
int main(void) {
    int s, e, c;
    cin >> N >> E;
    for(int i=0; i<E; i++) {
        cin >> s >> e >> c;
        a[s].push_back(make_pair(e, c));
        a[e].push_back(make_pair(s, c));
    }
    cin >> v1 >> v2; // 반드시 거쳐야 하는 정점
    for(int i=0; i<=N; i++) d[i] = INF; // 거리 무한

    // 1 -> v1 -> v2 -> N
    dijkstra(1);
    long long v1Tov2 = d[v1]; // v1 까지
    long long v2Tov1 = d[v2]; // v2 까지

    pq = priority_queue<pair<int, int> >();
    for(int i=0; i<=N; i++) d[i] = INF; // 거리 무한
    dijkstra(v1); // v1 -> N
    v1Tov2 += d[v2];

    pq = priority_queue<pair<int, int> >();
    for(int i=0; i<=N; i++) d[i] = INF; // 거리 무한
    dijkstra(v2); // v2 -> N
    v1Tov2 += d[N];
    
    // 1 -> v2 -> v1 -> N
    pq = priority_queue<pair<int, int> >();
    for(int i=0; i<=N; i++) d[i] = INF; // 거리 무한
    dijkstra(v2); // v2 -> v1
    v2Tov1 += d[v1];

    pq = priority_queue<pair<int, int> >();
    for(int i=0; i<=N; i++) d[i] = INF; // 거리 무한
    dijkstra(v1); // v1 -> N
    v2Tov1 += d[N];
    
    long long res = min(v1Tov2, v2Tov1);
    if(res >= INF) res = -1;
    cout << res << "\n"; // 최소값 출력
    return 0;
}