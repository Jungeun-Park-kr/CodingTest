#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
int map[20][20], visited[20][20], N, feed_cnt, sec;
pair<int,pair<int,int>> shark = {2, {-1,-1}}; // {상어무게, {상어 y좌표, 상어 x좌표}}
vector <pair<int, int>> fish;
struct cmp {
    bool operator()(pair<int, int> &pq1, pair<int, int> &pq2) {
        if (visited[pq1.first][pq1.second] > visited[pq2.first][pq2.second]) return true; //거리 순
        else if (visited[pq1.first][pq1.second] ==  visited[pq2.first][pq2.second]) {
            if (pq1.first > pq2.first) return true; // 위쪽 먼저
            else if (pq1.second == pq2.second) return pq1.second > pq2.second; // 왼쪽 먼저
            else return false;
        }
        else return false;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
void bfs(int y, int x) {
    pair<int, int> tmp;
    queue<pair<int, int>> q;
    int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 }, new_y, new_x; // 상, 왼, 하, 우 순서
    q.push({y,x});
    map[y][x] = 0; // 현재 상어의 위치 => 0
    int repeat = 10;
    while (!q.empty()) { // 현재 상어의 위치, 크기에서 잡아먹을 수 있는 물고기들을 모두 pq에 담기, 지나갈 수 있는 좌표는 q에 담기
        tmp = q.front(); q.pop();
        //cout << "현재 상어 위치: ("<< tmp.first<<","<<tmp.second <<") : ";
        for (int i = 0; i < 4; ++i) {
            new_y = tmp.first + dy[i]; new_x = tmp.second + dx[i];
            if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= N) continue;
            if (visited[new_y][new_x] == 0 && map[new_y][new_x] <= shark.first) { // 지나갈 수 있는 범위
                //cout << "-> (" << new_y << ","<<new_y <<")";
                q.push(make_pair(new_y, new_x)); // 지나 갈 수 있는 물고기 q에 담기
                visited[new_y][new_x] = visited[tmp.first][tmp.second]+1; // 거리(시간) 증가
                if (map[new_y][new_x] != 0 && map[new_y][new_x] < shark.first) pq.push({ new_y,new_x }); // 먹을 수 있는 물고기 pq에 담기    //fish.push_back({ new_y, new_x }); // 먹을 수 있는 물고기 담기
            }
        }
    }
    //cout << endl;
}
void check() { // 먹을 수 있는 물고기가 있을 때 까지 bfs 탐색
    pair<int, int> tmp;
    int repeat = 3;
    while (true) {
        pq = priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> (); // pq 초기화
        memset(visited, 0, sizeof(visited)); // visited, queue 초기화
        bfs(shark.second.first, shark.second.second);

        if (pq.size() == 0) { // 더이상 잡아먹을 수 있는 물고기 없음
            return;
        } else if (pq.size() >= 1) { // 잡아먹을 수 있는 물고기가 1마리 이상
            tmp = pq.top(); pq.pop();
            //cout << "(" << tmp.first<< ","<<tmp.second<<") "<< map[tmp.first][tmp.second]<<"크기 물고기 먹기, 상어크기: "<<shark.first<<"\n";
            map[tmp.first][tmp.second] = 0; // 잡아먹으면 0으로 변경
            shark.second.first = tmp.first; shark.second.second = tmp.second; // 잡아먹은 위치로 상어의 위치 갱신
            //cout << visited[tmp.first][tmp.second]<<"초 걸림, 누적 시간: ";
            feed_cnt++;
            if (feed_cnt == shark.first) { feed_cnt = 0; ++shark.first; } // 무게만큼 물고기 먹으면 무게 1 증가, 물고기 개수 초기화
            sec += visited[tmp.first][tmp.second]; // 물고기 먹는데 소요시간 더하기
            //cout << sec << endl;
        }
    }
}
int main(void)
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark.second.first = i; shark.second.second = j;
            }
        }
    }
    check();
    cout << sec << "\n";
    return 0;
}