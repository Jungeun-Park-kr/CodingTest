#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, map[1001][1001], res = 999999999, visited_j[1001][1001];
bool visited_f[1001][1001];
queue<pair<int,int> > fire; pair<int,int> jihoon;
bool isEscape(int y, int x) {
    if(y == 0 || y == N-1 || x == 0 || x == M-1) return true;
    return false;
}
void bfs(int y, int x) { // 지훈이 시작위치
    queue <pair<int, int> > q; pair<int,int> tmp;
    int new_y, new_x, dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
    q.push(make_pair(y,x));
    map[y][x] = 0; //지훈이가 지난 자리 다시 길로 만들어주기
    while(!q.empty()) {
        // 불 확산
        queue<pair<int, int> > newFire;
        while(!fire.empty()) {
            tmp = fire.front(); fire.pop();
            for(int i=0; i<4; ++i) {
                new_y = dy[i]+tmp.first; new_x = dx[i]+tmp.second;
                if(new_y<0 || new_x<0 || new_y>=N || new_x>=M|| visited_f[new_y][new_x] || map[new_y][new_x]) continue;
                visited_f[new_y][new_x] = true;
                newFire.push(make_pair(new_y,new_x));
            }
        }
        fire = newFire; // 번진 불 다시 넣어주기
        // 지훈이 이동
        queue <pair<int, int> > newQ; 
        while(!q.empty()) {
            tmp = q.front(); q.pop();
            // 종료조건 : 탈출 위치인지 확인
            if(isEscape(tmp.first, tmp.second)) {
                if(visited_j[tmp.first][tmp.second] < res) {
                    res = visited_j[tmp.first][tmp.second];
                }
                return;
            }
            // 지훈이 이동
            for(int i=0; i<4; ++i) {
                new_y = dy[i]+tmp.first; new_x = dx[i]+tmp.second;
                if(new_y < 0 || new_x < 0 || new_y >= N || new_x >= M|| visited_j[new_y][new_x]) continue;
                if(map[new_y][new_x] == 0 && !visited_f[new_y][new_x]) {
                    visited_j[new_y][new_x] = visited_j[tmp.first][tmp.second] + 1;
                    newQ.push(make_pair(new_y, new_x));
                }
            }
        }
        q = newQ;
    }
}
int main(void)
{
    char tmp;
    cin >> N >> M;
    for(int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> tmp;
            switch(tmp){
            case '#':map[i][j] = 1; break; // 벽
            case '.':map[i][j] = 0; break; //길
            case 'F':map[i][j] = 2; fire.push(make_pair(i,j)); visited_f[i][j] = true; break; // 불 시작위치
            case 'J':jihoon = make_pair(i,j); map[i][j] = 3; visited_j[i][j] = true; break; // 지훈이 시작위치
            }
        }
    }
    bfs(jihoon.first, jihoon.second);
    if(res == 999999999) cout << "IMPOSSIBLE\n";
    else cout << res << "\n"; 
    return 0;
}