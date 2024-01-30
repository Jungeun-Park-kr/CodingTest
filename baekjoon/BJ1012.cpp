#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N, M, K, X, Y, T;
bool map[51][51], visited[51][51];
void bfs(int y, int x) {
	queue<pair<int, int>> q; int tmpY, tmpX, newY, newX, dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		tmpX = q.front().first; tmpY = q.front().second; q.pop();
		for (int i = 0; i < 4; ++i) {
			newY = tmpY + dy[i]; newX = tmpX + dx[i];
			if (newY < N && newY > -1 && newX < M && newX > -1 && !visited[newX][newY] && map[newX][newY]) {
				visited[newX][newY] = true;
				q.push({ newX, newY });
			}
		}
	}
}
int main(void) {
	int tmpY, tmpX, cnt=0;
	cin >> T;
	for (int test_case = 0; test_case < T; ++test_case, cnt = 0) {
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

		cin >> M >> N >> K; // 가로, 세로, 배추 위치 개수

		for (int i = 0; i < K; ++i) {
			cin >> tmpX >> tmpY;
			map[tmpX][tmpY] = true;
		}

		for (int i = 0; i < N; ++i) { // y
			for (int j = 0; j < M; ++j) { // x
				if (map[j][i] && !visited[j][i]) {
					//cout << "방문: x:" << j << ", y:" << i << endl;
					bfs(i, j);
					++cnt;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}
