#include <iostream>
#include <cstring>
using namespace std;
int N, max_height = 0;
int land[102][102];
bool visited[102][102];

void dfs(int i, int j, int height) {
    visited[i][j] = true;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int new_y, new_x;

    for(int k=0; k<4; ++k) {
        new_x = j+dx[k];
        new_y = i+dy[k];
        if(land[new_y][new_x] > height && !visited[new_y][new_x]) {
            dfs(new_y, new_x, height);
        }
    }
    return;
}
int main(void)
{
    int cnt = 0, max_cnt=0;;
    cin >> N;
    
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            cin >> land[i][j];
            if (land[i][j] > max_height)    max_height = land[i][j];
        }
    }
    for(int h=0; h<=max_height; ++h, cnt=0) { // 각 높이마다 안전지대 개수 구하기
        memset(visited, false, sizeof(visited));
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) {
                if (land[i][j] > h && !visited[i][j]) {
                    dfs(i, j, h);
                    ++cnt;
                }
            }
        }
        if(max_cnt < cnt)   max_cnt = cnt;
    }

    cout << max_cnt << "\n";

    return 0;
}