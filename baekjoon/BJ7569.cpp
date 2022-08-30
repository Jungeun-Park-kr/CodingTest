#include <iostream>
#include <queue>
using namespace std;
int N, M, H, tomato[100][100][100];
queue<pair<int,pair<int,int>>> ripe;
void bfs() {
    pair<int,pair<int,int>> tmp;
    int new_y, new_x, new_z, dx[6] = {0,0,0,0,-1,1}, dy[6] = {0,0,-1,1,0,0}, dz[6] = {-1,1,0,0,0,0};
    while(!ripe.empty()) {
        tmp = ripe.front(); ripe.pop();
        for(int i=0; i<6; ++i) { // 3차원 배열 위,아래,상,하,좌,우 확인
            new_z = tmp.first + dz[i]; new_y = tmp.second.first+dy[i]; new_x = tmp.second.second+dx[i];
            if(new_z < 0 || new_z >= H || new_y < 0 || new_y >= N || new_x < 0 || new_x >= M) continue; // 범위 체크
            if(tomato[new_z][new_y][new_x] == 0) { // 아직 방문 안하고 익은 토마토
                ripe.push({new_z, {new_y,new_x}});
                tomato[new_z][new_y][new_x] = tomato[tmp.first][tmp.second.first][tmp.second.second]+1; // 이전 토마토가 익은 날짜 + 1
            }

        }
    }
}
int main(void)
{
    cin >> M >> N >> H;
    for(int i=0; i<H; ++i) {
        for(int j=0; j<N; ++j) {
            for (int k=0; k<M; ++k) {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1) ripe.push({i,{j,k}});
            }
        }
    }
    bfs();
    int max = -1;
    // 결과 확인
    for(int i=0; i<H; ++i) {
        for(int j=0; j<N; ++j) {
            for (int k=0; k<M; ++k) {
                if(tomato[i][j][k] == 0) {cout<<"-1\n"; return 0;} // 모든 토마토가 익지 않음
                if(tomato[i][j][k] > max) max = tomato[i][j][k]; // 모든 토마토가 익은 날 찾기
            }
        }
    }
    cout << max-1 << "\n";
    return 0;
}