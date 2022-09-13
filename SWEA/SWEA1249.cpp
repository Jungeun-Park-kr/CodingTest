#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#define MAX 9999999
using namespace std;
int map[101][101], N, dist[101][101];
bool visited[101][101];
void dijkstra(int y, int x) {
    queue<pair<int,int> > q; pair<int,int> tmp; int d;
    int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0}, new_y, new_x;
    dist[0][0] = 0; // 시작 지점의 비용: 0
    q.push(make_pair(0,0)); // 시작 지점 기준으로 연결 된 곳의 비용을 넣고 큐에 넣기
    while(!q.empty()) {
        tmp = q.front(); q.pop();
        
        for(int i=0; i<4; ++i) { // 연결된 곳과 인접한 칸 중에서 더 비용한 저렴 있으면 갱신하고 큐에 넣기
            new_y = dy[i] + tmp.first; new_x = dx[i] + tmp.second;
            if(new_y >= N || new_x >= N || new_y < 0 || new_x < 0) continue; // 범위 체크
            d = dist[tmp.first][tmp.second]+map[new_y][new_x];
            if(!visited[new_y][new_x] || visited[new_y][new_x] && d < dist[new_y][new_x]) { // 방문 안했거나 방문 해도 가중치 더 작은경우 확인
                visited[new_y][new_x] = true;
                dist[new_y][new_x] = d;
                q.push(make_pair(new_y, new_x));
            }
        }
    }
}
int main(void)
{
    int test_case, T;
    string str;
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case) {
        memset(visited, 0, sizeof(visited));
        cin >> N;
        for(int i=0; i<N; ++i) {
            cin >> str;
            for (int j=0; j<N; ++j) {
                map[i][j] = str[j]-'0';
                dist[i][j] = MAX;
            }
        }
        dijkstra(0,0);
        cout << "#" << test_case << "  " << dist[N-1][N-1] << "\n";
    }
    return 0;
}