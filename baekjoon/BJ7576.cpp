#include <iostream>
#include <queue>
using namespace std;
int M, N, tomato[1000][1000];
queue<pair<int, int>> ripe;
void bfs() {
	int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 }, new_y, new_x;
	pair<int, int> tmp;
	while (!ripe.empty()) {
		tmp = ripe.front(); ripe.pop();
		for (int i = 0; i < 4; ++i) {
			new_y = tmp.first + dy[i]; new_x = tmp.second + dx[i];
			if (new_y < N && new_x < M && new_x >= 0 && new_y >= 0 && tomato[new_y][new_x] == 0) {
				tomato[new_y][new_x] = tomato[tmp.first][tmp.second]+1; // 익는 일수 더해주기
				ripe.push({ new_y, new_x });
			}
		}
	}
}
int main(void)
{
	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) ripe.push({ i,j }); // 익은 토마토 넣어두기
		}
	}
	bfs();
	int day = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (tomato[i][j] == 0) { // 토마토 모두 못익음
				cout << "-1\n";
				return 0;
			}
			if (tomato[i][j] > day) day = tomato[i][j]; // 모든 토마토가 익은 날 찾기
		}
	}
	cout << day-1 << "\n";
	return 0;
}