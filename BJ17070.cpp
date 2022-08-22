#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int map[17][17], N, cnt;
bool visited[17][17];
void dfs(int y, int x, int d) {
	if (visited[y][x] || y >= N || x >= N) return;
	if (y == N - 1 && x == N - 1) { ++cnt; return; } // ��������
	visited[y][x] = true;
	switch (d) {
	case 1: // ���� (2����)
		if (x + 1 < N && !visited[y][x + 1] && map[y][x + 1]==0) { // ������
			dfs(y, x + 1, 1);
			visited[y][x + 1] = false; // backtracking
		}
		if (y + 1 < N && x + 1 < N && !visited[y + 1][x + 1] && map[y + 1][x + 1] == 0 && map[y][x+1] == 0 && map[y+1][x] == 0) { // 45�� �Ʒ�
			dfs(y + 1, x + 1, 3);
			visited[y + 1][x + 1] = false; //backtracking
		}
		break;
	case 2: // ���� (2����)
		if (y + 1 < N && !visited[y + 1][x] && map[y + 1][x] == 0) { // �Ʒ�
			dfs(y + 1, x, 2);
			visited[y + 1][x] = false;
		}
		if (y + 1 < N && x + 1 < N && !visited[y + 1][x + 1] && map[y + 1][x + 1] == 0 && map[y][x + 1] == 0 && map[y + 1][x] == 0) { // 45�� �Ʒ�
			dfs(y + 1, x + 1, 3);
			visited[y + 1][x + 1] = false; //backtracking
		}
		break;
	case 3: // �밢�� (3����)
		if (x + 1 < N && !visited[y][x + 1] && map[y][x + 1] == 0) { // ������
			dfs(y, x + 1, 1);
			visited[y][x + 1] = false; // backtracking
		}
		if (y + 1 < N && !visited[y + 1][x] && map[y + 1][x] == 0) { // �Ʒ�
			dfs(y + 1, x, 2);
			visited[y + 1][x] = false;
		}
		if (y + 1 < N && x + 1 < N && !visited[y + 1][x + 1] && map[y + 1][x + 1]==0 && map[y][x + 1] == 0 && map[y + 1][x] == 0) { // 45�� �Ʒ�
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
	 
	dfs(0, 1, 1); // ����(y, x), ����(����1, ����2, �밢�� 3)

	cout << cnt << "\n";
	return 0;
}