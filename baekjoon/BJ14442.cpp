#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <cstdio>
using namespace std;
int visited[1001][1001][11], map[1001][1001];
int N, M, K, res = -1;
void bfs(int start_y, int start_x) {
    queue< tuple <int,int,int> > q; // (y, x, k, c)
    tuple<int, int, int> tmp; int y, x, new_y, new_x, dy[4]={0,0,1,-1}, dx[4]={1,-1,0,0}, cur_k = 0;
    q.push(make_tuple(start_y,start_x,0));
    visited[start_y][start_x][0] = true;
    while(!q.empty()) {
        tie (y,x,cur_k) = q.front(); q.pop();
        if(y==N-1 && x==M-1) {
            res = visited[y][x][cur_k];
            return;
        }
        for(int i=0; i<4; ++i) {
            new_y = y+dy[i]; new_x = x+dx[i];
            if(new_y >= N || new_x >= M || new_y < 0 || new_x < 0) continue;
            
            if (map[new_y][new_x] == 0 && visited[new_y][new_x][cur_k] == 0) { // 0이면 가면 됨
                visited[new_y][new_x][cur_k] = visited[y][x][cur_k] + 1;
                q.push(make_tuple(new_y, new_x, cur_k));
            } 
            else if(map[new_y][new_x]==1 && cur_k < K && visited[new_y][new_x][cur_k+1]==0) { // 벽(1)이면 아직 K만큼 덜 부쉈고, 최소 부순 개수인지 확인
                //cout << "벽부수기: ("<<new_y<<", " <<new_x<<")\n";
                visited[new_y][new_x][cur_k+1] = visited[y][x][cur_k] + 1;
                q.push(make_tuple(new_y, new_x, cur_k+1));
            } 
        }
    }
}
int main(void) 
{
    string str;
    cin >> N >> M >> K;
    for(int i=0; i<N; ++i) {
        cin >> str;
        for (int j=0; j<M; ++j) {
            map[i][j] = str[j]-'0';
        }
    }
    bfs(0,0);
    cout << res << "\n";  
    return 0;
}