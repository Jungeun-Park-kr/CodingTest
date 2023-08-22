#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N, K, S, X, Y;
int map[201][201], dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
priority_queue <pair<int, pair<int,int> > > pq;
priority_queue <pair<int, pair<int,int> > > tmpq;
bool visited[201][201];

void bfs() {
    int cur_virus, cy, cx, ny, nx;
    memset(visited, 0, sizeof(visited));
    while(!pq.empty()) {
        cur_virus = -(pq.top().first);
        cy = pq.top().second.first;
        cx = pq.top().second.second;
        pq.pop();
        visited[cy][cx] = true;
        for(int i=0; i<4; i++) {
            ny = dy[i]+cy;
            nx = dx[i]+cx;
            if(ny <= N && nx<= N && ny >=1 && nx >= 1 && !visited[ny][nx] && map[ny][nx] == 0) {
                map[ny][nx] = cur_virus;
                tmpq.push(make_pair(-cur_virus, make_pair(ny,nx))); // 새로 전염된 바이러스, 좌표 넣기
                visited[ny][nx] = true;
            }
        }
    }
}

int main(void) {
    cin >> N >> K;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
            if(map[i][j] != 0) { // 바이러스 좌표 미리 넣어두기
                pq.push(make_pair(-map[i][j], make_pair(i,j)));
            }
        }
    }
    cin >> S >> X >> Y;
    for(int s=0; s<S; s++) {
        bfs();
        // tmpq => pq로 넣기 (다음 바이러스 위치), tmpq 초기화
        pq = tmpq;
        tmpq = priority_queue <pair<int, pair<int,int> > > ();
    }
    cout << map[X][Y] << "\n";
    return 0;
}
