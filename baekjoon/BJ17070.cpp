#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int map[17][17], N, cnt;
bool visited[17][17];
void dfs(int y, int x, int d) {
	if (visited[y][x] || y >= N || x >= N) return;
	if (y == N - 1 && x == N - 1) { ++cnt; return; } // 종료조건
	visited[y][x] = true;
	switch (d) {
	case 1: // 가로 (2가지)
		if (x + 1 < N && !visited[y][x + 1] && map[y][x + 1]==0) { // 오른쪽
			dfs(y, x + 1, 1);
			visited[y][x + 1] = false; // backtracking
		}
		if (y + 1 < N && x + 1 < N && !visited[y + 1][x + 1] && map[y + 1][x + 1] == 0 && map[y][x+1] == 0 && map[y+1][x] == 0) { // 45도 아래
			dfs(y + 1, x + 1, 3);
			visited[y + 1][x + 1] = false; //backtracking
		}
		break;
	case 2: // 세로 (2가지)
		if (y + 1 < N && !visited[y + 1][x] && map[y + 1][x] == 0) { // 아래
			dfs(y + 1, x, 2);
			visited[y + 1][x] = false;
		}
		if (y + 1 < N && x + 1 < N && !visited[y + 1][x + 1] && map[y + 1][x + 1] == 0 && map[y][x + 1] == 0 && map[y + 1][x] == 0) { // 45도 아래
			dfs(y + 1, x + 1, 3);
			visited[y + 1][x + 1] = false; //backtracking
		}
		break;
	case 3: // 대각선 (3가지)
		if (x + 1 < N && !visited[y][x + 1] && map[y][x + 1] == 0) { // 오른쪽
			dfs(y, x + 1, 1);
			visited[y][x + 1] = false; // backtracking
		}
		if (y + 1 < N && !visited[y + 1][x] && map[y + 1][x] == 0) { // 아래
			dfs(y + 1, x, 2);
			visited[y + 1][x] = false;
		}
		if (y + 1 < N && x + 1 < N && !visited[y + 1][x + 1] && map[y + 1][x + 1]==0 && map[y][x + 1] == 0 && map[y + 1][x] == 0) { // 45도 아래
			dfs(y + 1, x + 1, 3);
			visited[y + 1][x + 1] = false; //backtracking
		}
		break;
	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	 
	dfs(0, 1, 1); // 끝점(y, x), 방향(가로1, 세로2, 대각선 3)

	cout << cnt << "\n";
	return 0;
}